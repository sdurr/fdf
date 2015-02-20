/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/20 18:28:49 by sdurr            ###   ########.fr       */
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
	char	*test_y;
	t_list lst;
	int ab;
	int or;
	int fd2;
	int i;

	ret = 1;
	fd = open(map, O_RDONLY);
	fd2 = open(map, O_RDONLY);
	line = ft_strnew(150);
	or = 50;
	ab = 50;
	get_next_line(fd2, &test_y);
	while(ret == 1)
	{
		ret = get_next_line(fd, &line);
		i  = get_next_line(fd2, &test_y);
		if (i == 0)
			test_y = NULL;
		transfer_map(&lst, line, ab, or, test_y);
		or = 50;
		ab += 30;
		ft_putstr("line = ");
		  ft_putendl(line);
		line = ft_strnew(150);
	}
	calc_x_y(mlx, window, &lst);
}
