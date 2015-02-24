/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/24 09:46:58 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

void		windows(void *mlx, void *window, char *map)
{
	char	*line;
	char	*test_y;
	t_list	lst;
	t_plan	s;
	int		i;

	s.ret = 1;
	s.fd = open(map, O_RDONLY);
	s.fd2 = open(map, O_RDONLY);
	line = ft_strnew(150);
	s.or = 400;
	s.ab = 200;
	get_next_line(s.fd2, &test_y);
	while(s.ret == 1)
	{
		s.ret = get_next_line(s.fd, &line);
		i  = get_next_line(s.fd2, &test_y);
		if (i == 0)
			test_y = NULL;
		transfer_map(&lst, line, s.ab, s.or, test_y);
		s.ab += 30;
		s.or -= 30;
		line = ft_strnew(150);
	}
	calc_x_y(mlx, window, &lst);
}
