/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:20:34 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/19 13:14:31 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "./../libft/libft.h"

# define FD						1
# define TYPES_C				"cspdiuxX%"
# define TYPES_WITHOUT_P		"cspdiuxX"
# define FLAGS_C				"-.*0"
# define ALL_FLAGS				"-.*0123456789"
# define ALL_C					"cspdiuxX%-.*0123456789"
# define BASE					"0123456789abcdef"
# define BASE_UP				"0123456789ABCDEF"

typedef struct		s_flags1
{
	char			*src;
	int				i;
	int				index;
	unsigned int	nb_char;
	unsigned int	type;
	int				widlcard;
	int				tmp;
}					t_flags1;

typedef struct		s_flags2
{
	char			*src;
	int				i;
	int				nbr;
	unsigned int	u_nbr;
	unsigned int	nb_char;
	unsigned int	type;
	int				width;
	int				n_width;
	int				prec;
	int				is_prec;
	int				minus;
	int				minus_tmp;
	int				zero;
	int				len;
	char			space;
	char			*hex;
	int				hex_up;
	int				len_nbr;
	int				is_n;
	int				tmp;
	int				tmp2;
	int				tmp3;
	unsigned long	addr;
	int				wildcard;
}					t_flags2;

int					ft_printf(const char *format, ...);
int					ft_parser(va_list *list, t_flags1 *f1, t_flags2 *f2);
int					ft_printf_char(va_list *list, t_flags2 *f2);
int					ft_printf_str(va_list *list, t_flags2 *f2);
int					ft_printf_int(va_list *list, t_flags2 *f2);
int					ft_printf_addr(va_list *list, t_flags2 *f2);
int					ft_printf_hex(va_list *list, t_flags2 *f2);
int					ft_printf_uns(va_list *list, t_flags2 *f2);
t_flags1			*ft_init_flags1();
void				ft_init_flags2(t_flags2 *flags2);
int					ft_get_width(int i, t_flags1 *f1, t_flags2 *f2);
int					ft_set_flags(int i, t_flags1 *f1, t_flags2 *f2);
int					ft_get_precision(int i, t_flags1 *f1, t_flags2 *f2);
int					ft_putwidth(char c, int len, t_flags2 *flags2);
char				*ft_itoa_base(int nbr, int base);
int					ft_printf_percent(va_list *list, t_flags2 *f2);
void				ft_is_minus_hex(int size, t_flags2 *f2);
void				ft_no_minus_hex(int size, t_flags2 *f2);
unsigned int		ft_hex_len(int nbr);
unsigned int		ft_abs(int i);
int					ft_add_zero_hex(int nbr, int size, t_flags2 *f2);
int					ft_is_flags(char c);
int					ft_is_type(char c);
int					ft_check_char(int c);
void				ft_display_addr(int i, char *res, t_flags2 *f2);
void				ft_putnbr_printf(int nb, t_flags2 *f2);
int					ft_hex_conv_ifzero(t_flags2 *f2);
int					ft_check_type(t_flags1 *f1);
int					ft_parse_wildcard(int i, va_list *list, t_flags1 *f1,
		t_flags2 *f2);
int					ft_is_minus_addr(t_flags2 *f2);
int					ft_no_minus_addr(t_flags2 *f2);

#endif
