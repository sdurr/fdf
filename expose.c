/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 11:28:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/09 16:14:01 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

void			loop(t_bressen *b)
{
	if (b->e2 > -b->dx)
	{
		b->err -= b->dy;
		b->x0 += b->sx;
	}
	if (b->e2 < b->dy)
	{
		b->err += b->dx;
		b->y0 += b->sy;
	}
}

static void		init_bressen(t_env *env, t_bressen *b, int x1, int y1)
{
	b->x0 = env->tab_x[env->y][env->x];
	b->y0 = env->tab_y[env->y][env->x];
	b->y = b->y0;
	b->dx = x1 - b->x0;
	b->dy = y1 - b->y0;
	if (b->dx < 0)
		b->dx = -b->dx;
	if (b->dy < 0)
		b->dy = -b->dy;
	b->ince = 2 * b->dy;
	b->incne = 2 * (b->dy - b->dx);
	b->x = b->x0;
	b->sx = b->x0 < x1 ? 1 : -1;
	b->sy = b->y0 < y1 ? 1 : -1;
	b->err = (b->dx > b->dy ? b->dx : -b->dy) / 2;
}

void			bresenham(int x1, int y1, t_env *e)
{
	t_bressen	b;
	int			c;

	init_bressen(e, &b, x1, y1);
	while (1)
	{
		if (e->map[e->y][e->x] > 0
			|| (e->y < e->height && e->map[e->y + 1][e->x] > 0 && b.x0 > x1))
		{
			c = 0xffff00;
			mlx_pixel_put(e->mlx, e->win, b.x0, b.y0, \
	c -= e->map[e->y][e->x] * 4000);
		}
		else if (e->map[e->y][e->x] < 0 && (c = 0x66ffff))
		{
			mlx_pixel_put(e->mlx, e->win, b.x0, b.y0, \
	c += e->map[e->y][e->x] * 4000);
		}
		else
			mlx_pixel_put(e->mlx, e->win, b.x0, b.y0, 0xffffff);
		b.e2 = b.err;
		if (b.x0 == x1 && b.y0 == y1)
			break ;
		loop(&b);
	}
}

int				expose_hook(t_env *e)
{
	int			i;
	int			j;
	int			width;

	i = 0;
	j = 0;
	init_tab(e, i, j);
	while (e->height > 0)
	{
		width = e->width + 1;
		while (--width > 0)
		{
			e->y = i;
			e->x = j;
			if (width > 1)
				bresenham(e->tab_x[i][j + 1], e->tab_y[i][j + 1], e);
			if (e->map[i + 1])
				bresenham(e->tab_x[i + 1][j], e->tab_y[i + 1][j], e);
			j++;
		}
		j = 0;
		i++;
		e->height--;
	}
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (e->win)
		if (keycode == 53)
			exit(0);
	return (0);
}
