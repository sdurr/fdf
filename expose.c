/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 11:28:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/09 13:41:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

void		bresenham(int x1, int y1, t_env *env)
{
	t_bressen b;

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
	b.incne = 2 *(b.dy - b.dx);
	b.x = b.x0;
	b.sx = b.x0 < x1 ? 1 : -1;
	b.sy = b.y0 < y1 ? 1 : -1;
	b.err = (b.dx > b.dy ? b.dx : -b.dy) /2;
	while (1)
	{
		mlx_pixel_put(env->mlx, env->win, b.x0, b.y0, 0xFFFFFF);
		b.e2 = b.err;
		if (b.x0 == x1 && b.y0 == y1)
			break;
		if (b.e2 > -b.dx)
		{
			b.err -= b.dy;
			b.x0 += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			b.y0 += b.sy;
		}
	}
}
void	init_tab(t_env *e, int i, int j)
{
	int width;
	int coeff;
	int height;
	int x;
	int y;

	height = e->height;
	e->tab_x = (int **)malloc(sizeof(int *) * height + 1);
	e->tab_y = (int **)malloc(sizeof(int *) * height + 1);
	i = 0;
	y = 30;
	width = e->width;
	while (height)
	{
		j = 0;
		width = e->width;
		e->tab_x[i] = (int *)malloc(sizeof(int) * width + 1);
		e->tab_y[i] = (int *)malloc(sizeof(int) * width + 1);
		x = 30;
		while (width)
		{
			coeff = 3;
			e->tab_x[i][j] = (int)(((0.07 *(float)x - 0.07 * (float) y)) * coeff + 370);
			e->tab_y[i][j] = (int)(((0.04 * (float)x + 0.04 * (float)y) - 0.2 *(float)(e->map[i][j])) * coeff + 370);
			x += 100;
			width--;
			j++;
		}
		y+=100;
		i++;
		height--;
	}
	e->tab_x[i] = NULL;
	e->tab_y[i] = NULL;
}

int expose_hook(t_env *e)
{
	int i;
	int j;
	int width;
	int height;

	height = e->height;
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

int	key_hook(int keycode, t_env *e)
{
	if (e->win)
		if (keycode == 53)
			exit(0);
	return (0);
}
