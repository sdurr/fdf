/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 11:28:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/08 11:54:20 by sdurr            ###   ########.fr       */
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
	int coeff;
	int ptx;
	int pty;

	x = 30;
	y = 30;
	i = 0;
	j = 0;
	while (e->height > 0)
	{
		width = e->width;
		while (width >= 0)
		{
			coeff = 3;
			ptx = (int)(((0.07 *(float)x - 0.07 * (float) y)) * coeff + 370);
			pty = (int)(((0.04 * (float)x + 0.04 * (float)y) - 0.2 *(float)(e->map[i][j])) * coeff + 370);
			if (e->map[i][j] == 0)
				mlx_pixel_put(e->mlx, e->win, ptx, pty, 0xFFFF00);
			else
				mlx_pixel_put(e->mlx, e->win, ptx, pty, 0xFF0000);
			j++;
			width--;
			x += 100;
		}
		y+= 100;
		j = 0;
		x = 30;
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
