/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:25:32 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/17 16:11:46 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

t_flags1	*ft_init_flags1(void)
{
	t_flags1	*f1;

	if (!(f1 = (t_flags1*)malloc(sizeof(t_flags1))))
		return (0);
	f1->src = NULL;
	f1->i = 0;
	f1->index = 0;
	f1->nb_char = 0;
	f1->type = 0;
	f1->widlcard = 0;
	f1->tmp = 0;
	return (f1);
}

void		ft_init_flags2(t_flags2 *f2)
{
	f2->src = NULL;
	f2->i = 0;
	f2->nb_char = 0;
	f2->nbr = 0;
	f2->u_nbr = 0;
	f2->width = 0;
	f2->n_width = 0;
	f2->type = 0;
	f2->prec = 0;
	f2->is_prec = 0;
	f2->len = 0;
	f2->zero = 0;
	f2->minus = 0;
	f2->minus_tmp = 0;
	f2->wildcard = 0;
	f2->space = ' ';
	f2->hex = NULL;
	f2->hex_up = 0;
	f2->tmp = 0;
	f2->tmp2 = 0;
	f2->tmp3 = 0;
	f2->len_nbr = 0;
	f2->is_n = 0;
	f2->addr = 0;
}

int			ft_get_width(int i, t_flags1 *f1, t_flags2 *f2)
{
	int			j;
	int			k;
	char		*tmp;

	j = 0;
	k = i;
	while (ft_isdigit(f1->src[k]))
		k++;
	if (!(tmp = malloc(sizeof(char) * (k - i + 1))))
		return (-1);
	while (ft_isdigit(f1->src[i]))
	{
		tmp[j] = f1->src[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	f2->width = ft_atoi(tmp);
	free(tmp);
	return (0);
}

int			ft_get_precision(int i, t_flags1 *f1, t_flags2 *f2)
{
	int		j;
	int		k;
	char	*tmp;

	j = 0;
	k = i;
	while (ft_isdigit(f1->src[k]))
		k++;
	if (!(tmp = malloc(sizeof(char) * (k - i + 1))))
		return (-1);
	while (ft_isdigit(f1->src[i]))
	{
		tmp[j] = f1->src[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	f2->prec = ft_atoi(tmp);
	free(tmp);
	return (0);
}

int			ft_putwidth(char c, int len, t_flags2 *f2)
{
	int width;
	int nb_char;
	int tmp;

	width = f2->width;
	nb_char = 0;
	tmp = len;
	while (width > len)
	{
		ft_putchar_fd(c, FD);
		nb_char++;
		width--;
	}
	return (nb_char);
}
