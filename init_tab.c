/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 15:59:47 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/09 16:21:02 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void		projection_isometrique(t_env *e, t_init init, int i, int j)
{
	e->tab_x[i][j] = (int)(((0.07 * \
	(float)init.x - 0.07 * (float)init.y)) * init.coeff + 370);
	e->tab_y[i][j] = (int)(((0.04 * \
	(float)init.x + 0.04 * (float)init.y) - 0.2 * \
	(float)(e->map[i][j])) * init.coeff + 370);
}

static int		init_x(t_env *e, t_init init)
{
	if (e->width > 100)
		init.x += e->width / 5;
	else if (e->width > 50)
		init.x += e->width / 3;
	else if (e->width > 35)
		init.x += e->width / 2;
	else
		init.x += (e->width * 4);
	return (init.x);
}

static int		init_y(t_env *e, t_init init)
{
	if (e->width > 100)
		init.y += e->width / 5;
	else if (e->width > 50)
		init.y += e->width / 3;
	else if (e->width > 35)
		init.y += e->width / 2;
	else
		init.y += (e->width * 4);
	return (init.y);
}

void			init_tab(t_env *e, int i, int j)
{
	t_init	init;

	init.height = e->height;
	e->tab_x = (int **)malloc(sizeof(int *) * init.height + 1);
	e->tab_y = (int **)malloc(sizeof(int *) * init.height + 1);
	init.y = 30;
	while (init.height--)
	{
		j = 0;
		init.width = e->width;
		e->tab_x[i] = (int *)malloc(sizeof(int) * init.width + 1);
		e->tab_y[i] = (int *)malloc(sizeof(int) * init.width + 1);
		init.x = 30;
		while (init.width--)
		{
			init.coeff = 3;
			projection_isometrique(e, init, i, j);
			init.x = init_x(e, init);
			j++;
		}
		init.y = init_y(e, init);
		i++;
	}
}
