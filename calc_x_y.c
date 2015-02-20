/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_x_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:34:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/20 18:26:24 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "libft.h"
#include <stdlib.h>


void	calc_x_y(void *mlx, void *window, t_list *s)
{
	int color;
		t_list *c;

	c = s;
	c = c->next;
	ft_get_coord(s);
	while (s->next != NULL)
	{
		color = define_color(s->z);
		mlx_pixel_put(mlx, window, s->x, s->y, color);
		if (s->x < s->x2 && s->y == c->y)
			point_droite(s, mlx, window, color);
		else if (c->y > s->y)
			point_diag(s, mlx, window, color);
		else
			point_diag_revers(s, mlx, window, color);
	point_vertical(s, mlx, window, color);
		c= c->next;
			s = s->next;
	}
}

