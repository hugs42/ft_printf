/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:40:20 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/06 14:21:18 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char	*move_left(const char *format, int nb, char c)
{
	int i;
	int len;
	char *str;
	char *new;

	len = ft_strlen(format);
	if (len >= nb)
		return (str);
	str = ft_strnew(nb);
	i = 0;
	while (i < (nb - len))
		str[i++] = c;
	while (i < nb)
		str[i++] = *format++;
	return (format);
	if (len <= nb)
		return (str);
	return (str);
}

char	*move_right(const char *format, int nb, char c)
{
	int i;
	int len;
	char *str;

	i = 0;
	if (len <= nb)
		return (str);
	str = ft_strnew(nb);
	len = ft_strlen(format);
	
	return (str);
}
*/
int		ft_is_valid_precision(char c)
{
	if (ft_isdigit(c))
		return (SUCCESS);
	return (FINISH);
}
