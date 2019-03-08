/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:02:31 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/07 18:38:10 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_double(const char *format,va_list arg, t_flags *flags)
{
	double nbr;
	int tmp;

	nbr = va_arg(arg, double);
	tmp = nbr;
	ft_putnbr(tmp);
	nbr = (nbr - tmp) * 1000000 + 0.5;
	ft_putchar('.');
	tmp = nbr;
	ft_putnbr(tmp);
	return (SUCCESS);
}

int				ft_printf_unsigned_int(const char *format, va_list arg, t_flags *flags)
{
	unsigned int i;
	char *str = NULL;

	i = va_arg(arg, unsigned int);
	str = ft_itoa(i);
	ft_putstr(str);
	return (SUCCESS);
}

int				ft_printf_int(const char *format, va_list arg, t_flags *flags)
{
	int i;
	int width;
	int len_nbr;
	int zero;
	int minus;
	char c;

	flags->flag = 'd';
	i = va_arg(arg, int);
	width = flags->width;
	zero = flags->zero;
	minus = flags->minus;
	c = ' ';
	len_nbr = ft_strlen(ft_itoa(i));
	if (flags->zero)
		c = '0';
	if ((flags->plus == 1) && (i >= 0))
		len_nbr++;
	if (flags->minus == 1 && flags->plus == 1)
		ft_putchar('+');
	if (flags->minus == 1 && flags->zero == 1)
		c = ' ';
	if (flags->space == 1 && flags->plus == 1)
		flags->space = 0;
	if (width > len_nbr && minus == 0)
	{
		if ((flags->plus == 1) && (i >= 0) && (flags->zero == 1))
		{
			ft_putchar('+');
//			len_nbr++;
		}
		while (width > len_nbr)
		{
			width--;
			ft_putchar(c);
		}
		if ((flags->plus == 1) && (i >= 0) && (flags->zero == 0))
		{
			ft_putchar('+');
			len_nbr++;
		}
	}
	if (flags->space == 1)
	{
		ft_putchar(' ');
		len_nbr++;
	}
	ft_putnbr(i);
	width = flags->width;
	if ((width > len_nbr) && (minus == 1))
	{
		while (width > len_nbr)
		{
			--width;
			ft_putchar(c);
		}
	}
	return (SUCCESS);
}

