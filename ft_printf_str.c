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
	int count_char;

	count_char = 0;
	l = 0;
	flags->flag = 's';
	str = va_arg(arg, char *);
	len = ft_strlen(str);
	width = flags->width;
	if ((str == NULL && ft_strcmp(str, "") != 0) && (flags->width == 0))
	{
		if (flags->width > 1)
			count_char += ft_putwidth(c, 10, flags);
		ft_putchar('\0');
		count_char += 1;
	}
//	else if (ft ft_strcmp(str, "") != 0))
//		
	if (flags->space == 1 && flags->zero == 0 && flags->minus == 0 && flags->width > len && flags->plus == 0)
	{
		ft_putchar(' ');
		count_char++;
	}
	else if (flags->space == 1 && flags->zero == 1 && flags->minus == 0 && flags->width > len && flags->plus == 0)
	{
		ft_putchar('0');
		count_char++;
	}
	if (flags->zero == 1 && flags->minus == 0)
		c = '0';
	else
		c = ' ';
	if ((width > len) && (flags->minus == 0) && (flags->precision == 0) && (flags->is_precision == 0))
	{
		count_char += ft_putwidth(c, len, flags);
	}

	if (flags->precision == 1 && flags->width == 0)
		return (SUCCESS);
	if (flags->minus == 0)
	{
	if ((flags->precision == 0) && ((flags->width > ft_strlen(str))))
		count_char += ft_putwidth(c, len, flags);
		if (flags->precision >= 1 && flags->precision <= len && flags->width > len)
			count_char += ft_putwidth(c, len - (len - flags->precision), flags);
//		else if (flags->precision == 0 && flags->width > len)
//			count_char += ft_putwidth('j', len, flags);
		else if (flags->precision >= 1 && flags->precision > len && flags->width > len)
			count_char += ft_putwidth(c, len, flags);
	}
	if ((flags->precision >= 1) && (flags->precision < len))
	{
		if (flags->minus == 0 && flags->width != flags->precision && flags->width < len)
			count_char += ft_putwidth(c, /*flags->width - flags->precision*/len - (len - flags->precision), flags);
		count_char += ft_putnstr(str, flags->precision - 1);
	}
	else if ((flags->precision >= 1) && (flags->precision > len))
	{
		if (flags->minus == 0 && flags->width > len && flags->width != flags->precision && flags->precision < len - (len - flags->precision))
			count_char += ft_putwidth(c, flags->width - len, flags);
		if (flags->precision <= ft_strlen(str))
			count_char += ft_putnstr(str, flags->precision - 1);
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
		count_char += ft_strlen(str);
	}
	else
	{
		ft_putstr(str);
		count_char += ft_strlen(str);
	}
//	if ((flags->precision == 0) && ((flags->width > ft_strlen(str))))
//		ft_putwidth(c, len, flags);
//		ft_putchar('@');
//		ft_putstr(str);
//	}
	width = flags->width;
	if (flags->minus == 1)
	{
		if (flags->precision >= 1 && flags->precision <= len && flags->width > len)
		{
			count_char += ft_putwidth('a', len - (len - flags->precision), flags);
		}
		else if (flags->precision >= 1 && flags->precision <= len && flags->width < len)
		{

			count_char += ft_putwidth('e', len - (len - flags->precision), flags);
		}
		else if (flags->precision >= 1 && flags->precision > len && flags->width > len)
		{
			count_char += ft_putwidth('i', len, flags);
		}
		else if (width > len && flags->precision == 0 && flags->is_precision == 0)
		{
			count_char += ft_putwidth('u', len, flags);
		}
		else if (flags->precision == 0 && flags->width > len)
			count_char += ft_putwidth(c, len, flags);
	}
//	printf("\n%d\n %", count_char);
	return (count_char);
}
