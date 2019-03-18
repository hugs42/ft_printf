#include "ft_printf.h"

int				ft_printf_addr(const char *format, va_list arg, t_flags *flags)
{
	int i;
	int len;
	unsigned long addr;
	char const *base;
	char res[9];

	int diff = 0;
	i = 8;
	base = "0123456789abcdef";
	len = flags->width;
	flags->flag = 'p';
	diff = flags->width - 11;
	int diff2 = flags->precision - 9;
	addr = (unsigned long) va_arg(arg, unsigned long);
	if (flags->precision == 0)
	{
		if ((flags->width > 11) && (flags->minus == 0) && (flags->zero == 0) && (flags->precision < 14))
			ft_putwidth(' ', 11, flags);
	else if ((flags->width > 11) && (flags->minus == 0) && (flags->zero == 0) && (flags->precision > 14))
		ft_putwidth(' ', 11 + diff2, flags);
	if ((flags->width > 11) && (flags->minus == 0) && (flags->zero == 1)) //&& (flags->precision < 14))
		ft_putwidth(' ', 11, flags);
	}
	else if (flags->precision < 0)
	{
		if ((flags->width > 11) && (flags->minus == 0) && (flags->zero == 0) && (flags->precision < 14))
			ft_putwidth(' ', 11, flags);
	else if ((flags->width > 11) && (flags->minus == 0) && (flags->zero == 0) && (flags->precision > 14))
		ft_putwidth(' ', 11 + diff2, flags);
	if ((flags->width > 11) && (flags->minus == 0) && (flags->zero == 1)) //&& (flags->precision < 14))
		ft_putwidth(' ', 11, flags);
	}
	while ((addr / 16) > 0 || i >= 8)
	{
		res[i] = base[addr % 16];
		addr /= 16;
		i--;
	}
	res[i] = base[(addr % 16)];
	ft_putchar('0');
	ft_putchar('x');
	if (flags->zero == 1 && flags->precision > 14)
		ft_putzero_adress(diff2);
	if (flags->zero == 1 && diff > 0 && flags->minus == 0)
		ft_putzero_adress(diff);
	else if  (flags->zero == 0 && diff2 > 0 && flags->precision > 9)
		ft_putzero_adress(diff2);
//	else if (flags->zero == 1 && 
	while (i < 9)
	{
			ft_putchar(res[i]);
			i++;
	}
	if (flags->zero == 0)
	{
		if ((flags->minus == 1 && flags->width > 11) && (flags->precision < 14))
			ft_putwidth(' ', 11, flags);
		 if ((flags->width > 11) && (flags->minus == 1) && (flags->precision > 14))
			ft_putwidth(' ', 11 + diff2, flags);
//	if ((flags->width > 11) && (flags->minus == 1) && (flags->precision == 0))
//		ft_putwidth(' ', 11, flags);
//	if ((flags->width > 11) && (flags->minus == 0) && (flags->precision == 0))
//		ft_putwidth(' ', 11, flags);
	}
	else if (flags->zero == 1)
	{
		if ((flags->minus == 1 && flags->width > 11) && (flags->precision < 14))
			ft_putwidth(' ', 11, flags);
		 if ((flags->width > 11) && (flags->minus == 1) && (flags->precision > 14))
			ft_putwidth(' ', 11 + diff2, flags);
	}
	return (SUCCESS);
}
