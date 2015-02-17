/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/17 12:13:42 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
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

	mlx = mlx;
	window = window;
	x = 0;
	y = 0;
	x = x;
	y = y;
	ret = 1;
	fd = open(map, O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
	}
}
