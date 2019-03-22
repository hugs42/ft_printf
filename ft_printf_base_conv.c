/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:42:13 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/22 14:17:32 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		conv_ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

void    ft_printf_putnbr(int nb, t_flags *flags)
{
	if (nb == -2147483648)
			ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			if (flags->zero == 0)
				ft_putchar('-');
			nb = -nb;
                }
                if (nb >= 10)
                {
                        ft_putnbr(nb / 10);
                        ft_putnbr(nb % 10);
                }
                else
                        ft_putchar(nb + 48);
        }
}

char	*itoa_base(int value, int base)
{
	int					i;
	char				*str;
	int				tmp;
	
	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}	
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	return (str);
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

int		ft_binary_addition(long binary1, long binary2, t_flags *flags)
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
//	int ww = i;
//	while (ww >= 0)
//		printf("%d", sum[ww--]);
//	ft_putchar('\n');
//	ft_putchar('\n');
//.	printf("%d", sum);
	int k = 0;
	int l = 0;
	int m = 0;
//	printf("\n-i = %d\n", i);
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
/*	i = 0;
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
	ft_putchar('\n');*/
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
//	printf("%s ", total1);
	nbr1 = ft_itoa(bin4[4]);
	nbr2 = ft_itoa(bin3[0]);
	nbr3 = ft_itoa(bin3[1]);
	nbr4 = ft_itoa(bin3[2]);
	total2 = ft_strjoin(nbr4, nbr3);
	total2 = ft_strjoin(total2, nbr2);
	total2 = ft_strjoin(total2, nbr1);
//	printf("%s ", total2);
	nbr1 = ft_itoa(bin3[3]);
	nbr2 = ft_itoa(bin3[4]);
	nbr3 = ft_itoa(bin2[0]);
	nbr4 = ft_itoa(bin2[1]);
	total3 = ft_strjoin(nbr1, nbr2);
	total3 = ft_strjoin(total3, nbr3);
	total3 = ft_strjoin(total3, nbr4);
//	printf("%s ", total3);
	nbr1 = ft_itoa(bin2[2]);
	nbr2 = ft_itoa(bin2[3]);
	nbr3 = ft_itoa(bin2[4]);
	nbr4 = ft_itoa(bin1[0]);
	total4 = ft_strjoin(nbr1, nbr2);
	total4 = ft_strjoin(total4, nbr3);
	total4 = ft_strjoin(total4, nbr4);
//	printf("%s   ", total4);
//	printf("--%s--", nbr3);
//	printf("--%s--", nbr4);
//	ft_putchar('\n');
	char *bin=total1;
	char *bina2 = total2;
	char *bina3 = total3;
	char *bina4 = total4;
	char *a = bin;
	char *bb = bina2;
	char *cc = bina3;
	char *dd = bina4;
	int num = 0;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
//	int num4 = 0;
	int count_char = 0;
	if (flags->capital == 0)
		ft_putstr("ffff");
	else
		ft_putstr("FFFF");
	count_char += 4;
	do {
		int b = *a=='1'?1:0;
		num = (num<<1)|b;
		 a++;
	} 
	while (*a);
	if (flags->capital == 0)
		printf("%x", num);
	else
		printf("%X", num);
	count_char++;
	do {
		int b = *bb=='1'?1:0;
		num1 = (num1<<1)|b;
		 bb++;
	} 
	while (*bb);
	if (flags->capital == 0)
		printf("%x", num1);
	else
		printf("%X", num1);
	count_char++;
	do {
		int b = *cc=='1'?1:0;
		num2 = (num2<<1)|b;
		 cc++;
	} 
	while (*cc);
	if (flags->capital == 0)
		printf("%x", num2);
	else
		printf("%X", num2);
	count_char++;
	do {
		int b = *dd=='1'?1:0;
		num3 = (num3<<1)|b;
		 dd++;
	}
	while (*dd);
	if (flags->capital == 0)
		printf("%x", num3);
	else
		printf("%X", num3);
	count_char++;
//	do {
//		int b = *dd=='1'?1:0;
//		num4 = (num4<<1)|b;
//		 dd++;
//	} 
//	while (*cc);
//		printf("%X\n", num1);

//	int final_hex1;
//	int final_hex2;
//	int final_hex3;
//	int final_hex4;
//	printf("--%d\n", ft_bin_to_hex(ft_atoi(total1)));
//	ft_bin_to_hex(ft_atoi(total2));
//	ft_bin_to_hex(ft_atoi(total3));
//	ft_bin_to_hex(ft_atoi(total4));

//	ft_bin_to_hex(nombre);
	return (count_char);
}
/*
char                    *ft_itoa_zero_startes(int n)
{
        char                    *str;
        size_t                  len;
        unsigned int    n_tmp;
		int start_by_zero;

        len = ft_str_len(n);
        n_tmp = n;
		int start_by_zero
        if (n < 0)
        {
                n_tmp = -n;
                len++;
        }
        if (!(str = ft_strnew(len)))
                return (NULL);
        str[--len] = n_tmp % 10 + '0';
        while (n_tmp /= 10)
                str[--len] = n_tmp % 10 + '0';
        if (n < 0)
                *(str + 0) = '-';
        return (str);
}
*/
int		ft_bin_to_hex(int nbr)
{
	int i;
//	char res[100];
//	char *base_low = "0123456789abcdef";
//	char *base_upp = "0123456789ABCDEF";
	i = 1;
	int hexa = 0;
	int remainder = 1;
//	if (nbr == 0)
//	{
//		ft_putchar('0');
//		return (1);
//	}
	while (nbr > 0)
	{
		remainder = nbr % 10;
		hexa = hexa + remainder * i;
		i = i * 2;
		nbr = nbr / 10;
	}
//		while (res[i] != '\0')
//	res[i] = '\0';
//	printf("%d --res--", hexa);
//	ft_putstrrev(res);
	return (1);
}

