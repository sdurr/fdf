/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 11:28:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/08 17:19:35 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

void		bresenham(int x, int y,int x1, int y1, t_env *env, int i, int j)
{
	int x0;
	int y0;
	int dx;
	int dy;
	int ince;
	int incne;
	int e;

	y0 = y;
	dx = x1 - x;
	dy = y1 - y;
	ince = 2 * dy;
	incne = 2 *(dy - dx);
	e = 2 * dy - dx;
	while (x  < x1)
	{
		x0 = x;
		x++;
			if (env->map[i][j] == 0)
				mlx_pixel_put(env->mlx, env->win, x0, y0, 0xFFFF00);
			else
				mlx_pixel_put(env->mlx, env->win, x0, y0, 0xFF0000);
			if (e >= 0)
			{
				y0 += 1;
				e+= incne;
			}
			else
				e+= ince;
	}
}
void		bresenham_y1(int x, int y,int x1, int y1, t_env *env, int i, int j)
{
	int x0;
	int y0;
	int dx;
	int dy;
	int ince;
	int incne;
	int e;

	y0 = y;
	dx = x1 - x;
	dy = y1 - y;
	ince = 2 * dy;
	incne = 2 *(dy - dx);
	e = 2 * dy - dx;
	while (x  < x1)
	{
		x0 = x;
		x++;
			if (env->map[i][j] == 0)
				mlx_pixel_put(env->mlx, env->win, x0, y0, 0xFFFF00);
			else
				mlx_pixel_put(env->mlx, env->win, x0, y0, 0xFF0000);
			if (e >= 0)
			{
				y0 -= 1;
				e+= incne;
			}
			else
				e+= ince;
	}
}
void		bresenham_y2(int x, int y,int x1, int y1, t_env *env, int i, int j)
{
	int x0;
	int y0;
	int dx;
	int dy;
	int ince;
	int incne;
	int e;

	y0 = y;
	dx = x1 - x;
	dy = y1 - y;
	ince = 2 * dy;
	incne = 2 *(dy - dx);
	e = 2 * dy - dx;
	x0 = x;
	while (x  < x1)
	{
		x0 = x;
		x++;
			if (env->map[i - 1][j] == 0)
				mlx_pixel_put(env->mlx, env->win, x0, y0, 0xFFFF00);
			else
				mlx_pixel_put(env->mlx, env->win, x0, y0, 0xFF0000);
			if (e <= 0)
			{
				y0 -= 1;
				e+= incne;
			}
			else
			{
				e+= ince;
			}
	}
}
void		bresenham_y3(int x, int y,int x1, int y1, t_env *env, int i, int j)
{
	int x0;
	int y0;
	int dx;
	int dy;
	int ince;
	int incne;
	int e;

	y0 = y;
	dx = x1 - x;
	dy = y1 - y;
	ince = 2 * dx;
	incne = 2 *(dx - dy);
	e = 2 * dx - dy;
	x0 = x;
	while (y  > y1)
	{
		y0 = y;
		y--;
			if (env->map[i - 1][j] == 0)
				mlx_pixel_put(env->mlx, env->win, x0, y0, 0xFFFF00);
			else
				mlx_pixel_put(env->mlx, env->win, x0, y0, 0xFF0000);
			if (e <= 0)
			{
				x0 += 1;
				e+= incne;
			}
			else
			{
				e+= ince;
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
	int ptx;
	int pty;
	int ptx1;
	int pty1;

	x = 30;
	y = 30;
	i = 0;
	j = 0;
	while (e->height > 0)
	{
		width = e->width;
		while (width > 0)
		{
			coeff = 3;
			ptx = (int)(((0.07 *(float)x - 0.07 * (float) y)) * coeff + 370);
			ptx1 = (int)(((0.07 *(float)(x+100) - 0.07 * (float) y)) * coeff + 370);
			pty = (int)(((0.04 * (float)x + 0.04 * (float)y) - 0.2 *(float)(e->map[i][j])) * coeff + 370);
			pty1 = (int)(((0.04 * (float)x + 0.04 * (float)(y + 100)) - 0.2 *(float)(e->map[i][j])) * coeff + 370);
			if ((e->map[i][j] == 0 && e->map[i][j + 1] == 0) || e->map[i][j] == e->map[i][j + 1])
				bresenham(ptx, pty, ptx1, pty1, e, i, j);
			if (e->map[i - 1] && e->map[i - 1][j] == e->map[i][j])
				bresenham_y1(ptx, pty, ptx1, pty1, e, i, j);

			pty1 = (int)(((0.04 * (float)x + 0.04 * (float)(y + 100)) - 0.2 *(float)(e->map[i][j + 1])) * coeff + 370);
			if (e->map[i][j + 1] != e->map[i][j])
			bresenham(ptx, pty, ptx1, pty1, e, i, j + 1);
			j++;
			width--;
			x += 100;
		}
		y += 100;
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
