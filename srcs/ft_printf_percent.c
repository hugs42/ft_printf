/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:05:55 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/13 19:15:24 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int		ft_add_blank(int nb)
{
	int nb_char;

	nb_char = 0;
	while (nb > 0)
	{
		ft_putchar_fd(' ', FD);
		nb--;
		nb_char++;
	}
	return (nb_char);
}

int		ft_add_zero(int nb)
{
	int nb_char;

	nb_char = 0;
	while (nb > 0)
	{
		ft_putchar_fd('0', FD);
		nb--;
		nb_char++;
	}
	return (nb_char);
}

int		ft_printf_percent(va_list *list, t_flags2 *f2)
{
	int		i;

	i = 0;
	(void)list;
	if (f2->width != 0 && f2->minus == 0)
	{
		i = f2->width - 1;
		if (f2->zero != 0)
			f2->nb_char += ft_add_zero(i);
		else
			f2->nb_char += ft_add_blank(i);
		ft_putchar_fd('%', FD);
	}
	else if (f2->width != 0 && f2->minus == 1)
	{
		i = f2->width - 1;
		ft_putchar_fd('%', FD);
		f2->nb_char += ft_add_blank(i);
	}
	else
	{
		ft_putchar_fd('%', FD);
	}
	f2->nb_char += 1;
	return (0);
}
