/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:41:53 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/13 19:09:59 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int		ft_check_str(t_flags2 *f2)
{
	if (f2->src == 0)
		f2->src = "(null)";
	if (f2->prec > 0 && (size_t)f2->prec < ft_strlen(f2->src))
		f2->len = f2->prec;
	else
		f2->len = ft_strlen(f2->src);
	if (f2->is_prec == 1 && f2->prec > 0)
	{
		if (f2->width <= 0 || f2->prec <= f2->width)
			f2->len = f2->prec;
	}
	if (f2->is_prec == 1 && f2->prec == 0)
		f2->len = 0;
	if (f2->prec < 0)
	{
		if (f2->n_width == 1)
			f2->minus = 1;
		else if (f2->minus_tmp == 1)
			f2->minus = 1;
		else if (f2->minus_tmp == 0)
			f2->minus = 0;
	}
	if (f2->zero == 1)
		f2->space = '0';
	return (0);
}

int		ft_is_minus_str(t_flags2 *f2)
{
	int		nb_char;
	int		len;

	nb_char = 0;
	len = ft_strlen(f2->src);
	if (f2->width > 0)
	{
		if (f2->prec > len && f2->width > len && len != 0 &&
				f2->prec <= f2->width)
		{
			while (f2->prec > len)
			{
				ft_putchar_fd(' ', FD);
				f2->prec--;
				f2->nb_char++;
			}
		}
		if (ft_strlen(f2->src) == 0 && f2->prec > 0 && f2->prec <= f2->width)
			f2->len -= f2->prec;
		f2->nb_char += ft_putwidth(' ', f2->len, f2);
	}
	return (0);
}

int		ft_no_minus_str(t_flags2 *f2)
{
	int		nb_char;
	int		len;

	nb_char = 0;
	len = ft_strlen(f2->src);
	if (f2->width > 0)
	{
		if (f2->prec > len && f2->width > len && len != 0 &&
				f2->prec <= f2->width)
		{
			while (f2->prec > len)
			{
				ft_putchar_fd(' ', FD);
				f2->prec--;
				f2->nb_char++;
			}
		}
		if (ft_strlen(f2->src) == 0 && f2->prec > 0 && f2->prec <= f2->width)
		{
			f2->len -= f2->prec;
		}
		f2->nb_char += ft_putwidth(f2->space, f2->len, f2);
	}
	return (0);
}

int		ft_printf_str(va_list *list, t_flags2 *f2)
{
	int			i;

	i = 0;
	f2->src = (char*)va_arg(*list, char *);
	ft_check_str(f2);
	if (f2->minus == 0)
		f2->nb_char += ft_no_minus_str(f2);
	if (f2->is_prec == 1 && f2->prec == 0)
		ft_putchar_fd(FD, ' ');
	else
		f2->nb_char += ft_putnstr_fd(f2->src, f2->len, FD);
	if (f2->minus == 1)
		f2->nb_char += ft_is_minus_str(f2);
	return (0);
}
