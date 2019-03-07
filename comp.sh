FLAGS='-Wall -Wextra'

if [ "$1" = 'fclean' ]
then
	rm test_printf.exe
	make fclean
	echo 'All Clean'
else
	make all
	gcc $FLAGS main.c -L . -lprintf -o test_printf.exe
	echo 'exec ready'
fi
