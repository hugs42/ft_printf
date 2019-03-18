#include "ft_printf.h"
#include <stdio.h>

int				ft_printf_char(const char *format, va_list arg, t_flags *flags)

{
	char c;
	char space;

	space = ' ';
	if (flags->zero == 1)
		space = '0';
	flags->flag = 'c';
	c = va_arg(arg, int);
	if (!c)
		return (ERROR);
	if ((flags->width > 1) && (flags->minus == 0) && (flags->precision != 1))
		ft_putwidth(space, 1, flags);
	if (flags->minus == 1 && flags->width != 0)
		ft_putchar(c);
	else
		ft_putchar(c);
	if ((flags->width > 1) && (flags->minus == 1))
		ft_putwidth(space, 1, flags);
	return (SUCCESS);
}
