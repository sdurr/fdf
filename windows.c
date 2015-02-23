/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/02/23 14:29:54 by sdurr            ###   ########.fr       */
=======
/*   Updated: 2015/02/18 16:34:15 by sdurr            ###   ########.fr       */
>>>>>>> parent of 503ec73... all
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
<<<<<<< HEAD
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
=======
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
>>>>>>> parent of 503ec73... all
		line = ft_strnew(150);
	}
	calc_x_y(mlx, window, &lst);
}
