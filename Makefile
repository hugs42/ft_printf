# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 10:43:03 by hugsbord          #+#    #+#              #
#    Updated: 2019/03/06 10:50:22 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	=	libftprintf.a

CFLAGS	=	-I ./$(DIRLIB)

SRC	=	ft_printf.c \
		ft_printf_csp.c \
		ft_printf_nbr.c \
		ft_printf_base_conv.c \
		ft_printf_type_conversion.c \
		ft_utils.c

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
