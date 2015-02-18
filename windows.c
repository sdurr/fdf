/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/18 10:44:44 by sdurr            ###   ########.fr       */
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
	int		fd;
	int		ret;
	char	*line;
	t_size	s;

	mlx = mlx;
	window = window;
	ret = 1;
	fd = open(map, O_RDONLY);
	s.x = 50;
	s.y = 50;
	line = ft_strnew(15);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		ft_putstr("line = ");
		ft_putendl(line);
		s.j = 0;
		s = calc_x_y(mlx, window, s, line);
	s.y += 20;
	s.x = 50;
	}
}
