#include "ft_printf.h"

int				ft_printf_str(const char *format, va_list arg, t_flags *flags)
{
	char *str;
	int len;
	int width;
	int i;
	int pp;
	char c;
	int l;
	l = 0;
	flags->flag = 's';
	str = va_arg(arg, char *);
	len = ft_strlen(str);
	width = flags->width;
	if (str == NULL || ft_strcmp(str, "") == 0)
		return (ERROR);
	if (flags->space == 1 && flags->zero == 0 && flags->minus == 0)
		ft_putchar(' ');
	else if (flags->space == 1 && flags->zero == 1 && flags->minus == 0)
		ft_putchar('0');
	if (flags->zero == 1)
		c = '0';
	else
		c = ' ';
	if ((width > len) && (flags->minus == 0) && (flags->precision == 0) && (flags->is_precision == 0))
	{
		ft_putwidth(c, len, flags);
	}
//	if (flags->precision >= 1)
//	{
		if (flags->precision == 1 && flags->width == 0)
			return (SUCCESS);
		else if (flags->precision >= 1 && flags->precision <= len && flags->width > len && flags->minus == 0)
			ft_putwidth(c, len - (len - flags->precision), flags);
//		else if (flags->precision >= 1 && flags->precision <= len && flags->width < len && flags->minus == 0)
//			ft_putwidth(c, len - (len - flags->precision), flags);
		else if (flags->precision >= 1 && flags->precision > len && flags->width > len && flags->minus == 0)
			ft_putwidth(c, len, flags);
//		else if (flags->precision >= 1 && flags->precision < len && flags->width > len && flags->minus == 0)
//			ft_putwidth(c, len, flags);

//	if (flags->is_precision == 1 && flags->precision == 0)
//		ft_putchar(c);
//	printf("%d -", flags->width);
	if ((flags->precision >= 1) && (flags->precision < len))
	{
		if (flags->minus == 0 && flags->width != flags->precision && flags->width < len)
			ft_putwidth(c, /*flags->width - flags->precision*/len - (len - flags->precision), flags);
		ft_putnstr(str, flags->precision - 1);
	}
	else if ((flags->precision >= 1) && (flags->precision > len))
	{
		if (flags->minus == 0 && flags->width > len && flags->width != flags->precision && flags->precision < len - (len - flags->precision))
			ft_putwidth(c, flags->width - len, flags);
		if (flags->precision <= ft_strlen(str))
			ft_putnstr(str, flags->precision - 1);
		else
			ft_putstr(str);
	}
	else if (flags->is_precision == 1 && flags->precision == 0)
		while (l++ < flags->width)
			ft_putchar(c);
	else if ((flags->precision == 0) && ((flags->width > ft_strlen(str))))
	{
//	ft_putwidth(c, len, flags);		
//	ft_putchar('@');
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
	}
//	if ((flags->precision == 0) && ((flags->width > ft_strlen(str))))
//	{
//	ft_putwidth(c, len, flags);
//		ft_putchar('@');
//		ft_putstr(str);
//	}
	width = flags->width;
	if (flags->minus == 1)
	{
		if (flags->precision >= 1 && flags->precision <= len && flags->width > len)
			ft_putwidth('a', len - (len - flags->precision), flags);
		else if (flags->precision >= 1 && flags->precision <= len && flags->width < len)
			ft_putwidth('e', len - (len - flags->precision), flags);
		else if (flags->precision >= 1 && flags->precision > len && flags->width > len)
			ft_putwidth('i', len, flags);
		if ((width > len) && (flags->precision == 0))
			ft_putwidth('u', len, flags);
	}
	return (SUCCESS);
}

