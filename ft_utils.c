/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:02:49 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/05 19:07:27 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putstrrev(char *str)
{
	int len;
	len = ft_strlen(str);
	while (len + 1 > 0)
	{
		ft_putchar(str[len]);
		len--;
	}
	return (SUCCESS);
}

int		ft_is_diouxx(const char *format, va_list arg, int i)
{
	if ((format[i] == 'd') || (format[i] == 'i') || (format[i] ==
						'o') || (format[i] == 'u') || (format[i] == 'x') ||
							(format[i] == 'X'))
		return (SUCCESS);
	else
		return (FINISH);
}

int		ft_init_printf_struct(t_printf 
