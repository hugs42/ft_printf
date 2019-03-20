/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:42:13 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/06 18:45:05 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_octal(const char *format, va_list arg, t_flags *flags)
{
	int i;
	int nbr;
	char *res = NULL;
	char *base = "01234567";
	i = 0;
	nbr = va_arg(arg, int);
	while (nbr > 0)
	{
		res[i] = base[nbr % 8];
		nbr /= 8;
		i++;
	}
	res[i] = '\0';
	ft_putstrrev(res);
	return (SUCCESS);
}

long			ft_atoi_long(const char *str)
{
		int				i;
		int				sign;
		long			result;

		i = 0;
		result = 0;
		sign = 1;
		while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
				i++;
		if (str[i] == '+' || str[i] == '-')
		{
				if (str[i] == '-')
						sign = -1;
				i++;
		}
		while (ft_isdigit(str[i]))
		{
			result = result * 10 + str[i] - 48;
			i++;
		}
		result *= sign;
		return (result);
}

int		ft_binary_addition(long binary1, long binary2)
{
//    long binary1, binary2;
	int i = 0, remainder = 0, sum[20];

	while (binary1 != 0 || binary2 != 0)
	{
		sum[i++] =(binary1 % 10 + binary2 % 10 + remainder) % 2;
		remainder =(binary1 % 10 + binary2 % 10 + remainder) / 2;
		binary1 = binary1 / 10;
		binary2 = binary2 / 10;
	}
	if (remainder != 0)
		sum[i++] = remainder;
	--i;
	while (i >= 0)
		printf("%d", sum[i--]);
	 return 0;
}

int				ft_printf_negative_hex(int nbr)
{
	int count_char;
	int pos;
	char *base_2 = "01";
	char res[100];
	char *str;
	char binaire[12] = "111111111111";
	char new[16];
	char bin1[4];
	char bin2[4];
	char bin3[4];
	char bin4[5];
	int i = 0;
	int j = 16;
	int k = 0;
	int bin;
	int len = 0;
	long l_bin = 0000000000000001;
	bin = 0;
	nbr -= (nbr * 2);
	while (nbr > 0)
	{
		res[i] = base_2[nbr % 2];
		nbr /= 2;
		i++;
	}
	res[i] = '\0';
	i = 0;
	k = ft_strlen(res);
	str = malloc(sizeof(char) * k + 1);
	if (ft_strlen(res) < 16)
	{
		str = res;
		while (str[i] != '\0')
		{
			new[j] = str[k];
			i++;
			k--;
			j--;
		}
		while (new[j] >= 0)
		{
			new[j] = '1';
			j--;
		}
		
	}
	printf("%ld\n",ft_atoi_long(new));
	printf("%ld\n", ft_atoi_long("+0000000000000001"));
	ft_binary_addition(ft_atoi_long(new), l_bin);
//	ft_strjoin(binaire, ft_strrev(res));
//	printf("%s\n", new);
	return (count_char);
}

int				ft_printf_hex(const char *format, va_list arg, char c, t_flags *flags)
{
	int i;
	int nbr;
	char res[100];
	char *base_low = "0123456789abcdef";
	char *base_upp = "0123456789ABCDEF";
	i = 0;
	nbr = va_arg(arg, int);
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (c == 'x')
	{
		if (nbr > 0)
		{
			while (nbr > 0)
			{
				res[i] = base_low[nbr % 16];
				nbr /= 16;
				i++;
			}
//		while (res[i] != '\0')
			res[i] = '\0';
//		ft_putstrrev(res);
		}
		else
		{
			ft_printf_negative_hex(nbr);
		}
	}
	else if (c == 'X')
	{
		while (nbr > 0)
		{
			res[i] = base_upp[nbr % 16];
			nbr /= 16;
			i++;
		}
//		while (res[i] != '\0')
		res[i++] = '\0';
//		ft_putstrrev(res);
	}
	ft_strrev(res);
	ft_putstr(ft_strrev(res));
	return (ft_strlen(res));
}
