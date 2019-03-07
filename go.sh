FLAGS=''

if [ "$1" = 'fclean' ]
then
	rm printf.exe
	make fclean
	echo 'All Clean'
else
	make all
	gcc $FLAGS main.c -L . -lprintf -o printf.exe
	make clean
	echo 'exec ready'
fi
