/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/17 14:21:36 by sdurr            ###   ########.fr       */
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
	int 	y;
	int		x;
	int		fd;
	int		ret;
	char	*line;
	char *recup;
	int i;

	mlx = mlx;
	window = window;
	ret = 1;
	fd = open(map, O_RDONLY);
	x = 200;
	y = 200;
	line = ft_strnew(15);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		while (*line != '\0')
		{
			recup = ft_strnew(15);
			i = 0;
			while (*line != ' ')
				recup[i] = *line++;
			y += ft_atoi(recup);
			mlx_pixel_put(mlx, window, x, y, 0xFF0000);
			mlx_pixel_put(mlx, window, x, y, 0xFF0000);
			y -= ft_atoi(recup);
			line++;
			x += 20;
		}
		line = ft_strnew(15);
		y += 20;
		x = 200;
	}
}
