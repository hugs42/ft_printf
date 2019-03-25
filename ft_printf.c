/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:49:04 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/22 16:04:54 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_csp_case(const char *format, va_list arg, int i ,t_flags *flags)
{
	int count_char;

	count_char = 0;
	if (format[i] == 'c')
		count_char += ft_printf_char(format, arg, flags);
//	else if (format[i] == 's' && va_arg(arg, char *) == NULL)
//	{
//		count_char += ft_printf_str_null(format, arg, flags);
//	}
//	}
	else if (format[i] == 's') //&& va_arg(arg, char *) != NULL)
		count_char += ft_printf_str(format, arg, flags);
	else if (format[i] == 'p')
		count_char += ft_printf_addr(format, arg, flags);
	return (count_char);
}

int		ft_printf_diouxx_case(const char *format, va_list arg, int i, t_flags *flags)
{
	int count_char;

	count_char = 0;
	if ((format[i] == 'd') || (format[i] == 'i'))
		count_char += ft_printf_int(format, arg, flags);
	else if (format[i] == 'o')
		count_char += ft_printf_octal(format, arg, flags);
	else if (format[i] == 'u')
		count_char += ft_printf_unsigned_int(format, arg, flags);
	else if ((format[i] == 'x') || (format[i] == 'X'))
		count_char += ft_printf_hex(format, arg, format[i], flags);
	return (count_char);
}
#include <stdio.h>

int		ft_printf_parse(const char *format, va_list arg)
{
	int			i;
	int			count_char;
	char		*str;
	t_flags		*flags;
	int			len_w;

	i = 0;
	len_w = 0;
	count_char = 0;
	flags = malloc(sizeof(t_flags));
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if ((ft_init_flags_struct(flags)) != SUCCESS)
				return (ERROR);
			i++;
			while (ft_isflag(format, i))
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
/*			if (format[i] == '%')
			{
				if (flags->minus == 0)
					count_char += ft_putwidth(' ', flags->width, flags);
//				ft_putchar('%');
				if (flags->minus == 1)
					count_char += ft_putwidth(' ', flags->width, flags);
			}*/
			if (format[i] == '.')
			{
				flags->precision = 0;
				flags->is_precision = 1;
				i++;
//				if (!(ft_isdigit(format[i])))
//					flags->precision = 0;
				if (ft_isdigit(format[i]))
				{
//					ft_putchar(':');
					flags->precision = ft_get_precision(format, i);
					while (ft_isdigit(format[i]))
						i++;
				}
				else
					flags->precision = 0;
			}
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'p')
				count_char += ft_printf_csp_case(format, arg, i, flags);
			if (ft_is_diouxx(format, arg, i))
				count_char += ft_printf_diouxx_case(format, arg, i, flags);
			else if (format[i] == 'f')
			{
				if (format[i - 1] == 'l' || format[i - 1] == 'L')
					ft_printf_long_double(format, arg, flags);
				else
					ft_printf_double(format, arg, flags);
			}
			else if (format[i] == '%')
			{
				len_w = flags->width;
				if (flags->minus == 0 && flags->width > 0)
					while (--len_w > 0)
					{
						ft_putchar(' ');
						count_char++;
					}
					len_w = flags->width;
				ft_putchar('%');
				count_char++;
				if (flags->minus == 1 && flags->width > 0)
					while (--len_w > 0)
					{
						ft_putchar(' ');
						count_char++;
					}
			}
//			count_char++;
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			count_char++;
			i++;
		}
//		count_char = i;
	}
	return (count_char);
}

int		ft_printf(const char *format, ...)
{
	int count_char;
	va_list ap;
	va_start(ap, format);
	count_char = ft_printf_parse(format, ap);
//	printf("\n%d\n", count_char);
	va_end(ap);
	return (count_char);
}
