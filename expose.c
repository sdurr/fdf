/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 11:28:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/09 11:50:41 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

void		bresenham(int x0, int y0,int x1, int y1, t_env *env, int i, int j)
{
	int x;
	int y;
	int dx;
	int dy;
	int ince;
	int incne;
	int e;
	int sx;
	int sy;
	int err;
	int e2;

	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	ince = 2 * dy;
	incne = 2 *(dy - dx);
	e = 2 * dy - dx;
	x = x0;
	sx =  x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) /2;
	while (1)
	{
		(void)i;
		(void)j;
		mlx_pixel_put(env->mlx, env->win, x0, y0, 0xFFFFFF);
		e2 = err;
		if (x0 == x1 && y0 == y1)
			break;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

int expose_hook(t_env *e)
{
	int x;
	int y;
	int i;
	int j;
	int width;
	int coeff;
	int		**tab_x;
	int		**tab_y;
	int height;

	height = e->height;
	tab_x = (int **)malloc(sizeof(int *) * height + 1);
	tab_y = (int **)malloc(sizeof(int *) * height + 1);
	i = 0;
	y = 30;
	while (height)
	{
		j = 0;
		width = e->width;
		tab_x[i] = (int *)malloc(sizeof(int) * width + 1);
		tab_y[i] = (int *)malloc(sizeof(int) * width + 1);
		x = 30;
		while (width)
		{
			coeff = 3;
			tab_x[i][j] = (int)(((0.07 *(float)x - 0.07 * (float) y)) * coeff + 370);
			tab_y[i][j] = (int)(((0.04 * (float)x + 0.04 * (float)y) - 0.2 *(float)(e->map[i][j])) * coeff + 370);
			x += 100;
			width--;
			j++;
		}
		y+=100;
		i++;
		height--;
	}
	tab_x[i] = NULL;
	tab_y[i] = NULL;
	i = 0;
	j = 0;
	while (e->height > 0)
	{
		width = e->width;
		while (width > 0)
		{
			if (width > 1)
				bresenham(tab_x[i][j], tab_y[i][j], tab_x[i][j + 1], tab_y[i][j + 1], e, i, j);
			if (e->map[i + 1])
				bresenham(tab_x[i][j], tab_y[i][j], tab_x[i + 1][j], tab_y[i + 1][j], e, i, j);
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
