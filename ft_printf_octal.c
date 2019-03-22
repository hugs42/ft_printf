/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:34:33 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/22 15:14:31 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_octal(const char *format, va_list arg, t_flags *flags)
{
	int i;
	int sh = 0;
	int nbr;
	int count_char = 0;
	int prec = flags->precision;
	int prec_len = 0;
	char res[100];
	char *base = "01234567";
	char w = ' ';
	if (flags->zero == 1)
		w = '0';
	i = 0;
	if (flags->sharp == 1)
	{
		sh = 1;
		count_char+=1;
	}
	nbr = va_arg(arg, int);
	if (nbr == 0)
	{
		ft_putchar('0');
		count_char++;
	}
	while (nbr > 0)
	{
		res[i] = base[nbr % 8];
		nbr /= 8;
		i++;
		count_char++;
	}
	res[i] = '\0';
	if (flags->minus == 0)
	{
		if (flags->width > ft_strlen(res))
			count_char+= ft_putwidth(w, ft_strlen(res) +  sh + flags->precision, flags);
	}
	if (flags->sharp > 0)
		ft_putchar('0');
	if (prec > ft_strlen(res))
	{
		while (prec > ft_strlen(res))
		{
			ft_putchar('0');
			prec--;
			prec_len++;
			count_char++;
		}
	}
	ft_putstr(ft_strrev(res));
	if (flags->minus == 1)
	{
		if (flags->width > ft_strlen(res))
			count_char+= ft_putwidth(w, ft_strlen(res) +  sh + prec_len, flags);
	}
	return (count_char);
}

