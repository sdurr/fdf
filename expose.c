/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 11:28:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/07 15:55:06 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>


int expose_hook(t_env *e)
{
	int x;
	int y;
	int i;
	int j;
	int width;
	int test;

	x = 50;
	y = 50;
	i = 0;
	j = 0;
	while (e->height > 0)
	{
		width = e->width;
		while (width >= 0)
		{
			y += e->map[i][j];
			test = y + 30;
			while(y < test)
				mlx_pixel_put(e->mlx, e->win, x, y++, 0xFF0000);
			y -= 30;
			test = x+ 30;
			while(x < test)
				mlx_pixel_put(e->mlx, e->win, x++, y, 0xFF0000);

				y -= e->map[i][j];
			j++;
			width--;
		}

		y+= 30;

		j = 0;
		x = 50;
		i++;
		e->height--;
	}
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	if (e->win)
		if (keycode == 53)
			exit(0);
	return (0);
}
