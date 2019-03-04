#include "ft_printf.h"

int		ft_printf_str(const char *format, va_list arg)
{
		char *str;

		str = va_arg(arg, char *);
		ft_putstr(str);
		return (SUCCESS);
}
