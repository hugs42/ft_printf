#include "ft_printf.h"

int				ft_printf_int(const char *format, va_list arg)
{
		int i;

		i = va_arg(arg, int);
		ft_putnbr(i);
		return (SUCCESS);
}
