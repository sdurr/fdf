/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 19:18:05 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/17 13:52:43 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "fdf.h"

int		main(int ac, char **av)
{
	t_env e;

	ac = ac;
	if (ac == 2)
		e.map = av[1];
	e.mlx = mlx_init();
	e.window = mlx_new_window(e.mlx, 800, 800, "fdf");
	mlx_expose_hook(e.window, expose_hook, &e);
	mlx_key_hook(e.window, key_hook, &e);
	mlx_mouse_hook(e.window, mouse_hook, &e);
	mlx_loop(e.mlx);

	return (0);
}
