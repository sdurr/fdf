/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 11:28:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/09 14:05:57 by sdurr            ###   ########.fr       */
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

void			bresenham(int x1, int y1, t_env *env)
{
	t_bressen	b;

	b.x0 = env->tab_x[env->y][env->x];
	b.y0 = env->tab_y[env->y][env->x];
	b.y = b.y0;
	b.dx = x1 - b.x0;
	b.dy = y1 - b.y0;
	if (b.dx < 0)
		b.dx = -b.dx;
	if (b.dy < 0)
		b.dy = -b.dy;
	b.ince = 2 * b.dy;
	b.incne = 2 * (b.dy - b.dx);
	b.x = b.x0;
	b.sx = b.x0 < x1 ? 1 : -1;
	b.sy = b.y0 < y1 ? 1 : -1;
	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
	while (1)
	{
		mlx_pixel_put(env->mlx, env->win, b.x0, b.y0, 0xFFFFFF);
		b.e2 = b.err;
		if (b.x0 == x1 && b.y0 == y1)
			break ;
		loop(&b);
	}
}

void			projection_isometrique(t_env *e, t_init init, int i, int j)
{
	e->tab_x[i][j] = (int)(((0.07 * \
	(float)init.x - 0.07 * (float)init.y)) * init.coeff + 370);
	e->tab_y[i][j] = (int)(((0.04 * \
	(float)init.x + 0.04 * (float)init.y) - 0.2 * \
	(float)(e->map[i][j])) * init.coeff + 370);
}

void			init_tab(t_env *e, int i, int j)
{
	t_init		init;

	init.height = e->height;
	e->tab_x = (int **)malloc(sizeof(int *) * init.height + 1);
	e->tab_y = (int **)malloc(sizeof(int *) * init.height + 1);
	init.y = 30;
	while (init.height--)
	{
		j = 0;
		init.width = e->width;
		e->tab_x[i] = (int *)malloc(sizeof(int) * init.width + 1);
		e->tab_y[i] = (int *)malloc(sizeof(int) * init.width + 1);
		init.x = 30;
		while (init.width--)
		{
			init.coeff = 3;
			projection_isometrique(e, init, i, j);
			init.x += 100;
			j++;
		}
		init.y += 100;
		i++;
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
		width = e->width;
		while (width > 0)
		{
			e->y = i;
			e->x = j;
			if (width > 1)
				bresenham(e->tab_x[i][j + 1], e->tab_y[i][j + 1], e);
			if (e->map[i + 1])
				bresenham(e->tab_x[i + 1][j], e->tab_y[i + 1][j], e);
			j++;
			width--;
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