void		ft_swap_char(char a, char b)
{
	char tmp;

	tmp = a;
	a = b;
	b = tmp;
}
char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos){
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }

    return str;
}
char		*ft_reverse_bin(char *str, char *str_new)
{
	int i;
	int j;
	char *str2;

	i = 0;
	j = 0;
 //   printf("LL%sLL\n", str);  
	str2 = ft_strnew(ft_strlen(str + 1));
	str2 = ft_strcpy(str2, str);
	str2 = replace_char(str, '0', 'l');
	str2 = replace_char(str, '1', '0');
	str2 = replace_char(str, 'l', '1');
   // printf("UU%sUU\n", str2);  // He11o wor1d!
//    return 0;
/*	while (str[i] != '\0')
	{
		if (ft_strchr(str[i] == '0')
		{
			str2[j] = '1';
			j++;
		}
		else if (str[i] == '1')
		{
			str2[j] = '0';
			j++;
		}
		else
			return ("ERROR");
		i++;
	}
	str2[j] = '\0';
//	printf("aa%saa", str2);*/
	return (str2);
}

int				ft_printf_negative_hex(int nbr, t_flags *flags)
{
	int count_char = 0;
//	int pos;
	char *base_2 = "01";
	char res[100];
	char *str;
//	char binaire[12] = "111111111111";
	char new[32];
	char *new2 = NULL;
	char *new3;
//	char bin1[4];
//	char bin2[4];
//	char bin3[4];
//	char bin4[5];
	int i = 0;
	int j = 16;
	int k = 0;
	int bin;
//	int len = 0;
	long l_bin = 00000000000000000000000000000001;
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
//	char new_str[ft_strlen(res + 1)];
	if (ft_strlen(res) < 16)
	{
		str = ft_strrev(res);
//		printf("--%s-- ", str);
//		printf("==%s==",str);
		k--;
		j--;
		while (str[i] != '\0')
		{
			new[j] = str[k];
			i++;
			k--;
			j--;
		}
//		printf("$$%s$$",str);
		new2 = ft_reverse_bin(str, new2);
//		printf("GG%sGG",new2);
		int diff = 16 - ft_strlen(new2);
//		printf("%d\n", diff);
		new3 = ft_strnew(diff);
		i = 0;
		if (diff > 0)
		{
			while (diff > 0)
			{
				new3[i++] = '1';
				diff--;
			}
		}
	}
//	printf("-*-%s-*-\n", new3);
	new3 = ft_strjoin(new3, new2);
//	printf("-*-%s-*-\n", new3);
//	printf("--%ld--\n",ft_atoi_long(new3));
//	printf("%ld\n", ft_atoi_long("+0000000000000001"));
	count_char += ft_binary_addition(ft_atoi_long(new3), l_bin, flags);
//	ft_strjoin(binaire, ft_strrev(res));
//	printf("%s\n", new);
	return (count_char);
}

int				ft_printf_hex(const char *format, va_list arg, char c, t_flags *flags)
{
	int i;
	int sh = 0;
	int count_char = 0;
	int nbr;
	char res[100];
	int prec = flags->precision;
	int prec_len = 0;
	char *base_low = "0123456789abcdef";
	char *base_upp = "0123456789ABCDEF";
	char w = ' ';
	if (flags->zero == 1)
		w = '0';
	i = 0;
	if (flags->sharp == 1)
	{
		sh = 2;
		count_char+=2;
	}
	nbr = va_arg(arg, int);
	if (nbr == 0 && flags->is_precision == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (c == 'x')
	{
	flags->capital = 0;
		if (nbr > 0)
		{
			while (nbr > 0)
			{
				res[i] = base_low[nbr % 16];
				nbr /= 16;
				i++;
			}
			res[i] = '\0';
//		ft_putstrrev(res);
		}
		else
		{
			count_char = ft_printf_negative_hex(nbr, flags);
		}
	}
	else if (c == 'X')
	{
	flags->capital = 1;
		if (nbr > 0)
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
		else
		{
			count_char += ft_printf_negative_hex(nbr, flags);
		}
	}
	ft_strrev(res);
	if (flags->sharp == 1 && flags->zero == 1)
	{
		if (flags->capital == 1)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
	if (flags->minus == 0)
	{
		if (flags->width > ft_strlen(res) && flags->precision <= ft_strlen(res))
			count_char += ft_putwidth(w, ft_strlen(res) + sh, flags);

	}
	if (flags->sharp == 1 && flags->zero == 0)
	{
		if (flags->capital == 1)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
	if (prec > ft_strlen(res))
	{
		while (prec > ft_strlen(res))
		{
			ft_putchar('0');
			prec--;
			prec_len++;
			count_char++;
		}
	}
	ft_putstr(ft_strrev(res));
	if (flags->minus == 1)
	{
		if (flags->width > ft_strlen(res))
			count_char += ft_putwidth(w, ft_strlen(res) + sh + prec_len, flags);
	}
	count_char += ft_strlen(res);
//	if (nbr > 0 && flags->width == 0)
//		return (ft_strlen(res));
	return (count_char);
}
