# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 16:51:29 by hugsbord          #+#    #+#              #
#    Updated: 2020/02/19 16:22:54 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = ./includes/*.h

NAMELIB = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS =	./srcs/ft_printf.c				\
		./srcs/ft_parser.c				\
		./srcs/ft_parser_utils.c		\
		./srcs/ft_printf_char.c			\
		./srcs/ft_printf_str.c			\
		./srcs/ft_printf_addr.c			\
		./srcs/ft_addr_utils.c			\
		./srcs/ft_printf_int.c			\
		./srcs/ft_int_utils.c			\
		./srcs/ft_printf_hex.c			\
		./srcs/ft_hex_utils.c			\
		./srcs/ft_printf_unsigned_int.c	\
		./srcs/ft_printf_percent.c		\
		./srcs/ft_utils.c				\
		./srcs/ft_utils2.c

OBJ = *.o *SORTED

_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

all: $(NAME)

$(NAMELIB):
	@make -C ./libft
	@cp ./libft/$(NAMELIB) .
	
$(NAME):$(NAMELIB)
	@ar -x libft.a
	@gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(_BOLD)libftprintf.a$(_END) $(_BOLD)$(_GREEN)correctly created$(_END)"

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@rm -f libft.a

fclean: clean
	@make fclean -C libft
	@rm -f *.a

re: fclean all
