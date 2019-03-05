# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 21:46:51 by hugsbord          #+#    #+#              #
#    Updated: 2019/03/05 11:48:54 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror -I ./$(DIRLIB)

SRC	=	ft_printf.c \
		main.c

LIB	=	libft.a
DIRLIB	=	libft/

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -C $(DIRLIB)
		@gcc -o $(NAME) $(OBJ) $(DIRLIB)$(LIB)
		@echo "ft_printf correctly compiled ... OK"

clean:
		@rm -f $(OBJ)
		@make -C $(DIRLIB) clean
		@echo "Objects removed"

fclean:		clean
		@rm -f $(NAME)
		@make -C $(DIRLIB) fclean
		@echo "$(NAME) removed"

re:		fclean all

.PHONY:		all clean fclean re
