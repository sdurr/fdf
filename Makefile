#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/04 10:34:39 by sdurr             #+#    #+#              #
#    Updated: 2015/06/07 14:37:16 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= fdf
SRC			= main.c \
				expose.c \
				recup_map.c \
				ft_realloc.c \
				ft_inttablen.c \

OBJ			= $(SRC:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

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