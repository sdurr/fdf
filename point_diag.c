/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_trace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 13:16:26 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/21 11:53:09 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>

void	point_diag(t_list *s, void *mlx, void *window, int color)
{
	t_list *c;
	t_diag d;

	c = s;
	c = c->next;
	d.dx = s->x2 - s->x;
	d.dy = c->y - s->y;
	d.d = 2 * d.dy - d.dx;
	d.e = 2 * d.dy;
	d.ne = 2 * (d.dy - d.dx);
	d.x = s->x;
	d.y = s->y;
	mlx_pixel_put(mlx, window, d.x, d.y, color);
	while (d.x < s->x2)
	{
		if (d.d <= 0)
		{
			d.d += d.e;
			d.x++;
		}
		else
		{
			d.d += d.ne;
			d.x++;
			d.y++;
		}
		//color += 100000;
		mlx_pixel_put(mlx, window, d.x, d.y, color);

	}
}


