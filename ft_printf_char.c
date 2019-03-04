#include "ft_printf.h"

int		ft_printf_char(const char *format, va_list arg)
{
	char c;

	c = va_arg(arg, int);
	ft_putchar(c);
	return (SUCCESS);
}
