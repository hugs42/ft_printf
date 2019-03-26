/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_long_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:43:38 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/26 17:18:17 by hugsbord         ###   ########.fr       */
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
