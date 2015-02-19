/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_x_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:34:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/19 17:11:18 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "libft.h"
#include <stdlib.h>


void	calc_x_y(void *mlx, void *window, t_list *s)
{
	int color;
	int tmp;


	ft_get_coord(s);
	while (s->next != NULL)
	{
		tmp = s->x;
		color = define_color(s->z);
//		if (c->z != 0)
			point_trace(s, mlx, window, color);
			/*	else
		{
			tmp = s->x;
			while (s->x < s->x2)
				mlx_pixel_put(mlx, window, s->x++, s->y, color);
			s->x = tmp;
			while (s->y < s->y2)
				mlx_pixel_put(mlx, window, s->x, s->y++, color);
				}*/
			ft_putstr("x = ");
			ft_putnbr(s->x);
			ft_putchar ('\n');
			ft_putstr("x2 = ");
			ft_putnbr(s->x2);
			ft_putchar ('\n');
			ft_putstr("y = ");
			ft_putnbr(s->y);
			ft_putchar ('\n');
			ft_putstr("y2 = ");
			ft_putnbr(s->y2);
			ft_putchar ('\n');
			ft_putchar ('\n');
			s = s->next;
	}
	tmp = s->x;
	s->x = tmp;
	point_trace(s, mlx, window, color);
		mlx_pixel_put(mlx, window, s->x, s->y++, color);
}

