# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 12:18:47 by hugsbord          #+#    #+#              #
#    Updated: 2019/03/07 17:40:55 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = #-Wall -Wextra #-Werror

HEADER = libft/libft.h ft_printf.h

INC_PATH = libft/

INCLUDE =  $(HEADER)

CPPFLAGS = -I $(INCLUDE)

NAME = libprintf.a

SRC_PATH = libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_LIBFT)) $(SRC_PRINTF)

SRC_LIBFT =	ft_atoi.c	\
			ft_bzero.c	\
			ft_toupper.c\
			ft_tolower.c\
			ft_swap.c	\
			ft_strtrim.c\
			ft_strsub.c	\
			ft_strstr.c	\
			ft_strsplit.c\
			ft_strrchr.c\
			ft_strnstr.c\
			ft_strnew.c	\
			ft_strnequ.c\
			ft_strndup.c\
			ft_strncpy.c\
			ft_strncmp.c\
			ft_strncat.c\
			ft_strmapi.c\
			ft_strmap.c	\
			ft_strlen.c	\
			ft_strlcat.c\
			ft_strjoin.c\
			ft_striteri.c\
			ft_striter.c\
			ft_strequ.c	\
			ft_strdup.c	\
			ft_strdel.c	\
			ft_strcpy.c	\
			ft_strcmp.c	\
			ft_strclr.c	\
			ft_strchr.c	\
			ft_strcat.c	\
			ft_putstr.c	\
			ft_putstr_fd.c\
			ft_putnbr.c	\
			ft_putnbr_fd.c	\
			ft_putendl.c\
			ft_putendl_fd.c	\
			ft_putchar.c\
			ft_putchar_fd.c	\
			ft_memset.c	\
			ft_memmove.c	\
			ft_memdel.c	\
			ft_memcpy.c	\
			ft_memcmp.c	\
			ft_memchr.c	\
			ft_memccpy.c	\
			ft_memalloc.c	\
			ft_lstnew.c	\
			ft_lstmap.c	\
			ft_lstiter.c	\
			ft_lstdelone.c	\
			ft_lstdel.c	\
			ft_lstadd.c	\
			ft_itoa.c	\
			ft_isprint.c	\
			ft_isdigit.c	\
			ft_isascii.c	\
			ft_isalpha.c	\
			ft_isalnum.c	\
			ft_isspace.c	\
			ft_islower.c	\
			ft_isupper.c \

SRC_PRINTF = ft_formating.c \
			ft_printf_nbr.c \
			ft_utils.c \
			ft_printf.c \
			ft_printf_base_conv.c \
			ft_printf_precision.c \
			ft_printf_csp.c \
			ft_printf_type_conversion.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "libft creation :"
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created ..."
	@ranlib $(NAME)
	@echo "$(NAME) correctly indexed"

$(OBJ) : $(INCLUDE)

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ (.o) removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all, clean, fclean, re
