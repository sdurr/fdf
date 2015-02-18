/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/18 10:28:41 by sdurr            ###   ########.fr       */
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
	int		x2;
	int		y2;


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
				s.y -= ft_atoi(recup);
				x2 = s.x + 20;
				y2 = y2;
				while (s.x != x2)
				{
					s.x = s.x + 1;
					mlx_pixel_put(mlx, window, s.x, s.y, 0xFF0000);
				}
				s.x -= 20;
				y2 = s.y + ft_atoi(recup);
				while (s.y != y2)
				{
				ft_putstr("y = ");
				ft_putnbr(s.y);
				ft_putchar('\n');

					ft_putstr("y2 = ");
					ft_putnbr(y2);
					ft_putchar('\n');
					if (ft_atoi(recup) > 0)
						s.y = s.y + 1;
					else
						s.y = s.y - 1;
					mlx_pixel_put(mlx, window, s.x, s.y, 0xFF0000);
				}

				while (line[s.j] == ' ' && line[s.j] != '\0')
					s.j++;
				s.x += 20;
		ft_putstr("x = ");
		ft_putnbr(s.x);
		ft_putchar('\n');
		}
		line = ft_strnew(15);
	s.y += 20;
	s.x = 50;
	}
}
