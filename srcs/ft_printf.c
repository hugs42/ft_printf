/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:11:20 by hugsbord          #+#    #+#             */
/*   Updated: 2020/02/17 16:58:33 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int		ft_check_type(t_flags1 *f1)
{
	int j;

	j = f1->i;
	while (f1->src[j] != '\0')
	{
		if (ft_is_type(f1->src[j]))
			return (1);
		j++;
	}
	return (0);
}

int		ft_space_undefined_behavior(const char *format, t_flags1 *f1)
{
	int i;
	int j;

	i = f1->i;
	j = 0;
	if (format[i] != ' ')
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] != ' ')
			j = 1;
		i++;
	}
	if (j == 1)
		while (format[f1->i] == ' ')
			f1->i++;
	else
		return (1);
	return (0);
}

void	ft_formatloop(const char *format, va_list *list, t_flags1 *f1)
{
	t_flags2 *f2;

	while (format[f1->i] != '\0')
	{
		f1->type = 0;
		if (f1->i != 0 && format[f1->i - 1] == '%')
		{
			if (!(f2 = (t_flags2*)malloc(sizeof(t_flags2))))
				break ;
			if (ft_parser(list, f1, f2) != -1)
				free(f2);
			else if (ft_space_undefined_behavior(format, f1) == 1)
				break ;
		}
		if (format[f1->i] != '%' && (f1->type == 0 || f1->type == 10))
		{
			if (f1->type == 10 && (f1->src[f1->i] == '\0' ||
						f1->src[f1->i] == '\0'))
				break ;
			else
				ft_putchar_fd(format[f1->i], FD);
			f1->nb_char++;
		}
		f1->i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list			list;
	t_flags1		*f1;

	va_start(list, format);
	if ((ft_strlen(format) == 1 && format[0] == '%') || (!format[0]))
		return (0);
	f1 = ft_init_flags1();
	f1->src = ft_strdup(format);
	ft_formatloop(format, &list, f1);
	free(f1->src);
	free(f1);
	va_end(list);
	return (f1->nb_char);
}
