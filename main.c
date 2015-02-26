/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 19:18:05 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/26 11:30:00 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "fdf.h"

int		main(int ac, char **av)
{
	t_env e;

	if (ac == 2)
		e.map = av[1];
	e.mlx = mlx_init();
	e.window = mlx_new_window(e.mlx, 2000, 1040, "fdf");
	e.coeff_move_x = 0;
	e.coeff_move_y = 0;
	e.size = 20;
	mlx_expose_hook(e.window, expose_hook, &e);
	mlx_key_hook(e.window, key_hook, &e);
	mlx_loop(e.mlx);

	return (0);
}
