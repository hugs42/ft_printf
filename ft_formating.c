/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:29:49 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/06 15:16:03 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int             ft_set_flags(char c, t_flags *flags)
{
        if (c == '#')
                flags->sharp = 1;
        if (c == '-')
                flags->minus = 1;
        if (c == '+')
                flags->plus =1;
        if (c == ' ')
                flags->space =1;
        if (c == '0')
                flags->zero =1;
        return (SUCCESS);
}

int		ft_get_width(const char *format, int i)
{
	int width;
	int j;
	int k;
	char *tmp_digit;

	width = 0;
	k = i;
	while (ft_isdigit(format[k]))
		k++;
	tmp_digit = malloc(sizeof(char) * (k - i + 1));
	while (ft_isdigit(format[i]))
	{
		tmp_digit[j] = format[i];
		i++;
		j++;
	}
	tmp_digit[j] = '\0';
	width = ft_atoi(tmp_digit);
	return (width);
}
