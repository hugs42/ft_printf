/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:49:53 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/07 16:49:49 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	size_t				len;
	size_t				len_min;
	int					precision;
	char				*format;
	int					l;
	int					ll;
	int					h;
	int					hh;
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
int		ft_putzero_adress(char c, int len);

#endif
