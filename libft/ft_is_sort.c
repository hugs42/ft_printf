/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:06:25 by hugsbord          #+#    #+#             */
/*   Updated: 2018/01/31 20:09:09 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	unsigned int	i;

	i = 0;
	while ((i + 1) < length)
	{
		if (f(tab[i + 1], tab[i]) < 0)
			return (0);
	}
	return (1);
}
