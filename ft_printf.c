/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:49:04 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/07 16:49:05 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_csp_case(const char *format, va_list arg, int i ,t_flags *flags)
{
	if (format[i] == 'c')
		ft_printf_char(format, arg, flags);
	else if (format[i] == 's')
		ft_printf_str(format, arg, flags);
	else if (format[i] == 'p')
		ft_printf_addr(format, arg, flags);
	return (SUCCESS);
}

int		ft_printf_diouxx_case(const char *format, va_list arg, int i, t_flags *flags)
{
	if ((format[i] == 'd') || (format[i] == 'i'))
		ft_printf_int(format, arg, flags);
	else if (format[i] == 'o')
		ft_printf_octal(format, arg, flags);
	else if (format[i] == 'u')
		ft_printf_unsigned_int(format, arg, flags);
	else if ((format[i] == 'x') || (format[i] == 'X'))
		ft_printf_hex(format, arg, format[i], flags);
	return (SUCCESS);
}

int		ft_printf_parse(const char *format, va_list arg)
{
	int			i;
	int			count_char;
	char		*str;
	t_flags		*flags;

	i = 0;
	count_char = 0;
	flags = malloc(sizeof(t_flags));
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if ((ft_init_flags_struct(flags)) != SUCCESS)
				return (ERROR);
			i++;
			if (ft_isflag(format, i))
			{
				ft_set_flags(format, i, flags);
				i++;
			}
			if (ft_isdigit(format[i]))
			{
				flags->width = ft_get_width(format, i);
				while (ft_isdigit(format[i]))
					i++;
			}
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'p')
				ft_printf_csp_case(format, arg, i, flags);
			if (ft_is_diouxx(format, arg, i))
				ft_printf_diouxx_case(format, arg, i, flags);
			else if (format[i] == 'f')
				ft_printf_double(format, arg, flags);
			else if (format[i] == '%')
				ft_putchar('%');
			count_char++;
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			count_char++;
			i++;
		}
	}
	return (count_char);
}

int		ft_printf(const char *format, ...)
{
	int count_char;
	va_list ap;
	va_start(ap, format);
	count_char = ft_printf_parse(format, ap);
	va_end(ap);
	return (count_char);
}
