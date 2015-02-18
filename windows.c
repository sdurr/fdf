/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/18 16:34:15 by sdurr            ###   ########.fr       */
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
	t_list lst;
	int ab;
	int or;

	mlx = mlx;
	window = window;
	ret = 1;
	fd = open(map, O_RDONLY);
	line = ft_strnew(150);
	or = 50;
	ab = 50;
	while(ret == 1)
	{
		ret = get_next_line(fd, &line);
		transfer_map(&lst, line, ab, or);
		or = 50;
		ab += 20;
		ft_putendl(line);
		line = ft_strnew(150);
	}
	calc_x_y(mlx, window, &lst);
}
