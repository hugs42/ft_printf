#include "ft_printf.h"

int				ft_printf_int(const char *format, va_list arg, t_flags *flags)
{
	int i;
	int width;
	int len_nbr;
	int prec = 0;
	int zero;
	int minus;
	char c;
	int count_char = 0;

	flags->flag = 'd';
	i = va_arg(arg, int);
	width = flags->width;
	zero = flags->zero;
	minus = flags->minus;
	c = ' ';
	len_nbr = ft_strlen(ft_itoa(i));
	if (flags->zero > 0)
		c = '0';
	if ((flags->plus == 1) && (i >= 0))
	{
		len_nbr++;
		flags->space = 0;
	}
	if (i < 0)
		flags->is_negative = 1;
//	if (flags->minus == 1 && flags->plus == 1)
//		ft_putchar('+');
	if (flags->minus == 1 && flags->zero == 1)
		c = ' ';
	if ((flags->space == 1) && (flags->width == 0) && (i >= 0))
	{
		ft_putchar(' ');
		count_char++;
	}
//	else if ((flags->space == 1) && (flags->width > 0))
//		ft_putchar(' ');
	if ((flags->plus == 1) && (i >= 0) && (flags->width > len_nbr + 1) && (flags->minus == 0) && (flags->zero == 0))
		ft_putchar(' ');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->zero == 0))
		ft_putchar('+');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->zero == 1))
		ft_putchar('+');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 1) && (flags->zero == 0))
		ft_putchar('+');
	else if ((flags->plus == 1) && (i >= 0) && (flags->width > 0) && (flags->minus == 1) && (flags->zero == 1))
		ft_putchar('+');
//	else if ((flags->plus == 0) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->zero == 1))
//		ft_putchar('0');
	else if ((flags->plus == 0) && (i >= 0) && (flags->width > 0) && (flags->minus == 1) && (flags->space == 1)) //&& (flags->zero > 0))
		ft_putchar(' ');
	else if ((flags->plus == 0) && (i >= 0) && (flags->width > 0) && (flags->minus == 0) && (flags->space == 1)) //&& (flags->zero > 0))
		ft_putchar(' ');

//	count_char++;
	else
		count_char --;
	count_char++;
	len_nbr = ft_strlen(ft_itoa(i));
	if (/*(flags->plus == 1) &&*/ (i < 0)/* && (flags->width > len_nbr) */ &&  (flags->zero > 0))
		ft_putchar('-');
	if (flags->minus == 0)
	{
		if ((width > len_nbr)  && (flags->precision < len_nbr))
		{
			if (flags->plus == 1)
				len_nbr-=2;
		count_char += ft_putwidth(c, len_nbr, flags);
		}
		else if ((width > len_nbr) && (flags->precision > len_nbr))
			count_char += ft_putwidth(c, flags->precision, flags);
	}
	if ((flags->plus == 1) && (i >= 0) && (flags->zero == 0))// && (flags->width == 0))
	{
		ft_putchar('+');
		count_char++;
	}
	len_nbr = ft_strlen(ft_itoa(i));
	prec = flags->precision;
//	printf("%d", len_nbr);
/*	if (prec > len_nbr && flags->zero != 0 && flags->zero ==0)
	{
		while (prec > len_nbr)
		{
			ft_putchar('+');
			count_char++;
			prec--;
		}
	}*/
	int prec_len = 0;
	if (prec > len_nbr)
	{
//		if (flags->zero == 1)//
//			ft_putchar');;
		while (prec > len_nbr)
		{
			ft_putchar('0');
			count_char++;
			prec--;
			prec_len++;
		}
		if (flags->zero == 1)
			ft_putchar('0');
	}

/*		
*		if ((flags->space == 1) && (flags->zero == 1))
		{
			ft_putchar(' ');
			len_nbr++;
		}
		while (width > len_nbr)
		{
			width--;
			ft_putchar(c);
		}
		if ((flags->plus == 1) && (i >= 0) && (flags->zero == 0))
		{
			ft_putchar('+');
			len_nbr++;
		}
	}
	if ((flags->space == 1) && (flags->zero == 0))
	{
		ft_putchar(' ');
		len_nbr++;
	}*/
//		if ((flags->plus == 1) && (i >= 0))
//			ft_putchar('+');
	ft_printf_putnbr(i, flags, len_nbr);
	width = flags->width;
	count_char += len_nbr;
	if (minus == 1)
	{
		if ((width > len_nbr))
		{
			count_char += ft_putwidth(c, len_nbr + prec_len, flags);
//			while (width > len_nbr)
//			{
//				--width;
//				ft_putchar(c);
//				count_char++;
//			}
		}
	}
	return (count_char);
}
