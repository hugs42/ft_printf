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

typedef struct			s_printf
{
						int len;
						int precision;
						char *format;
}						t_printf;

#endif