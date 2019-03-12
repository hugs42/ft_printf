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

int		ft_printf_long_double(const char *format,va_list arg, t_flags *flags)
{
	long double nbr;
	int tmp;

 	nbr = va_arg(arg, long double);
	tmp = nbr;
	ft_putnbr(tmp);
	nbr = (nbr - tmp) * 1000000 + 0.5;
	ft_putchar('.');
	tmp = nbr;
	ft_putnbr(tmp);
	return (SUCCESS);
}
#include <stdio.h>
int				ft_printf_double(const char *format,va_list arg, t_flags *flags)
{
	double nbr;
	char c = ' ';
	int tmp;
	int len_nbr;
	int len_nbr_total;
	int test = 12345;
	double tet = 345.22;
	char *rrr[32];
	nbr = va_arg(arg, double);
	len_nbr = ft_str_len(nbr);
	int len_nbr2;
	char *nbr_tmp1;
	int li;
	char *nbr_tmp2;
	char dot[2]= ".";
	char *nbr_tmp_final;
	char *nbr_tmp_final2;
//	printf("%d", len_nbr);
	tmp = nbr;
	nbr_tmp1 = ft_itoa(tmp);
	nbr = (nbr - tmp) * 1000000 + 0.5;
	tmp = nbr;
	len_nbr2 = ft_str_len(tmp);
	nbr_tmp_final = ft_strjoin(nbr_tmp1, dot);
	nbr_tmp2 = ft_itoa(tmp);
	nbr_tmp_final2 = ft_strjoin(nbr_tmp_final, nbr_tmp2);
	if (flags->zero == 1)
		c = '0';
	if (flags->precision == 0)
		if ((flags->width > ft_strlen(nbr_tmp_final2)) && (flags-> minus == 0))
			ft_putwidth(c,  ft_strlen(nbr_tmp_final2), flags);
//	if (flags->zero == 1)
//		c = '0';
	if (flags->precision == 1)
	{
		if (flags-> width > ft_strlen(nbr_tmp1) && flags->minus == 0)
			ft_putwidth(c, ft_strlen(nbr_tmp1), flags);
//		if (flags->plus == 1)
//			ft_putchar('+');
		ft_putstr(nbr_tmp1);
		if (flags-> width > ft_strlen(nbr_tmp1) && flags->minus == 1)
			ft_putwidth(' ', ft_strlen(nbr_tmp1), flags);
	}
	else if ((flags->precision > 1) && (flags->precision < ft_strlen(nbr_tmp_final2)))
	{
		if ((flags->precision > 1) && (flags-> minus == 0))
			ft_putwidth(c,  (ft_strlen(nbr_tmp2) - flags->precision + 1), flags);
//		if (flags->plus == 1)
//			ft_putchar('+');
		ft_putstr(nbr_tmp_final);
		li = ft_putnstr(nbr_tmp2, flags->precision - 1);
		if (flags-> width > ft_strlen(nbr_tmp_final) + li && flags->minus == 1)
			ft_putwidth(' ', ft_strlen(nbr_tmp_final) + li, flags);
	}
	else
		ft_putstr(nbr_tmp_final2);
	if ((flags->width > ft_strlen(nbr_tmp_final2)) && (flags-> minus == 1) && flags->precision < 1)
		ft_putwidth(' ', ft_strlen(nbr_tmp_final2), flags);
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
//	if (flags->minus == 1 && flags->plus == 1)
//		ft_putchar('+');
	if (flags->minus == 1 && flags->zero == 1)
		c = ' ';
	if (flags->space == 1 && flags->plus == 1)
		flags->space = 9;
	if ((width > len_nbr) && ( minus == 0))
		ft_putwidth(c, len_nbr, flags);
//		if ((flags->plus == 1) && (i >= 0) && (flags->zero == 1))
/*			ft_putchar('+');
		if ((flags->space == 1) && (flags->zero == 1))
		{
			ft_putchar(' ');
			len_nbr++;
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
	if ((flags->space == 1) && (flags->zero == 0))
	{
		ft_putchar(' ');
		len_nbr++;
	}*/
//		if ((flags->plus == 1) && (i >= 0))
//			ft_putchar('+');
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

