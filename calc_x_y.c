/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_x_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:34:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/18 19:02:37 by sdurr            ###   ########.fr       */
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
	s = s->next;
	while (s->next != NULL)
	{
		color = define_color(s->z);
		if (s->z == 0)
			while (s->x < c->x)
				mlx_pixel_put(mlx, window, s->x++, s->y, color);
	if (s->z == 0)
			while (s->y < c->y)
			{
				mlx_pixel_put(mlx, window, s->x, s->y++, color);
			}
	c = c->next;
	s = s->next;
	ft_putstr("next ");
	ft_putnbr(s->x);
	ft_putchar ('\n');
	}
	mlx_pixel_put(mlx, window, s->x, s->y, color);
}

