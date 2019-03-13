/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:02:49 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/12 19:00:33 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void sd2str_v2(char *lpszDest, double value) {
	char *pDst;
	int i, j;
	pDst = lpszDest;
	i = value;
	value -= i;
	itoa(i, pDst, 10);
	if (i < 0.0) { pDst++; value = -value; }
	pDst += length(i);
	*pDst++ = ',';
	for (j = 0; j < 17; ++j) {
		value *= 10;
		i = value;
		value -= i;
		*pDst++ = '0' + i;
	}
	*pDst = 0;
}
*/

size_t   ft_str_len(double n)
{
	int l = 0;
	int temp = 1;
	while (temp <= n)
	{
	 temp *= 10;
	 l++;
	}
	return (l);
/*		size_t		i;

		i = 1;
		while (n /= 10)
				i++;
		return (i);
*/}

char					*ft_itoa_double(int n)
{
char					*str;
		size_t                  len;
		unsigned int    n_tmp;

		len = ft_str_len(n);
	n_tmp = n;
	if (n < 0)
	{
			n_tmp = -n;
			len++;
	}
	if (!(str = ft_strnew(len)))
				return (NULL);
		str[--len] = n_tmp % 10 + '0';
		while (n_tmp /= 10)
				str[--len] = n_tmp % 10 + '0';
		if (n < 0)
				*(str + 0) = '-';
		return (str);
}

int				ft_putstrrev(char *str)
{
	int len;
	len = ft_strlen(str);
	while (len + 1 > 0)
	{
		ft_putchar(str[len]);
		len--;
	}
	return (SUCCESS);
}

int				ft_putnstr(char *str, int n)
{
	int i = 0;
	while (i <= n)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		ft_putzero_adress(char c, int len)

{
	while (len > 0)
	{
		ft_putchar('0');
		len--;
	}
	return (SUCCESS);
}

int		ft_putwidth(char c, int len, t_flags *flags)
{
	int width;
	int tmp = len;

	width = flags->width;
	if (flags->flag == 's' && flags->precision > 0)// && width <len)
		len = flags->precision;
		if (flags->flag == 's' && flags->precision > 0 && width <len)
		len = tmp;
	if ((width >= len) && (flags->minus == 0))
	{
		while (width > len + 1)
		{
			ft_putchar(c);
			width--;
		}
		if (flags->plus == 1  && flags->zero == 0 && flags->flag != 'c' && flags->flag != 'p' && flags->flag !='s')
			ft_putchar('+');
		else if ((flags->plus == 0) && (flags->space == 1))
			return (SUCCESS);
		else
			ft_putchar(c);
	}
	else if ((width >= len) && (flags->minus == 1))
	{
		while (width > len + 1)
		{
			width--;
			ft_putchar(' ');
		}
		if (flags->plus == 1 && flags->zero == 0 && flags->flag != 'c' && flags->flag != 's' && flags->flag != 'p')
			ft_putchar('+');
		else
			ft_putchar(' ');
	}
	else
		ft_putstr("PORN");
	return (SUCCESS);
}

char	*cut_left(char *str,  int n)
{
	int i;
	int len;
	char *str_cut;

	i = 0;
	len = ft_strlen(str);
	if (n >= len)
		return ("");
	str_cut = ft_strnew(len - n);
	while (n--)
		str++;
	while (*str)
		str_cut[i++] = *str++;
	return (str_cut);
}

char	*cut_right(char *str, int n)
{
	int i;
	int len;
	char *str_cut;

	i = 0;
	len = ft_strlen(str);
	if (n >= len)
		return ("");
	str_cut = ft_strnew(len - n);
	while (n--)
		str++;
	while (i < (len - n))
		str_cut[i++] = *str++;
	return (str_cut);
}

int		ft_isflag(const char *format, int i)
{
	if ((format[i] == '#') || (format[i] == '-') || (format[i] ==
						'+') || (format[i] == ' ') || (format[i] == '+') ||
							(format[i] == 'h') || (format[i]) == '0')
		return (SUCCESS);
	else
		return (FINISH);

}

int		ft_is_diouxx(const char *format, va_list arg, int i)
{
	if ((format[i] == 'd') || (format[i] == 'i') || (format[i] ==
						'o') || (format[i] == 'u') || (format[i] == 'x') ||
							(format[i] == 'X'))
		return (SUCCESS);
	else
		return (FINISH);
}

int		ft_init_flags_struct(t_flags *flags)
{
	flags->flag = '0';
	flags->sharp = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->len = 0;
	flags->len_min = 0;
	flags->precision = 0;
	flags->format = NULL;
	return (SUCCESS);
}

