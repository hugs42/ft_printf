/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:42:36 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/14 16:34:04 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int		ft_utoa(unsigned int nbr, t_flags2 *f2)
{
	int				i;
	char			*res;
	unsigned int	u_nbr;

	i = 1;
	u_nbr = nbr;
	while ((u_nbr /= 10) >= 1)
		i++;
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	res[i] = '\0';
	u_nbr = nbr;
	while (i-- > 0)
	{
		res[i] = (u_nbr % 10 < 10) ? u_nbr % 10 + '0' : u_nbr % 10 + 'a' - 10;
		u_nbr /= 10;
	}
	f2->src = ft_strdup(res);
	free(res);
	return (0);
}

int		ft_no_minus_uns(t_flags2 *f2)
{
	int diff;

	diff = f2->prec - f2->len_nbr;
	if (f2->width > 0 && f2->width > f2->len_nbr && f2->prec < f2->len_nbr)
		f2->nb_char += ft_putwidth(f2->space, f2->len_nbr, f2);
	else if (f2->width > f2->prec && f2->prec >= f2->len_nbr)
		f2->nb_char += ft_putwidth(f2->space, f2->len_nbr + diff, f2);
	return (0);
}

int		ft_is_minus_uns(t_flags2 *f2)
{
	int diff;

	diff = f2->prec - f2->len_nbr;
	if (f2->width > 0 && f2->width > f2->len_nbr && f2->prec < f2->len_nbr)
		f2->nb_char += ft_putwidth(f2->space, f2->len_nbr, f2);
	else if (f2->width > f2->prec && f2->prec >= f2->len_nbr)
		f2->nb_char += ft_putwidth(f2->space, f2->len_nbr + diff, f2);
	return (0);
}

void	ft_check_uns(t_flags2 *f2)
{
	if (f2->u_nbr == 0)
		f2->nb_char = 1;
	if (f2->prec < 0 && f2->minus_tmp == 0)
		f2->minus = 0;
	if (f2->prec < 0 && f2->n_width == 1)
	{
		f2->minus = 1;
		f2->space = ' ';
	}
	if ((f2->zero == 1 && f2->is_prec != 0) || (f2->minus == 1))
		if (f2->prec >= 0)
			f2->space = ' ';
	if (f2->u_nbr == 0 && f2->is_prec == 1 && f2->prec == 0)
		f2->len_nbr--;
}

int		ft_printf_uns(va_list *list, t_flags2 *f2)
{
	f2->u_nbr = (unsigned int)va_arg(*list, unsigned int);
	ft_utoa(f2->u_nbr, f2);
	f2->len_nbr += ft_strlen(f2->src);
	f2->nb_char += f2->len_nbr;
	ft_check_uns(f2);
	if (f2->minus == 0)
		f2->nb_char += ft_no_minus_uns(f2);
	if (f2->prec > f2->len_nbr)
	{
		f2->tmp = f2->prec;
		while (f2->tmp > f2->len_nbr)
		{
			ft_putchar_fd('0', FD);
			f2->tmp--;
			f2->nb_char++;
		}
	}
	if (f2->u_nbr == 0 && f2->is_prec == 1 && f2->prec == 0)
		f2->nb_char--;
	else
		ft_putstr_fd(f2->src, FD);
	if (f2->minus == 1)
		f2->nb_char += ft_is_minus_uns(f2);
	free(f2->src);
	return (0);
}
