# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/22 16:27:16 by rde-mato          #+#    #+#              #
#    Updated: 2017/01/25 14:04:30 by rde-mato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	hud

SRC = 		srcs/ctrl.c \
			srcs/drawhud.c \
			srcs/image.c \
			srcs/main.c \

CC =			gcc
CFLAGS =		-Wall -Werror -Wextra
COPT =			-c -I ./includes
LIBFTFLAGS =	-L ./libft -L ./minilibx -lm -lft -lXext -lX11
MLXFLAGS =		-lmlx #-framework OpenGL -framework AppKit
RM =			/bin/rm -f

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc -o $(NAME) $(SRC) $(LIBFTFLAGS) $(MLXFLAGS)

clean:
	make clean -C ./libft

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) $(NAME)

re: fclean all

.PHONY: $(EXEC) clean fclean re
