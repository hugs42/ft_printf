#include "ft_printf.h"
#include <stdio.h>

int				ft_printf_char(const char *format, va_list arg, t_flags *flags)

{
	char c;
	char space;
	int count_char;

	count_char = 0;
	space = ' ';
	if (flags->zero == 1)
		space = '0';
	flags->flag = 'c';
	c = va_arg(arg, int);
	if (!c)
	{
		count_char = 1;
		if (flags->width > 1)
		{
			count_char += ft_putwidth(' ', 1, flags);
		}
		ft_putchar('\0');
		return (count_char);
	}
	if ((flags->width > 1) && (flags->minus == 0) && (flags->precision != 1))
		count_char += ft_putwidth(space, 1, flags);
	if (flags->minus == 1 && flags->width != 0)
		ft_putchar(c);
	else
		ft_putchar(c);
	count_char++;
	if ((flags->width > 1) && (flags->minus == 1))
		count_char += ft_putwidth(space, 1, flags);
	return (count_char);
}
