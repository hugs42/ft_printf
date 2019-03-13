/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:48:28 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/07 16:58:32 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

int		ft_printf_char(const char *format, va_list arg, t_flags *flags)
{
	char c;
	char w;

	w = ' ';
	if (flags->zero == 1)
		w = '0';
	flags->flag = 'c';
	c = va_arg(arg, int);
	if (!c)
		return (ERROR);
	if ((flags->width > 1) && (flags->minus == 0) && (flags->precision != 1))
		ft_putwidth(w, 1, flags);
	if (flags->minus == 1 && flags->width != 0)
		ft_putchar(c);
	else
		ft_putchar(c);
	if ((flags->width > 1) && (flags->minus == 1))
		ft_putwidth(w, 1, flags);
	return (SUCCESS);
}

int				ft_printf_str(const char *format, va_list arg, t_flags *flags)
{
	char *str;
	int len;
	int width;
	int i;
	int pp;
	char c;
	int l;
	l = 0;
	flags->flag = 's';
	str = va_arg(arg, char *);
	len = ft_strlen(str);
	width = flags->width;
	if (str == NULL || ft_strcmp(str, "") == 0)
		return (ERROR);
	if (flags->zero == 1)
		c = '0';
	else
		c = ' ';
	if ((width > len) && (flags->minus == 0) && (flags->precision == 0) && (flags->is_precision == 0))
	{
		ft_putwidth(c, len, flags);
	}
	if (flags->precision == 1 && flags->width == 0)
		return (SUCCESS);
//	if (flags->precision == 1 && flags->width == 0)
//		return (SUCCESS);
	else if (flags->precision >= 1 && flags->precision <= len && flags->width > len && flags->minus == 0)
		ft_putwidth(c, len - (len - flags->precision), flags);
	else if (flags->precision >= 1 && flags->precision > len && flags->width > len && flags->minus == 0)
		ft_putwidth(c, len, flags);
//printf("%d -", flags->precision);
//	if (flags->is_precision == 1 && flags->precision == 0)
//		ft_putchar(c);
//	printf("%d -", flags->width);
	if ((flags->precision >= 1) && (flags->precision < len))
		ft_putnstr(str, flags->precision - 1);
	else if (flags->is_precision == 1 && flags->precision == 0)
		while (l++ < flags->width)
			ft_putchar(c);
	else
		ft_putstr(str);
	width = flags->width;
	if (flags->precision >= 1 &&  flags->precision <= len && flags->width > len && flags->minus == 1)
		ft_putwidth('i', len - (len - flags->precision), flags);
	else if (flags->precision >= 1 && flags->precision > len && flags->width > len && flags->minus == 1)
		ft_putwidth(c, len, flags);
	if ((width > len) && (flags->minus == 1) && (flags->precision == 0))
		ft_putwidth(c, len, flags);
	return (SUCCESS);
}

int				ft_printf_addr(const char *format, va_list arg, t_flags *flags)
{
	int i;
	int len;
	unsigned long addr;
	char const *base;
	char res[9];

	int diff = 0;
	i = 8;
	base = "0123456789abcdef";
	len = flags->width;
	flags->flag = 'p';
	diff = flags->width - 11;
	addr = (unsigned long) va_arg(arg, unsigned long);
	if ((flags->width > 11) && (flags->minus == 0) && flags->zero == 0)
		ft_putwidth(' ', 11, flags);
	while ((addr / 16) > 0 || i >= 8)
	{
		res[i] = base[addr % 16];
		addr /= 16;
		i--;
	}
	res[i] = base[(addr % 16)];
	ft_putchar('0');
	ft_putchar('x');
	if (flags->zero == 1 && diff > 0 && flags->minus == 0)
		ft_putzero_adress('0', diff);
	while (i < 9)
	{
			ft_putchar(res[i]);
			i++;
	}
	if ((flags->width > 11) && (flags->minus == 1))
		ft_putwidth(' ', 11, flags);
	return (SUCCESS);
}
