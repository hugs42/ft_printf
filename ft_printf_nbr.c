/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:02:31 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/22 14:52:02 by hugsbord         ###   ########.fr       */
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

int				ft_printf_double(const char *format,va_list arg, t_flags *flags)
{
	double nbr;
	char c = ' ';
	int tmp;
	int len_nbr;
//	int len_nbr_total;
//	int test = 12345;
//	double tet = 345.22;
//	char *rrr[32];
	nbr = va_arg(arg, double);
	len_nbr = ft_str_len(nbr);
	flags->len = len_nbr;
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
	if (flags->zero > 0)
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
/*
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
	if (flags->zero > 0)
		c = '0';
	if ((flags->plus == 1) && (i >= 0))
	{
		len_nbr++;
		flags->space = 0;
	}
	if (i < 0)
		flags->is_negative = 1;
//	if (flags->minus == 1 && flags->plus == 1)
//		ft_putchar('+');
	if (flags->minus == 1 && flags->zero == 1)
		c = ' ';
	if ((flags->space == 1) && (flags->width == 0) && (i >= 0))
	{
		ft_putchar(' ');
		count_char++;
	}
//	else if ((flags->space == 1) && (flags->width > 0))
//		ft_putchar(' ');
	if ((flags->plus == 1) && (i >= 0) && (flags->width > len_nbr + 1) && (flags->minus == 0) && (flags->zero == 0))
		ft_putchar(' ');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->zero == 0))
		ft_putchar('+');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->zero == 1))
		ft_putchar('+');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 1) && (flags->zero == 0))
		ft_putchar('+');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 1) && (flags->zero == 1))
		ft_putchar('+');
//	else if ((flags->plus == 0) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->zero == 1))
//		ft_putchar('0');
	else if ((flags->plus == 0) && (i >= 0) && (flags->width > 0) && (flags->minus == 1) && (flags->space == 1)) //&& (flags->zero > 0))
		ft_putchar(' ');
	else if ((flags->plus == 0) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->space == 1)) //&& (flags->zero > 0))
		ft_putchar(' ');

//	count_char++;
	else
		count_char --;
	count_char++;
	len_nbr = ft_strlen(ft_itoa(i));
	if ((flags->plus == 1) && (i < 0) && (flags->width > len_nbr)  &&  (flags->zero > 0))
		ft_putchar('-');

	if (flags->minus == 0)
	{
		if ((width > len_nbr)  && (flags->precision < len_nbr))
		{
			if (flags->plus == 1)
				len_nbr--;
		count_char += ft_putwidth(c, len_nbr, flags);
		}
		else if ((width > len_nbr) && (flags->precision > len_nbr))
			count_char += ft_putwidth(c, flags->precision, flags);
	}
	if ((flags->plus == 1) && (i >= 0) && (flags->zero == 0))// && (flags->width == 0))
	{
		ft_putchar('+');
		count_char++;
	}
	len_nbr = ft_strlen(ft_itoa(i));
	prec = flags->precision;
//	printf("%d", len_nbr);
/*	if (prec > len_nbr && flags->zero != 0 && flags->zero ==0)
	{
		while (prec > len_nbr)
		{
			ft_putchar('+');
			count_char++;
			prec--;
		}
	}
	if (prec > len_nbr)
	{
		while (prec > len_nbr)
		{
			ft_putchar('0');
			count_char++;
			prec--;
		}
	}
*		
*		if ((flags->space == 1) && (flags->zero == 1))
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
	}
//		if ((flags->plus == 1) && (i >= 0))
//			ft_putchar('+');
	ft_printf_putnbr(i, flags);
	width = flags->width;
	count_char += len_nbr;
	if ((width > len_nbr) && (minus == 1))
	{
		while (width > len_nbr)
		{
			--width;
			ft_putchar(c);
			count_char++;
		}
	}
	return (count_char);
}
*/
