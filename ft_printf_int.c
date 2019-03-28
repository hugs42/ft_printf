/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:23:40 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/28 16:08:32 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_int(const char *format, va_list arg, t_flags *flags)
{
	int i;
	int width;
	int len_nbr;
	int prec = 0;
	int zero;
	int minus;
	char c;
	int count_char = 0;

	flags->flag = 'd';
	i = va_arg(arg, int);
	width = flags->width;
	zero = flags->zero;
	minus = flags->minus;
	c = ' ';
	len_nbr = ft_strlen(ft_itoa(i));
	if (flags->zero > 0)// && (flags->width <= ft_strlen(ft_itoa(i))))
		c = '0';
	if ((flags->zero > 0) && (flags->width >= ft_strlen(ft_itoa(i))) && (flags->precision > len_nbr))
		c = ' ';
	if ((flags->plus == 1) && (i >= 0))
	{
		len_nbr++;
		flags->space = 0;
	}
	if (i < 0)
		flags->is_negative = 1;
	else
		flags->is_negative = 0;
	if (flags->minus == 1 && flags->zero == 1)
		c = ' ';
	if ((flags->space == 1) && (flags->width == 0) && (i >= 0))
	{
		ft_putchar(' ');
		count_char++;
	}
	if ((flags->plus == 1) && (i >= 0) && (flags->width > len_nbr + 1) && (flags->minus == 0) && (flags->zero == 0))
		ft_putchar(' ');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->zero == 0))
		ft_putchar('+');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->zero == 1))
		ft_putchar('+');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 1) && (flags->zero == 0) && (flags->precision < len_nbr))
		ft_putchar('+');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 1) && (flags->zero == 1))
		ft_putchar('+');
	else if ((flags->plus == 0) && (i >= 0) && (flags->width > 0) && (flags->minus == 1) && (flags->space == 1))
		ft_putchar(' ');
	else if ((flags->plus == 0) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->space == 1))
		ft_putchar(' ');
	else
		count_char --;
	count_char++;
	len_nbr = ft_strlen(ft_itoa(i));
//	if (flags->is_negative == 1)
//		len_nbr--;
	if ((i < 0) &&  (flags->zero > 0) && (flags->precision <= len_nbr))
		ft_putchar('-');
	else if ((i < 0) &&  (flags->zero == 0) && (flags->precision > len_nbr))
		ft_putchar('-');
	if (flags->minus == 0)
	{
		if ((width > len_nbr)  && (flags->precision < len_nbr))
		{
			if (flags->plus == 1) /*&& flags->width > ft_strlen(ft_itoa(i))*/
			{
				if (flags->is_negative == 1)
					len_nbr-=2;
				else if (flags->is_negative == 0)
					len_nbr-=1;
//			else if (flags->plus == 1 /*&& flags->width > ft_strlen(ft_itoa(i)) */&& flags->is_negative == 1)
//				len_nbr-=2;
//			else if (flags->plus == 1)
//				len_nbr-=5;
			}
		count_char += ft_putwidth(c, len_nbr, flags);
		}
		else if ((width > len_nbr) && (flags->precision > len_nbr))
		{
			if (i < 0)
				len_nbr--;
			count_char += ft_putwidth(c, flags->precision, flags);
		}
	}
	if ((flags->plus == 1) && (i >= 0) && (flags->zero == 0))
	{
		ft_putchar('+');
		count_char++;
	}
	len_nbr = ft_strlen(ft_itoa(i));
	prec = flags->precision;
	int prec_len = 0;
	if (prec >= len_nbr)
	{
		if ((flags->zero == 1) && (flags->precision == len_nbr + 1) && (flags->width > len_nbr))
			prec--;
		while (prec > len_nbr)
		{
			ft_putchar('0');
			count_char++;
			prec--;
			prec_len++;
		}
		if ((flags->zero == 1) || ((flags->precision > len_nbr) && flags->is_negative == 1))
		{
			ft_putchar('0');
			count_char++;
		}
	}
	if ((i == 0) && (flags->precision == 0) && (flags->is_precision == 1))
	{
		if ((i == 0) && (flags->precision == 0) && (flags->is_precision == 1) && (flags->width > len_nbr))
		{
			count_char++;
			ft_putchar(' ');
		}
		count_char -= 1;
	}
	else
		ft_printf_putnbr(i, flags, len_nbr);
	width = flags->width;
	count_char += len_nbr;
	if (minus == 1)
	{
		if ((width > len_nbr))
			count_char += ft_putwidth(c, len_nbr + prec_len, flags);
	}
	return (count_char);
}
