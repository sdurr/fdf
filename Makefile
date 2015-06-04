#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/04 10:34:39 by sdurr             #+#    #+#              #
#    Updated: 2015/06/04 11:30:43 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= fdf
SRC			= main.c \
				draw.c \
				expose.c \

OBJ			= $(SRC:.c=.o)

CC			= gcc

CFLAGS		=

HPATH		= -lmlx -framework OpenGL -framework Appkit

PATHLIB    = -I libft/includes

$(NAME)	:		$(OBJ)
				Make -C mlx/
				Make -C libft/
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Lmlx $(HPATH) -L libft -lft

clean	:
				Make -C libft/ fclean
				rm -rf $(OBJ)
				rm -rf *~

all		:		$(NAME)

fclean	:		clean
				rm -rf $(NAME)

re		:		fclean all

.c.o	:
				$(CC) $(CFLAGS) $(PATHLIB) -I mlx -o $@ -c $<