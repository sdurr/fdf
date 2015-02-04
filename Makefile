#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/04 09:59:37 by sdurr             #+#    #+#              #
#    Updated: 2015/02/04 10:01:01 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= fdf
SRC			=

OBJ			= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

$(NAME)	:		$(OBJ)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean	:
				rm -rf $(OBJ)
				rm -rf *~

all		:		$(NAME)

fclean	:		clean
				rm -rf $(NAME)

re		:		fclean all

.c.o	:
				$(CC) $(CFLAGS) -o $@ -c $<
