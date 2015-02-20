/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_trace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 13:16:26 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/20 18:29:08 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>

void	point_vertical(t_list *s, void *mlx, void *window, int color)
{
	int y;

	y = s->y;
		while (y < s->y2)
		{
			if (s->y - s->y2 < -30)
				color += 100000;
			else if (s->y - s->y2 > -30)
					color += 100000;
			mlx_pixel_put(mlx, window, s->x, y++, color);
		}
}


