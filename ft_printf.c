#include "ft_printf.h"
#include "./libft/libft.h"

int		count_arg(const char *format)
{
	int res;
	return (res);
}

int		ft_printf_options(const char *format, va_list arg, ...)
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
			{
				c = va_arg(arg, int);
				ft_putchar(c);
				i++;
				count_char++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(arg, char *);
				ft_putstr(str);
				i++;
				count_char++;
			}
		}
		else
		{
			ft_putchar(format[i]);
			count_char++;
			i++;
		}
	}
	ft_putchar('\n');
	return (count_char);
}

int		ft_printf(const char *format, ...)
{
	int res;
	va_list ap;
	va_start(ap, format);
	res = ft_printf_options(format, ap);
	va_end(ap);
	return (res);
}

int		main(int argc, char **argv)
{
	char nb  = '7';
	char nb1 = '6';
	char nb2 = '9';
	char *str = "8888888888";
	ft_printf("Test ::%c::%c::%s::%c::", nb1, nb, str, nb2);
	return (0);
}
