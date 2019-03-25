/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:49:53 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/22 15:59:00 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define BLUE			"\033[34m"
# define YELLOW			"\033[33m"
# define GREEN			"\033[32m"
# define RED			"\033[31m"

# define SUCCESS		(1)
# define ERROR			(-1)
# define FINISH			(0)

typedef struct			s_flags
{
	char				flag;
	int					sharp;
	int					zero;
	int					minus;
	int					plus;
	int					space;
	int					width;
	int					len;
	int					len_min;
	int					is_precision;
	int					precision;
	int					is_negative;
	char				*format;
	int					l;
	int					ll;
	int					h;
	int					hh;
	int					capital;
//	static int			count_char;
}						t_flags;



int		ft_printf(const char *format, ...);
int		ft_printf_parse(const char *format, va_list arg);
int		ft_printf_char(const char *format,va_list arg, t_flags *flags);
int		ft_printf_str(const char *format,va_list arg, t_flags *flags);
int		ft_printf_int(const char *format,va_list arg, t_flags *flags);
int		ft_printf_addr(const char *format,va_list arg, t_flags *flags);
int		ft_printf_octal(const char *format,va_list arg, t_flags *flags);
int		ft_printf_hex(const char *format,va_list arg, char c, t_flags *flags);
int		ft_printf_unsigned_int(const char *format,va_list arg, t_flags *flags);
int		ft_printf_double(const char *format, va_list arg, t_flags *flags);
int		ft_printf_long_double(const char *format, va_list arg, t_flags *flags);
int		ft_printf_csp_case(const char *format, va_list arg, int i, t_flags *flags);
int		ft_printf_diouxx_case(const char *format, va_list arg, int i, t_flags *flags);
int		ft_is_diouxx(const char *format, va_list arg, int i);
int		ft_printf_type_conversion(const char *format, va_list arg, int i);
int		ft_init_flags_struct(t_flags *flags);
int		ft_get_width(const char *format, int i);
int		ft_isflag(const char *format, int i);
int		ft_set_flags(const char *format,int i,t_flags *flags);
int		ft_get_precision(const char *format, int i);
char	*cut_left(char *str, int i);
char	*cut_right(char *str, int i);
int		ft_putstrrev(char *str);
int		ft_putnstr(char *str, int n);
int		ft_putwidth(char c, int len, t_flags *flags);
int		ft_set_specifier(const char *format, int i, t_flags *flags);
char	*ft_itoa_double(int n);
size_t	ft_str_len(double n);
char	*ft_itoai_doule(int n);
int		ft_putzero_adress(int len);
char	*ft_strrev(char *str);
int		ft_putwidth_by_prec(char c, int len, t_flags *flags);
int		ft_printf_negative_hex(int nbr, t_flags *flags);
int		ft_binary_addition(long bin_1, long bin_2, t_flags *flags);
long	ft_atoi_long(const char *str);
int		*ft_intsub(const int *hexa, unsigned int start, int len);
int		**ft_add(const int *hexa, int **tab);
int		**ft_split_hexa(const int *hexa);
int		*ft_intcpy(int *dest, const int *src, size_t n);
int		ft_bin_to_hex(int nbr);
void	ft_printf_putnbr(int nbr, t_flags *flags, int len);
int		ft_printf_str_null(const char *format, va_list arg, t_flags *flags);

#endif
