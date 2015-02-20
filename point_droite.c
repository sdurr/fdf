/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_trace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 13:16:26 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/20 15:41:36 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>

void	point_droite(t_list *s, void *mlx, void *window, int color)
{
	int x;

	x = s->x;
		while (x < s->x2)
			mlx_pixel_put(mlx, window, x++, s->y, color);
}


