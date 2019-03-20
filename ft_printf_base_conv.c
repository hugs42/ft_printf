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

int    *ft_intcpy(int *dest, const int *src, size_t n)
{
        unsigned int i;

        i = 0;
        while (src[i] != '\0' && i < n)
        {
                dest[i] = src[i];
                i++;
        }
        while (i < n)
        {
                dest[i] = '\0';
                i++;
        }
        return (dest);
}

int    *ft_intsub(int const *hexa, unsigned int start, int len)
{
        unsigned int    i;
        int              *tab;
        unsigned int    end;

        i = 0;
        end = start + len;
        if (!hexa)
                return (NULL);
        else if ((tab = (int *)malloc(len + 1)) && end != 0)
        {
                while (start < end)
                        tab[i++] = hexa[start++];
                tab[i] = '\0';
        }
        return (tab);
}

int				**ft_add(int const *hexa, int **tab)
{
		size_t			i;
		size_t			start;
		size_t			index;

		index = 0;
		i = 0;
		while (hexa[i])
		{
				if (i % 4 == 0)
				{
					i++;
					start = i;
					while (hexa[i] && i % 4 != 0)
						i++;
					tab[index] = ft_intsub(hexa, start, i - start);
					index++;
					tab[index] = NULL;
				}
		}
		tab[index] = 0;
		return (tab);
}

int				**ft_split_hexa(const int *hexa)
{
	int		**tab;
	if (hexa == NULL)
		return (NULL);
	if (!(tab = (int**)malloc(sizeof(int*) * 4 + 1)))
		return (NULL);
	ft_bzero(tab, 4 + 1);
	return (ft_add(hexa, tab));
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
	int i = 0;
	int j = 0;
	int remainder = 0; 
	int sum[20];
	int bin1[5];
	int bin2[5];
	int bin3[5];
	int bin4[5];

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
	int ww = i;
	while (ww >= 0)
		printf("%d", sum[ww--]);
	ft_putchar('\n');
//	ft_putchar('\n');
//.	printf("%d", sum);
	int k = 0;
	int l = 0;
	int m = 0;
	printf("\n-i = %d\n", i);
	while (i >= 0)
	{
//		if (i % 4 == 0)
//		{
//		ft_intcpy(bin4, sum, 4);
		while (j <= 4)
			bin4[j++] = sum[i--];
//		if (j == 4)
//			bin4[j + 1] = '\0';
		while (k <= 4)
			bin3[k++] = sum[i--];
		while (l <= 4)
			bin2[l++] = sum[i--];
		while (m <= 4)
			bin1[m++] = sum[i--];
//		bin3[k++] = sum[i--];
//		bin2[l++] = sum[i--];
//		bin1[m++] = sum[i--];
//		}
//			bin4[j++] == sum[i--];
//		printf("%d", sum[i--]);
//	}
//	i--;
	}
//	for( int i = 0; i < 5; ++i )
//		printf( "%d", bin4[ i ] );
	i = 0;
	while (i <= 4)
		ft_putnbr(bin4[ i++]);
//	ft_putchar(' ');
	i = 0;
	while (i <= 4)
		ft_putnbr(bin3[ i++]);
//	ft_putchar(' ');
	i = 0;
	while (i <= 4)
		ft_putnbr(bin2[ i++]);
	i = 0;
	while (i < 1)
		ft_putnbr(bin1[ i++]);
	ft_putchar('\n');
	i = 0;
	char *nbr4;
	char *nbr3;
	char *nbr2;
	char *nbr1;
	char *total1;
	char *total2;
	char *total3;
	char *total4;
	nbr1 = ft_itoa(bin4[0]);
	nbr2 = ft_itoa(bin4[1]);
	nbr3 = ft_itoa(bin4[2]);
	nbr4 = ft_itoa(bin4[3]);
	total1 = ft_strjoin(nbr4, nbr3);
	total1 = ft_strjoin(total1, nbr2);
	total1 = ft_strjoin(total1, nbr1);
	printf("%s ", total1);
	nbr1 = ft_itoa(bin4[4]);
	nbr2 = ft_itoa(bin3[0]);
	nbr3 = ft_itoa(bin3[1]);
	nbr4 = ft_itoa(bin3[2]);
	total2 = ft_strjoin(nbr4, nbr3);
	total2 = ft_strjoin(total2, nbr2);
	total2 = ft_strjoin(total2, nbr1);
	printf("%s ", total2);
	nbr1 = ft_itoa(bin3[3]);
	nbr2 = ft_itoa(bin3[4]);
	nbr3 = ft_itoa(bin2[0]);
	nbr4 = ft_itoa(bin2[1]);
	total3 = ft_strjoin(nbr4, nbr3);
	total3 = ft_strjoin(total3, nbr2);
	total3 = ft_strjoin(total3, nbr1);
	printf("%s ", total3);
	nbr1 = ft_itoa(bin2[2]);
	nbr2 = ft_itoa(bin2[3]);
	nbr3 = ft_itoa(bin2[4]);
	nbr4 = ft_itoa(bin1[0]);
	total4 = ft_strjoin(nbr4, nbr3);
	total4 = ft_strjoin(total4, nbr2);
	total4 = ft_strjoin(total4, nbr1);
	printf("%s   ", total4);
//	printf("--%s--", nbr3);
//	printf("--%s--", nbr4);
	ft_putchar('\n');

//	ft_bin_to_hex(nombre);
	return (0);
}


int		ft_bin_to_hex(int nbr)
{
	int i;
	char res[100];
	char *base_low = "0123456789abcdef";
	char *base_upp = "0123456789ABCDEF";
	i = 0;
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (nbr > 0)
	{
		res[i] = base_low[nbr % 16];
		nbr /= 16;
		i++;
	}
//		while (res[i] != '\0')
	res[i] = '\0';
	ft_putstrrev(res);
	return (1);
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
//	printf("%ld\n",ft_atoi_long(new));
//	printf("%ld\n", ft_atoi_long("+0000000000000001"));
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
