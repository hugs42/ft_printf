/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:50:32 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/05 16:41:36 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_int(const char *format, va_list arg)
{
		int i;

		i = va_arg(arg, int);
		ft_putnbr(i);
		return (SUCCESS);
}

int				ft_printf_unsigned_int(const char *format, va_list arg)
{
	unsigned int i;
	char *str = NULL;

	i = va_arg(arg, unsigned int);
	str = ft_itoa(i);
	ft_putstr(str);
	return (SUCCESS);
}
