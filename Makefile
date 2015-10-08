# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/26 21:28:47 by mgarcin           #+#    #+#              #
#    Updated: 2014/03/27 23:35:20 by tdeniset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export	CFLAGS	=	-Wall -Wextra -Werror -g3 -Iincludes -Ilibft

export	CC		=	cc

export	INC		=	-I $(PWD)/libft

NAME		=	RT

SRC_DIR		=	srcs

FILES		=	main.c \
				objects.c \
				data_convert.c \
				vectors.c \
				ctrl1.c \
				ctrl2.c \
				mlx_hooks.c \
				mlx_trace.c \
				pixel_process.c \
				screen_ray.c \
				reflection.c \
				op_geom.c \
				op_math.c \
				primitives.c \
				sphere.c \
				cone.c \
				cylinder.c \
				plan.c

SRC			=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJ			=	$(SRC:.c=.o)

LIB			=	-Llibft -lft -L/usr/X11/lib/ -lmlx -framework OpenGL -framework AppKit

all:			libft/libft.a $(NAME)

libft/libft.a:
	@make -C libft

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"$(NAME) is being compiled : "\033[32m"Success"\033[0m"

$(OBJ):			libft/libft.a

%.o:			%.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"$(NAME) objects being deleted : "\033[32m"Success"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
	@make fclean -C libft

re:				fclean all

.PHONY:			all clean fclean re
