#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/04 09:59:37 by sdurr             #+#    #+#              #
#    Updated: 2015/02/26 11:49:25 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= fdf
SRC			= main.c \
				windows.c \
				transfer_map.c \
				ft_create_elem.c \
				expose_hook.c \
				key_hook.c \
				define_color.c \

OBJ			= $(SRC:.c=.o)

CC			= gcc

CFLAGS		=

HPATH		= -lmlx -framework OpenGL -framework Appkit

PATHLIB    = -I libft/includes

$(NAME)	:		$(OBJ)
				Make -C libft/
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HPATH) -L libft -lft

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
