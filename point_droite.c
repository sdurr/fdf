/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_trace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 13:16:26 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/23 14:13:01 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>

void	point_droite(t_list *s, void *mlx, void *window, int color)
{
	int x;
	t_list *c;

	c = s;
	c = c->next;
	x = s->x;
	s->x2 = s->x2 + s->z;
	while (x < s->x2)
		{
			if (s->y - s->y2 != -50 && s->y - s->y2 != 520 && c->y != s->y)
				color=0x125252;
			mlx_pixel_put(mlx, window, x++, s->y, color);
		}
}


