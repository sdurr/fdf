/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 09:16:11 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/09 17:32:38 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"

int main(int ac, char **av)
{
	t_env e;

	if (ac != 2)
	{
		ft_putendl_fd("Not enough or too many arguments.", 2);
		ft_putendl_fd("Please retry with this format: $> ./fdf \"mapfile\"", 2);
		return (-1);
	}
	e.map = recup_map(av[1], &e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, ((e.width + 50) * 15),\
	((e.height + 50) * 15), "fdf");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
