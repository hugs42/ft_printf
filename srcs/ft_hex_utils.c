/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:14:40 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/19 13:06:57 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int				ft_hex_conv_ifzero(t_flags2 *f2)
{
	if (f2->is_prec == 1 && f2->prec < 1 && f2->width == 0)
		return (0);
	if (f2->is_prec == 1 && f2->prec < 1)
	{
		ft_putchar_fd(' ', FD);
		f2->nb_char++;
		return (0);
	}
	ft_putchar_fd('0', FD);
	f2->nb_char += 1;
	return (0);
}

unsigned int	ft_hex_len(int nbr)
{
	unsigned int i;

	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = ft_abs(nbr);
	i = 0;
	while (nbr)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int				ft_add_zero_hex(int nbr, int size, t_flags2 *f2)
{
	int		nb_char;

	nb_char = 0;
	if (f2->prec > size)
	{
		f2->tmp = f2->prec;
		if (nbr < 0 && f2->minus == 1)
			f2->tmp -= 8 - size;
		while (f2->tmp-- > size)
		{
			ft_putchar_fd('0', FD);
			f2->nb_char++;
		}
	}
	return (nb_char);
}

void			ft_is_minus_hex(int size, t_flags2 *f2)
{
	if (f2->tmp2 < 0)
		size = 8;
	f2->tmp = size;
	if (f2->prec > size)
		f2->tmp += f2->prec - size;
	if ((f2->prec > size || f2->width > f2->len_nbr) && f2->zero == 1)
		f2->space = ' ';
	if (f2->tmp2 < 0)
	{
		if (f2->is_prec == 0)
			f2->tmp += 8 - size;
		size += 8 - size;
	}
	f2->nb_char += ft_putwidth(f2->space, f2->tmp, f2);
	if (f2->prec > size && f2->minus == 0)
	{
		f2->tmp = f2->prec;
		while (f2->tmp-- > size)
		{
			ft_putchar_fd('0', FD);
			f2->nb_char++;
		}
	}
}

void			ft_no_minus_hex(int size, t_flags2 *f2)
{
	f2->tmp = size;
	if (f2->prec > size)
		f2->tmp += f2->prec - size;
	if (f2->zero == 1 && f2->wildcard < 0)
		f2->space = '0';
	else if ((f2->prec > size && f2->zero == 1) || (f2->zero == 1 &&
				f2->is_prec != 0))
		f2->space = ' ';
	if (f2->tmp2 < 0)
	{
		if (f2->is_prec == 0)
			f2->tmp += 8 - size;
		size += 8 - size;
	}
	f2->nb_char += ft_putwidth(f2->space, f2->tmp, f2);
	if (f2->prec > size)
	{
		f2->tmp = f2->prec;
		while (f2->tmp-- > size)
		{
			ft_putchar_fd('0', FD);
			f2->nb_char++;
		}
	}
}
