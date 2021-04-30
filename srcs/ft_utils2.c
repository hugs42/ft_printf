/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:53:11 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/19 13:08:53 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

unsigned int	ft_abs(int i)
{
	return (i * ((i > 0) - (i < 0)));
}

char			*ft_itoa_base(int nbr, int base)
{
	char					*str;
	unsigned long			n;
	int						i;

	i = 1;
	n = nbr;
	while ((n /= base) >= 1)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	n = nbr;
	while (i-- > 0)
	{
		if (n % base < 10)
			str[i] = n % base + 48;
		else
			str[i] = n % base + 'a' - 10;
		n /= base;
	}
	return (str);
}
