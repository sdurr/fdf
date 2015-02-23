#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/04 09:59:37 by sdurr             #+#    #+#              #
#    Updated: 2015/02/23 17:31:42 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= fdf
SRC			= main.c \
				windows.c \
				point_droite.c \
				point_diag.c \
				point_diag_revers.c \
				point_vertical.c \
				point_vert.c \
				ft_create_elem.c \
				transfer_map.c \
				calc_x_y.c \
				expose_hook.c \
				key_hook.c \
				mouse_hook.c \
				define_color.c \

OBJ			= $(SRC:.c=.o)

CC			= gcc

export CFLAGS		= -Wall -Wextra -Werror

HPATH		= -L/usr/X11/lib -lmlx -lXext -lX11

PATHLIB    = -I libft/includes

$(NAME)	:		$(OBJ)
				Make -C libft/
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HPATH) -L libft/ -lft

clean	:
				Make -C libft/ fclean
				rm -rf $(OBJ)
				rm -rf *~

all		:		$(NAME)

fclean	:		clean
				rm -rf $(NAME)

re		:		fclean all

.c.o	:
				$(CC) $(CFLAGS) $(PATHLIB) -o $@ -c $<
