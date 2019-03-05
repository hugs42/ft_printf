/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:49:53 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/05 16:03:35 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define BLUE			"\033[34m"
# define YELLOW			"\033[33m"
# define GREEN			"\033[32m"
# define RED			"\033[31m"

# define SUCCESS		(1)
# define ERROR			(-1)
# define FINISH			(0)

int		ft_printf(const char *format, ...);
int		ft_printf_parse(const char *format, va_list arg);
int		ft_printf_char(const char *format,va_list arg);
int		ft_printf_str(const char *format,va_list arg);
int		ft_printf_int(const char *format,va_list arg);
int		ft_printf_addr(const char *format,va_list arg);
int		ft_printf_octal(const char *format,va_list arg);
int		ft_printf_hex(const char *format,va_list arg, char c);
int		ft_printf_unsigned_int(const char *format,va_list arg);
int		ft_putstrrev(char *str);

typedef struct			s_printf
{
						int len;
						int precision;
						char *format;
}						t_printf;

#endif
