/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:52:16 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/19 13:38:44 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

void	ft_check_addr(t_flags2 *f2)
{
	if ((int)f2->addr < 0)
		f2->is_n = 1;
	if (f2->prec < 0)
	{
		if (f2->minus_tmp == 1)
			f2->minus = 1;
		else if (f2->minus_tmp == 0 && f2->n_width == 0)
			f2->minus = 0;
		else if (f2->minus_tmp == 0 && f2->n_width == 1)
			f2->minus = 1;
	}
	if (f2->is_n == 0)
	{
		f2->tmp3 = ft_hex_len(f2->addr);
		if ((f2->addr >= 1 && f2->addr <= 16) || ((void*)f2->addr == NULL))
			f2->tmp2 = 1;
	}
	if (f2->addr == 0)
		f2->tmp = 1;
	if (f2->tmp == 1 && f2->is_prec == 1 && f2->prec == 0)
		f2->tmp3--;
}

void	ft_printf_addr2(int i, char *res, t_flags2 *f2)
{
	if (f2->prec > f2->tmp3)
	{
		while (f2->tmp3++ < f2->prec)
		{
			ft_putchar_fd('0', FD);
			f2->nb_char++;
		}
	}
	if (f2->tmp == 1)
	{
		if (f2->is_prec == 1 && f2->prec == 0)
			f2->hex_up++;
		else
		{
			ft_putchar_fd('0', FD);
			f2->nb_char += 1;
		}
	}
	else
		ft_display_addr(i, res, f2);
	if (f2->minus == 1)
		ft_is_minus_addr(f2);
}

int		ft_addr_base(int i, t_flags2 *f2)
{
	while ((f2->addr / 16) > 0 || i >= 8)
	{
		f2->hex[i] = BASE[f2->addr % 16];
		f2->addr /= 16;
		i--;
		f2->len++;
	}
	f2->hex[i] = BASE[(f2->addr % 16)];
	f2->len += 1;
	if (f2->addr != 0)
		f2->tmp3 = f2->len;
	else if (f2->addr == 0 && f2->prec > 2)
		f2->width--;
	return (i);
}

int		ft_printf_addr(va_list *arg, t_flags2 *f2)
{
	int				i;

	i = 8;
	f2->addr = (unsigned long)va_arg(*arg, void *);
	if (!(f2->hex = (char*)malloc(sizeof(char) * 9)))
		return (-1);
	ft_check_addr(f2);
	i = ft_addr_base(i, f2);
	if (f2->addr != 0)
		f2->tmp3 = f2->len;
	else if (f2->addr == 0 && f2->prec > 1)
		f2->width++;
	if (f2->minus == 0)
		ft_no_minus_addr(f2);
	if (f2->minus == 1)
	{
		ft_putstr_fd("0x", FD);
		f2->nb_char += 2;
	}
	ft_printf_addr2(i, f2->hex, f2);
	free(f2->hex);
	return (0);
}
