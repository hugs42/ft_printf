#include "ft_printf.h"
#include <stdio.h>
 
int		main(int argc, char **argv)
{
	int i = 19;
	int j = 123;
	int k = 42;
	float fl = 42.15;
	unsigned int ui = 1849494;
//	char nb  = '7';
	char nb1 = '6';
//	char nb2 = '9';
	char *str = "abc";
	char *str2 = "groove";
	argv = NULL;
	argc = 2;

	ft_printf("ft_printf\t::%c::%5s::%p::%+d::%i::%o::%u::%x::%X::%%::%f::%+d::\\\\", nb1, str, str2, i, j, i,ui,j, j,fl, k);
	printf("printf  \t::%c::%5s::%p::%+d::%i::%o::%u::%x::%X::%%::%f::%+d::\\\\", nb1, str, str2, i, j,i, ui, j,j, fl, k);
	ft_putchar('\n');
	return (0);
}
