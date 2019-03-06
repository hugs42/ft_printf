/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:48:28 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/06 15:32:51 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_printf_char(const char *format, va_list arg, t_flags *flags)
{
	char c;

	flags->flag = 'c';
	c = va_arg(arg, int);
	ft_putchar(c);
	return (SUCCESS);
}

int				ft_printf_str(const char *format, va_list arg, t_flags *flags)
{
	char *str;

	flags->flag = 's';
	str = va_arg(arg, char *);
	ft_putstr(str);
	return (SUCCESS);
}

int				ft_printf_addr(const char *format, va_list arg, t_flags *flags)
{
	int i;
	unsigned long addr;
	char const *base;
	char res[9];

	i = 8;
	base = "0123456789abcdef";
	flags->flag = 'p';
	addr = (unsigned long) va_arg(arg, unsigned long);
	while ((addr / 16) > 0 || i >= 8)
	{
		res[i] = base[addr % 16];
		addr /= 16;
		i--;
	}
	res[i] = base[(addr % 16)];
	ft_putchar('0');
	ft_putchar('x');
	while (i < 9)
	{
			ft_putchar(res[i]);
			i++;
	}
	return (SUCCESS);
}
