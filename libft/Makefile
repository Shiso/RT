# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:42:53 by tdeniset          #+#    #+#              #
#    Updated: 2014/03/26 20:13:06 by tdeniset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Werror -Wextra
CC=gcc
NAME=libft.a
HEAD=libft.h
FILES=src/ft_memset.c \
	src/ft_bzero.c \
	src/ft_memcpy.c \
	src/ft_memccpy.c \
	src/ft_memmove.c \
	src/ft_memchr.c \
	src/ft_memcmp.c \
	src/ft_strlen.c \
	src/ft_strdup.c \
	src/ft_strcpy.c \
	src/ft_strncpy.c \
	src/ft_strcat.c \
	src/ft_strncat.c \
	src/ft_strlcat.c \
	src/ft_strchr.c \
	src/ft_strrchr.c \
	src/ft_strstr.c \
	src/ft_strnstr.c \
	src/ft_strcmp.c \
	src/ft_strncmp.c \
	src/ft_atoi.c \
	src/ft_isalpha.c \
	src/ft_isdigit.c \
	src/ft_isalnum.c \
	src/ft_isascii.c \
	src/ft_isprint.c \
	src/ft_toupper.c \
	src/ft_tolower.c \
	src/ft_memalloc.c \
	src/ft_memdel.c \
	src/ft_strnew.c \
	src/ft_strdel.c \
	src/ft_strclr.c \
	src/ft_striter.c \
	src/ft_striteri.c \
	src/ft_strmap.c \
	src/ft_strmapi.c \
	src/ft_strequ.c \
	src/ft_strnequ.c \
	src/ft_strsub.c \
	src/ft_strjoin.c \
	src/ft_strnjoin.c \
	src/ft_strjoinc.c \
	src/ft_strtrim.c \
	src/ft_strsplit.c \
	src/ft_itoa.c \
	src/ft_putstr.c \
	src/ft_putchar.c \
	src/ft_putnbr.c \
	src/ft_putendl.c \
	src/ft_putchar_fd.c \
	src/ft_putstr_fd.c \
	src/ft_putnbr_fd.c \
	src/ft_putendl_fd.c \
	src/get_next_line.c

OBJ=$(FILES:.c=.o)

%.o: %.c
	@gcc -o $@ -c $^ -I includes/ $(CFLAG)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	rm -rf libft.a

re: fclean all

.PHONY: all $(NAME) re clean fclean
