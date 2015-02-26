/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:39:48 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/26 11:30:53 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int		key_hook(int keycode, t_env *e)
{
		if (keycode == 53)
			exit(0);
		if (keycode == 63)
			e->size = e->size * 2;
		if (keycode == 78)
			e->size = e->size / 2;
		if (keycode == 124)
			e->coeff_move_x = e->coeff_move_x + 10;
		if (keycode == 123)
			e->coeff_move_x = e->coeff_move_x - 10;
		if (keycode == 126)
			e->coeff_move_y = e->coeff_move_y + 10;
		if (keycode == 125)
			e->coeff_move_y = e->coeff_move_y - 10;
		if (keycode == 53)
			exit(0);
	return (0);
}
