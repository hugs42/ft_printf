/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:03:21 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/26 17:27:54 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
//	ft_atoi_base(42);
//	ft_printf("ii %s ii",  NULL);
//
//	ft_putchar('\n');
//	printf("ii %s ii", NULL);
//	ft_printf("%10.5d",  -42);

//	ft_putchar('\n');
//	printf("%10.5d", -42);
//	ft_putchar('\n');

	ft_printf("%0+5d", 42);

	ft_putchar('\n');
	printf("%0+5d", 42);

//	printf("%10s", "test");
	return (0);
}
