/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:03:21 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/12 19:01:42 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int             main(int argc, char **argv)
{
//        int i = 11;
        int j = 1234567;
        int k = 42;
		int l =  2035065302;
		float  m = 13223.3622;
        float fl = 42.15;
        unsigned int ui = 1849494;
//      char nb  = '7';
//		char c = 'X';
        char nb1 = '6';
//      char nb2 = '9';
        char *str = "abc";
        char *str2 = "groove";
        argv = NULL;
        argc = 2;

//      ft_printf("ft_printf\t::%c::%5s::%p::%+d::%i::%o::%u::%x::%X::%%::%f::%+d::\\\\", nb1, str, str2, i, j, i, ui);
//      printf("printf  \t::%c::%5s::%p::%+d::%i::%o::%u::%x::%X::%%::%f::%+d::\\\\", nb1, str, str2, i, j, i, ui);
//		ft_putchar('\n');
//	 ft_printf("ft_printf = ::%4p::%+d::%7f::%- .c::",str2, k,m,c);
//	ft_putchar('\n');
//	printf("printf    = ::%4p::%+d::%7f::%- .c::",str2, k, m,c );

	char c = 'c';
	char *s = "groove";
	char *p = "p";
	int d = 213;
	int i = 1043666;
	int o = 42;
	unsigned int u = 321;
	int x = 888;
	int x2 = 55;
	ft_printf("ft_printf = ::%-+c::%-13s::%+0-013.4p::%+03d::%+06i::::%u::%x::%X::", c, s, p, d, i, u, x, x2);
	ft_putchar('\n');
	printf("printf    = ::%-+.c::%-13s::%+0-013.4p::%+03d::%+06i::::%u::%x::%X::", c, s, p, d, i, u, x, x2);
		return (0);
}
