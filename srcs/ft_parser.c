/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:17:40 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/17 16:09:47 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

void	ft_parse_flags2(t_flags1 *f1, t_flags2 *f2)
{
	if (ft_isdigit(f1->src[f1->tmp]) && f1->src[f1->tmp - 1] != '.'
			&& f2->width == 0)
	{
		ft_get_width(f1->tmp, f1, f2);
		while (ft_isdigit(f1->src[f1->tmp]))
			f1->tmp++;
		f1->tmp--;
	}
	if (f1->src[f1->tmp] == '.')
		f2->is_prec = 1;
	if (ft_isdigit(f1->src[f1->tmp]) && f1->src[f1->tmp - 1] == '.'
			&& f2->prec == 0)
	{
		f2->is_prec = 1;
		ft_get_precision(f1->tmp, f1, f2);
		while (ft_isdigit(f1->src[f1->tmp]))
			f1->tmp++;
		f1->tmp--;
	}
}

void	ft_parse_flags(va_list *list, t_flags1 *f1, t_flags2 *f2)
{
	f1->tmp = f1->i;
	while (ft_strchr(ALL_C, f1->src[f1->tmp + 1]))
	{
		if (f1->src[f1->tmp] == '*')
			ft_parse_wildcard(f1->tmp, list, f1, f2);
		if (ft_strchr(FLAGS_C, f1->src[f1->tmp]))
			ft_set_flags(f1->tmp, f1, f2);
		ft_parse_flags2(f1, f2);
		if (ft_is_type(f1->src[f1->tmp]))
			break ;
		f1->tmp++;
	}
}

int		ft_parse_index(char c, t_flags2 *f2)
{
	int i;

	i = 0;
	while (TYPES_C != '\0')
	{
		if (TYPES_C[i] == c)
		{
			if (i == 7)
				f2->hex_up = 1;
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_parser2(va_list *list, t_flags1 *f1, t_flags2 *f2)
{
	int		i;
	int		j;

	i = f1->i;
	j = f1->i;
	ft_init_flags2(f2);
	if (ft_check_type(f1) == 0)
		return (-1);
	if (ft_is_flags(f1->src[f1->i]) == 1)
	{
		ft_parse_flags(list, f1, f2);
		while (!(ft_strchr(TYPES_C, f1->src[f1->i])))
			f1->i++;
	}
	f2->src = ft_strdup(f1->src);
	f2->i = f1->i;
	f1->index = ft_parse_index(f1->src[f1->i], f2);
	if (f1->index == 8)
		f1->i++;
	free(f2->src);
	return (0);
}

int		ft_parser(va_list *list, t_flags1 *f1, t_flags2 *f2)
{
	int			(*tab_funct[9])(va_list *, t_flags2 *);

	tab_funct[0] = ft_printf_char;
	tab_funct[1] = ft_printf_str;
	tab_funct[2] = ft_printf_addr;
	tab_funct[3] = ft_printf_int;
	tab_funct[4] = ft_printf_int;
	tab_funct[5] = ft_printf_uns;
	tab_funct[6] = ft_printf_hex;
	tab_funct[7] = ft_printf_hex;
	tab_funct[8] = ft_printf_percent;
	if (ft_check_char(f1->src[f1->i]) == -1 || (ft_parser2(list, f1, f2) == -1))
	{
		free(f2);
		return (-1);
	}
	if (f1->index != -1)
	{
		f1->type = 1;
		if (f1->index == 8)
			f1->type = 10;
		(*tab_funct[f1->index])(list, f2);
	}
	f1->nb_char += f2->nb_char;
	return (0);
}
