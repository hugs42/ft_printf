#include "ft_printf.h"
#include "./libft/libft.h"

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
			else if (format[i] == 'd')
				ft_printf_int(format, arg);
			else if (format[i] == 'e')
				break;
			else if (format[i] == 'f')
				break;
			else if (format[i] == 'o')
				break;
			else if (format[i] == 's')
				break;
			else if (format[i] == 'u')
				break;
			else if (format[i] == 'x')
				break;
			else if (format[i] == '%')
				break;
			count_char++;
			i++;
		}
//		else if (format[i] == '\\')
//		{
//			ft_putchar('\\');
//			i++;
//		}
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
	int i = -123456789;
	char nb  = '7';
	char nb1 = '6';
	char nb2 = '9';
	char *str = "8888888888";
	ft_printf("ft_printf ::%c::%c::%s::%c::%d::%%", nb1, nb, str, nb2, i);
	ft_putchar('\n');
	printf("printf    ::%c::%c::%s::%c::%d::%%", nb1, nb, str, nb2, i);
	ft_putchar('\n');
	return (0);
}
