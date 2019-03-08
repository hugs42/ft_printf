/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:02:49 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/06 19:05:41 by hugsbord         ###   ########.fr       */
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

int		ft_isflag(const char *format, int i)
{
	if ((format[i] == '#') || (format[i] == '-') || (format[i] ==
						'+') || (format[i] == ' ') || (format[i] == '.') ||
							(format[i] == 'h') || (format[i]) == '0')
		return (SUCCESS);
	else
		return (FINISH);

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

int		ft_init_flags_struct(t_flags *flags)
{
	flags->flag = '0';
	flags->sharp = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->len = 0;
	flags->len_min = 0;
	flags->precision = 0;
	flags->format = NULL;
	return (SUCCESS);
}

