/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:49:04 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/05 16:40:24 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_parse(const char *format, va_list arg)
{
	int i;
	int count_char;
	char c;
	char *str;

	i = 0;
	count_char = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_printf_char(format, arg);
			else if (format[i] == 's')
				ft_printf_str(format, arg);
			else if (format[i] == 'p')
				ft_printf_addr(format, arg);
			else if ((format[i] == 'd') || (format[i] == 'i'))
				ft_printf_int(format, arg);
			else if (format[i] == 'o')
				ft_printf_octal(format, arg);
			else if (format[i] == 'u')
				ft_printf_unsigned_int(format, arg);
			else if ((format[i] == 'x') || (format[i] == 'X'))
				ft_printf_hex(format, arg, format[i]);
			else if (format[i] == '%')
				ft_putchar('%');
//			else if (format[i] == 'e')
//				break;
//			else if (format[i] == 'f')
//				break;
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
	int res;
	va_list ap;
	va_start(ap, format);
	res = ft_printf_parse(format, ap);
	va_end(ap);
	return (res);
}

int		main(int argc, char **argv)
{
	int i = 19;
	int j = 123;
	unsigned int ui = 1849494;
	char nb  = '7';
	char nb1 = '6';
	char nb2 = '9';
	char *str = "8888888888";
	char *str2 = "punk";

	ft_printf("ft_printf ::%c::%s::%p::%d::%i::%o::%u::%x::%X::%%::", nb1, str, str2, i, j, i,ui,j, j);
	printf("printf    ::%c::%s::%p::%d::%i::%o::%u::%x::%X::%%::", nb1, str, str2, i, j,i, ui, j,j);
	ft_putchar('\n');
	return (0);
}
