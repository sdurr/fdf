/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/17 15:29:50 by sdurr            ###   ########.fr       */
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
	char	*recup;
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
		while (line[s.j] != '\0')
		{
			recup = ft_strnew(15);
			s.i = 0;
			while (line[s.j] != ' ' && line[s.j] != '\0')
				recup[s.i++] = line[s.j++];
			s.y += ft_atoi(recup);
			mlx_pixel_put(mlx, window, s.x, s.y, 0xFF0000);
			s.y -= ft_atoi(recup);
			while (line[s.j] == ' ' && line[s.j] != '\0')
				s.j++;
			s.x += 20;
		}
		line = ft_strnew(15);
		s.y += 20;
		s.x = 50;
	}
}
