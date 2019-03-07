/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:03:21 by hugsbord          #+#    #+#             */
/*   Updated: 2019/03/07 17:19:11 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int             main(int argc, char **argv)
{
        int i = 10;
        int j = 123;
        int k = 42;
        float fl = 42.15;
        unsigned int ui = 1849494;
//      char nb  = '7';
        char nb1 = '6';
//      char nb2 = '9';
        char *str = "abc";
        char *str2 = "groove";
        argv = NULL;
        argc = 2;

//      ft_printf("ft_printf\t::%c::%5s::%p::%+d::%i::%o::%u::%x::%X::%%::%f::%+d::\\\\", nb1, str, str2, i, j, i,u$
//      printf("printf  \t::%c::%5s::%p::%+d::%0000i::%o::%u::%x::%X::%%::%f::%+d::\\\\", nb1, str, str2, i, j,i, u$
//      ft_putchar('\n');
        ft_printf("ft_printf = ::%+55d::", i);
        ft_putchar('\n');
        printf("printf    = ::%+55d::", i);
        return (0);
}
