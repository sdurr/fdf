/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:22:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/26 11:49:03 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"


/*open map and send line at transfer_map*/

void		windows(t_env *e)
{
	t_list point;
	char *line;
	int ret;
	int fd;
	t_base s;

	ret = 1;
	if ((fd = open(e->map, O_RDONLY)) == -1)
	{
		ft_putendl("Error");
		exit (0);
	}
	while (ret == 1)
	{
		s.x =  (50 + e->coeff_move_x) * e->size;
		s.y =  (50 + e->coeff_move_y) * e->size;
		ret = get_next_line(fd, &line);
		transfer_map(&point, line, s);
	}
}
