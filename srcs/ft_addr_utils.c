/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:07:47 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/19 13:24:48 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int		ft_is_minus_addr(t_flags2 *f2)
{
	int		tmp;
	int		diff;

	tmp = 0;
	diff = 0;
	tmp = f2->tmp3;
	diff = f2->prec - f2->tmp3;
	if (f2->prec > f2->tmp3)
		tmp += diff;
	if (f2->width > 0)
	{
		tmp += 2;
		if ((f2->zero == 1 && f2->is_prec != 0) || (f2->zero == 0))
			f2->nb_char += ft_putwidth(' ', tmp, f2);
	}
	return (0);
}

int		ft_no_minus_addr(t_flags2 *f2)
{
	int		tmp;
	int		diff;

	tmp = f2->tmp3;
	diff = f2->prec - f2->tmp3;
	if (f2->prec > f2->tmp3)
		tmp += diff;
	if (f2->width > 0)
	{
		tmp += 2;
		if ((f2->zero == 1 && f2->is_prec != 0) || (f2->zero == 0))
			f2->nb_char += ft_putwidth(' ', tmp, f2);
	}
	ft_putstr_fd("0x", FD);
	f2->nb_char += 2;
	if (f2->width > 0)
	{
		if ((f2->zero == 1 && f2->is_prec == 0))
			f2->nb_char += ft_putwidth('0', tmp, f2);
	}
	return (0);
}

void	ft_display_addr(int i, char *res, t_flags2 *f2)
{
	if (f2->tmp2 == 1)
		i++;
	while (i < 9)
	{
		ft_putchar_fd(res[i], FD);
		f2->nb_char++;
		i++;
	}
}
