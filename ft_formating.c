/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:29:49 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/07 18:14:56 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_set_flags(const char *format, int i, t_flags *flags)
{
	if (format[i] == '#')
		flags->sharp = 1;
	else if (format[i] == '-')
		flags->minus = 1;
	else if (format[i] == '+')
		flags->plus = 1;
	else if (format[i] == ' ')
		flags->space = 1;
	else if (format[i] == '0')
		flags->zero = 1;
	return (SUCCESS);
}

int		ft_set_specifier(const char *format, int i, t_flags *flags)
{
	if ((format[i] == 'l' && format[i] != 'l') || format[i] == 'L')
		flags->l = 1;
	else
		flags->l = 0;
	if (format[i] == 'l' && format[i] == 'l')
		flags->ll = 1;
	else
		flags->ll = 0;
	if (format[i] == 'h' && format[i] != 'h')
		flags->h = 1;
	else
		flags->h = 0;
	if (format[i] == 'h' && format[i] == 'h')
		flags->hh = 1;
	else
		flags->hh = 0;
	return (SUCCESS);
}

int		ft_get_precision(const char *format, int i)
{
	int precision;
	int j;
	int k;
	char *tmp_precision;

	precision = 0;
	j = 0;
	k = i;
	while (ft_isdigit(format[k]))
		k++;
	tmp_precision = malloc(sizeof(char) * (k - i + 1));
	while (ft_isdigit(format[i]))
	{
		tmp_precision[j] = format[i];
		i++;
		j++;
	}
	tmp_precision[j] = '\0';
	//printf("@%s@", tmp_precision);
	precision = ft_atoi(tmp_precision);
	free(tmp_precision);
//;;;	printf("==%d", precision);
	if (!precision)
		return (1);
	else
	{
		return (precision);
	}
}

int		ft_get_width(const char *format, int i)
{
	int width;
	int j;
	int k;
	char *tmp_digit;

	width = 0;
	j = 0;
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
	free(tmp_digit);
	return (width);
}

int		ft_format_specifiers(const char *format, int i, t_flags *flags)
{
	
	return (0);
}
