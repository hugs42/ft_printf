/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:00:40 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/18 19:28:48 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int			ft_hex_conv(int nbr, int size, char *base, t_flags2 *f2)
{
	int			i;
	char		*res;

	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (-1);
	if (nbr < 0)
		nbr = ft_abs(nbr);
	if (nbr == 0)
	{
		ft_hex_conv_ifzero(f2);
		return (0);
	}
	while (nbr > 0)
	{
		res[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	res[i] = '\0';
	f2->hex = ft_strrev(res);
	free(res);
	f2->nb_char += ft_strlen(f2->hex);
	return (0);
}

int			ft_printf_n_hex(int nbr, t_flags2 *f2)
{
	int		i;
	char	*res;
	char	*nb;

	i = 0;
	nb = ft_itoa_base(nbr, 16);
	res = ft_substr(nb, 8, 16);
	free(nb);
	if (f2->hex_up == 1)
	{
		while (res[i] != '\0')
		{
			if (res[i] >= 97 && res[i] <= 122)
				ft_putchar_fd(res[i] - 32, FD);
			else
				ft_putchar_fd(res[i], FD);
			i++;
		}
	}
	else
		ft_putstr_fd(res, FD);
	f2->tmp3 = ft_strlen(res);
	free(res);
	return (0);
}

int			ft_hex_print(int nbr, int size, t_flags2 *f2)
{
	int		n_hex;

	n_hex = 0;
	if (f2->hex_up == 1)
		f2->nb_char += ft_hex_conv(nbr, size, BASE_UP, f2);
	else if (f2->hex_up == 0)
		f2->nb_char += ft_hex_conv(nbr, size, BASE, f2);
	if (nbr >= 0)
		ft_putstr_fd(f2->hex, FD);
	else
	{
		if (f2->hex_up == 1)
			ft_printf_n_hex(nbr, f2);
		else if (f2->hex_up == 0)
			ft_printf_n_hex(nbr, f2);
	}
	if (f2->tmp2 < 0 && ft_strlen(f2->hex) != 8)
		f2->nb_char += 8 - ft_strlen(f2->hex);
	free(f2->hex);
	return (0);
}

void		ft_check_hex(int size, t_flags2 *f2)
{
	if (f2->prec > size)
		f2->tmp += f2->prec;
	if (f2->prec < 0)
	{
		f2->prec = 1;
		if (f2->n_width == 1)
			f2->minus = 1;
		else if (f2->n_width == 0 && f2->minus_tmp == 0)
			f2->minus = 0;
		else if (f2->minus_tmp == 1)
			f2->minus = 1;
		else if (f2->minus_tmp == 0)
			f2->minus = 1;
	}
}

int			ft_printf_hex(va_list *list, t_flags2 *f2)
{
	int		nbr;
	int		size;

	nbr = (int)va_arg(*list, int);
	size = ft_hex_len(nbr);
	f2->tmp2 = nbr;
	ft_check_hex(size, f2);
	if (f2->tmp2 < 0)
		size = 8;
	if (f2->minus == 0)
		ft_no_minus_hex(size, f2);
	else if (f2->minus == 1 && f2->prec > size)
		ft_add_zero_hex(nbr, size, f2);
	ft_hex_print(nbr, size, f2);
	if (f2->minus == 1)
		ft_is_minus_hex(size, f2);
	return (0);
}
