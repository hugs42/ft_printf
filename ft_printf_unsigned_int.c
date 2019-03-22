/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:51:10 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/22 15:17:58 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_digits(long n, int count)
{
	if (n > 9)
			return (count_digits(n / 10, count + 1));
	return (count + 1);
}

char		*allocate_memory(long n)
{
	char	*str;
	int		i = 0;

	if (n < 0)
	{
		n = -n;
		str = ft_strnew(count_digits(n, 0) + 1);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		i = 1;
		while (i <= count_digits(n, 0))
			str[i++] = 'X';
	}
	else
	{
		str = ft_strnew(count_digits(n, 0));
		if (str == NULL)
			return (NULL);
		i = 0;
		 while (i < count_digits(n, 0))
			str[i++] = 'X';
	}
	return (str);
}

char		*ft_is_zero(void)
{
	char    *str;

	str = ft_strnew(1);
	if (str == NULL)
		 return (NULL);
	str[0] = '0';
	return (str);
}
char	*ft_ltoa(long n)
{
	char	*str;
	char	*iter;

	if (n == 0)
		return (ft_is_zero());
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	str = allocate_memory(n);
	if (str == NULL)
		return (NULL);
	iter = str;
	while (*iter)
		iter++;
	iter--;
	if (n < 0)
		n = -n;
	while (n)
	{
		*iter = (n % 10) + '0';
		n /= 10;
		iter--;
	}
	return (str);
}

int		ft_printf_unsigned_int(const char *format, va_list arg, t_flags *flags)
{
	unsigned int i = 0;
	int count_char = 0;
	char *str = NULL;
	char w = ' ';
	int prec_len = 0;
	int prec = flags->precision;
	int len_nbr = ft_strlen(ft_itoa(i));
	i = va_arg(arg, unsigned int);
	if (flags->zero == 1)
		w = '0';
	str = ft_ltoa(i);
	if (flags->minus == 0)
	{
		if (flags->width > ft_strlen(str))
			count_char+= ft_putwidth(w, ft_strlen(str) + flags->precision, flags);
	}
	if (prec > len_nbr)
	{
		while (prec > len_nbr + 1)
		{
			ft_putchar('0');
			count_char++;
			prec--;
		}
	}
	ft_putstr(str);
	if (flags->minus == 1)
	{
		if (flags->width > ft_strlen(str))
			count_char+= ft_putwidth(w, ft_strlen(str) + prec_len, flags);
	}
	count_char += ft_strlen(str);
	return (count_char);
}
