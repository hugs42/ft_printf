/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:28:34 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/13 18:51:37 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int		ft_parse_wildcard(int i, va_list *list, t_flags1 *f1, t_flags2 *f2)
{
	f2->wildcard = (int)va_arg(*list, int);
	if (f1->src[i - 1] == '.')
		f2->prec = f2->wildcard;
	else
	{
		f2->width = f2->wildcard;
		if (f2->width < 0)
			f2->n_width = 1;
	}
	if (f2->wildcard < 0)
	{
		f2->minus = 1;
		f2->width = ft_abs(f2->width);
		while (f1->src[i] != '*')
			i++;
	}
	else
		i = f1->i;
	return (i);
}

int		ft_is_flags(char c)
{
	int i;

	i = 0;
	while (TYPES_C[i] != '\0')
	{
		if (TYPES_C[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int		ft_check_char(int c)
{
	if ((c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
				|| c == 'x' || c == 'X' || c == '%' || c == '.' || c == '*' ||
				c == '0' || c == '-') || (ft_isdigit(c)))
		return (1);
	else
		return (0);
}

int		ft_set_flags(int i, t_flags1 *f1, t_flags2 *f2)
{
	if (f1->src[i] == '-')
	{
		f2->minus = 1;
		f2->minus_tmp = 1;
	}
	if (f1->src[i] == '0' && f1->src[i - 1] != '.')
	{
		f2->zero = 1;
		f2->space = '0';
	}
	if (f1->src[i] == '.')
	{
		if (f2->prec == 0)
			f2->prec = 0;
		f2->is_prec = 1;
	}
	return (0);
}
