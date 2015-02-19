/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_trace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 13:16:26 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/19 15:34:16 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>

void	point_trace(t_list *s, void *mlx, void *window, int color)
{
	t_trace d;
	int x;
	int y;
	int i;

	d.dx = ft_abs(s->x2 - s->x);
	if (s->x < s->x2)
		d.sx = 1;
	else
		d.sx = -1;
	d.dy = ft_abs(s->y2 - s->y);
	if (s->y < s->y2)
		d.sy = 1;
	else
		d.sy = -1;
	x = s->x;
	y = s->y;
	if (d.dx > d.dy)
	{
		d.err = d.dx /2;
		i = 0;
		while (i++ < d.dx)
		{
			x+=d.sx;
			d.err += d.sy;
			if (d.err > d.dx)
				{
					d.err -= d.dx;
					y+= d.sy;
				}
	mlx_pixel_put(mlx, window, x, y, color);
		}
	}
	else
	{
		d.err = d.dy / 2;
		i = 0;
		while (i++ < d.dy)
		{
			y += d.sy;
			d.err +=d.dx;
			if (d.err > d.dy)
			{
				d.err -= d.dy;
				x+= d.sx;
			}
			mlx_pixel_put(mlx, window, x, y, color);
		}
			mlx_pixel_put(mlx, window, s->x, s->y, color);
	}
/*	while (s->x < s->x2)
	{
		mlx_pixel_put(mlx, window, s->x, s->y, color);
		d.e2 = d.err;
		if (d.e2 > -d.dx)
		{
			d.err -= d.dy;
			s->x += d.sx;
		}
		if (d.e2 > -d.dy)
		{
			d.err += d.dx;
			s->y -= d.sy;
		}
			mlx_pixel_put(mlx, window, s->x, s->y, color);
			}*/
}
