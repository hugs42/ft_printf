/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:38:18 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/13 15:46:22 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

void	ft_putnbr_printf2(int nb, t_flags2 *f2)
{
	if (f2->zero == 1 && f2->prec < 0 && f2->minus_tmp == 0 && f2->is_n)
	{
		f2->tmp3 += 1;
		f2->nb_char += ft_putwidth('0', f2->tmp3, f2);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, FD);
		ft_putnbr_fd(nb % 10, FD);
	}
	else
	{
		if (nb == 0 && f2->is_prec == 1 && f2->prec == 0)
		{
			if (f2->width > 0)
				ft_putchar_fd(' ', FD);
		}
		else
			ft_putchar_fd(nb + '0', FD);
	}
}

void	ft_putnbr_printf(int nb, t_flags2 *f2)
{
	f2->tmp3 = f2->len_nbr;
	if (nb < 0)
	{
		ft_putchar_fd('-', FD);
		nb = -nb;
		f2->tmp3 -= 1;
		f2->len_nbr--;
	}
	if (f2->prec > f2->len_nbr && nb >= 0)
	{
		f2->tmp2 = f2->width;
		f2->width = f2->prec;
		f2->nb_char += ft_putwidth('0', f2->tmp3, f2);
	}
	else if (f2->zero == 1 && f2->is_n == 1 && f2->width > f2->tmp3 &&
			f2->is_prec == 0)
	{
		if (f2->wildcard >= 0 && f2->minus == 0)
		{
			f2->tmp3 += 1;
			f2->nb_char += ft_putwidth('0', f2->tmp3, f2);
		}
	}
	ft_putnbr_printf2(nb, f2);
}
