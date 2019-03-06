/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:42:13 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/06 18:45:05 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_octal(const char *format, va_list arg, t_flags *flags)
{
	int i;
	int nbr;
	char *res;
	char *base = "01234567";
	i = 0;
	nbr = va_arg(arg, int);
	while (nbr > 0)
	{
		res[i] = base[nbr % 8];
		nbr /= 8;
		i++;
	}
	res[i] = '\0';
	ft_putstrrev(res);
	return (SUCCESS);
}

int				ft_printf_hex(const char *format, va_list arg, char c, t_flags *flags)
{
	int i;
	int nbr;
	char res[100];
	char *base_low = "0123456789abcdef";
	char *base_upp = "0123456789ABCDEF";
	i = 0;
	nbr = va_arg(arg, int);
	if (c == 'x')
	{
		while (nbr > 0)
		{
			res[i] = base_low[nbr % 16];
			nbr /= 16;
			i++;
		}
		res[i] = '\0';
		ft_putstrrev(res);
	}
	else if (c == 'X')
	{
		while (nbr > 0)
		{
			res[i] = base_upp[nbr % 16];
			nbr /= 16;
			i++;
		}
		res[i] = '\0';
		ft_putstrrev(res);
	}
	return (SUCCESS);
}
