/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:26:02 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/17 17:38:15 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int		ft_printf_char(va_list *list, t_flags2 *f2)
{
	int		c;

	c = (int)va_arg(*list, int);
	if (f2->zero == 1)
		f2->space = '0';
	if (f2->prec < 0 && f2->n_width == 1 && f2->minus_tmp == 0)
		f2->minus = 1;
	else if (f2->prec < 0 && f2->n_width == 0 && f2->minus_tmp == 0)
		f2->minus = 0;
	if (f2->width > 0 && f2->minus == 0)
		f2->nb_char += ft_putwidth(f2->space, 1, f2);
	if (c == 0)
		ft_putchar_fd('\x00', FD);
	else
		ft_putchar_fd(c, FD);
	f2->nb_char++;
	if (f2->width > 0 && f2->minus == 1)
		f2->nb_char += ft_putwidth(' ', 1, f2);
	return (0);
}
