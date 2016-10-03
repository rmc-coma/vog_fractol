#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 13:18:15 by rmc-coma          #+#    #+#              #
#    Updated: 2016/03/22 22:39:35 by rmc-coma         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -framework OpenGL -framework AppKit -lpthread

HDR = 	-I ./libft/include/libft.h \
		-I ./libft/include/get_next_line.h \
		-I ./minilibx/mlx.h

LIB =	./libft/libft.a \
		./minilibx/libmlx.a

SRC =	main.c fo_draw_mandelbrot.c fo_init.c fo_clear_framebuffer.c \
		fo_input_keyboard.c fo_input_mouse.c fo_draw_julia.c fo_input_motion.c \
		fo_draw_ship.c fo_close.c fo_fireup_threads.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C ./libft
	make -C ./minilibx
	$(CC) $(CFLAGS) $(HDR) -c $(SRC)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C ./libft clean
	make -C ./minilibx clean
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	make -C ./libft fclean
	make -C ./minilibx fclean
	rm -f $(NAME)

re: fclean all