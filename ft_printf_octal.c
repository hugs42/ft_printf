/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:34:33 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/22 13:45:39 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_octal(const char *format, va_list arg, t_flags *flags)
{
		int i;
		int sh = 0;
		int nbr;
		int count_char = 0;
		char res[100];
		char *base = "01234567";
		char w = ' ';
		if (flags->zero == 1)
			w = '0';
		i = 0;
		nbr = va_arg(arg, int);
		while (nbr > 0)
		{
				res[i] = base[nbr % 8];
				nbr /= 8;
				i++;
				count_char++;
		}
		res[i] = '\0';
		if (flags->minus == 0)
		{
			if (flags->width > ft_strlen(res))
				count_char+= ft_putwidth(w, ft_strlen(res) +  sh, flags);
		}
		ft_putstr(ft_strrev(res));
		if (flags->minus == 1)
		{
			if (flags->width > ft_strlen(res))
				count_char+= ft_putwidth(w, ft_strlen(res) +  sh, flags);
		}
		return (count_char);
}

