/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:29:49 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/06 19:08:10 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_flags(const char *format, int i, t_flags *flags)
{
	if (format[i] == '#')
		flags->sharp = 1;
	else
		flags->sharp = 0;
	if (format[i] == '-')
		flags->minus = 1;
	else
		flags->minus = 0;
	if (format[i] == '+')
		flags->plus = 1;
	else
		flags->plus = 0;
	if (format[i] == ' ')
		flags->space = 1;
	else
		flags->space = 0;
	if (format[i] == '0')
		flags->zero = 1;
	else
		flags->zero = 0;
	if (format[i] == '.')
		flags->precision = 1;
	else
		flags->precision = 0;
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
