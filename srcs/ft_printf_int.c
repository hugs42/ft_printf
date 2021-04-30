/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:09:24 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/14 12:57:54 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int		ft_no_minus_int(t_flags2 *f2)
{
	int nb_char;

	nb_char = 0;
	if (f2->is_n == 1)
		f2->tmp--;
	if (f2->width > 0 && f2->width > f2->len_nbr && f2->prec < f2->len_nbr)
	{
		if (f2->is_prec == 1 && f2->prec >= 0)
			f2->space = ' ';
		if (f2->zero == 1 && f2->is_n == 1 && f2->is_prec <= 0)
			return (0);
		else if (f2->zero == 1 && f2->prec < 0 && f2->minus_tmp == 0
				&& f2->is_n)
			return (0);
		nb_char += ft_putwidth(f2->space, f2->len_nbr, f2);
	}
	else if (f2->width > f2->prec && f2->prec >= f2->len_nbr)
	{
		nb_char += f2->tmp;
		while (f2->tmp-- > 0)
			ft_putchar_fd(' ', FD);
	}
	return (nb_char);
}

int		ft_is_minus_int(t_flags2 *f2)
{
	int nb_char;

	nb_char = 0;
	if (f2->is_n == 1)
	{
		f2->tmp--;
		f2->len_nbr++;
	}
	if (f2->is_prec == 1 || f2->width > 0)
		f2->space = ' ';
	if (f2->width > 0 && f2->width > f2->len_nbr && f2->prec <= f2->len_nbr)
	{
		nb_char += ft_putwidth(f2->space, f2->len_nbr, f2);
	}
	if (f2->tmp2 > f2->prec && f2->prec >= f2->len_nbr)
	{
		nb_char += f2->tmp;
		while (f2->tmp-- > 0)
			ft_putchar_fd(' ', FD);
	}
	return (nb_char);
}

void	ft_check_int(t_flags2 *f2)
{
	if (f2->nbr == 0)
		f2->nb_char = 1;
	if (f2->width != 0 && f2->prec < 0 && f2->minus_tmp == 1)
		f2->minus = 1;
	else if (f2->width != 0 && f2->prec < 0 && f2->minus_tmp == 0)
		f2->minus = 0;
	if (f2->n_width == 1 && f2->prec < 0)
		f2->minus = 1;
	if (f2->nbr < 0)
		f2->is_n = 1;
	if (f2->nbr == 0 && f2->is_prec == 1 && f2->prec == 0)
	{
		f2->space = ' ';
		if (f2->width == 0)
			f2->nb_char--;
	}
}

int		ft_printf_int(va_list *list, t_flags2 *f2)
{
	char *tmp;

	f2->nbr = (int)va_arg(*list, int);
	tmp = ft_itoa(f2->nbr);
	f2->len_nbr = ft_strlen(tmp);
	free(tmp);
	f2->nb_char += f2->len_nbr;
	f2->tmp = f2->width - f2->prec;
	ft_check_int(f2);
	if (f2->minus == 0)
		f2->nb_char += ft_no_minus_int(f2);
	if (f2->nbr != -2147483648)
		ft_putnbr_printf(f2->nbr, f2);
	else
		ft_putstr_fd("-2147483648", FD);
	if (f2->minus == 1)
		f2->nb_char += ft_is_minus_int(f2);
	return (0);
}
