/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_x_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:34:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/26 11:17:21 by sdurr            ###   ########.fr       */
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
	c = c->next;
	ft_get_coord(s);
	s = s->next;
	while (s->next != NULL)
	{
		mlx_pixel_put(mlx, window, s->x, s->y, color);
		color = define_color(c->z);
	c = c->next;
	s = s->next;
	}
		mlx_pixel_put(mlx, window, s->x, s->y, color);
}
