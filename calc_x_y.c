/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_x_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:34:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/18 10:45:20 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "libft.h"

t_size	calc_x_y(void *mlx, void *window, t_size s, char *line)
{
	char *recup;

	while (line[s.j] != '\0')
	{
		recup = ft_strnew(15);
		s.i = 0;
		while (line[s.j] != ' ' && line[s.j] != '\0')
			recup[s.i++] = line[s.j++];
		s.y -= ft_atoi(recup);
		s.x2 = s.x + 20;
		s.y2 = s.y2;
		while (s.x != s.x2)
		{
			s.x = s.x + 1;
			mlx_pixel_put(mlx, window, s.x, s.y, 0xFF0000);
		}
		s.x -= 20;
		s.y2 = s.y + ft_atoi(recup);
		while (s.y != s.y2)
		{
			ft_putstr("y = ");
			ft_putnbr(s.y);
			ft_putchar('\n');

			ft_putstr("y2 = ");
			ft_putnbr(s.y2);
			ft_putchar('\n');
			if (ft_atoi(recup) > 0)
				s.y = s.y + 1;
			else
				s.y = s.y - 1;
			mlx_pixel_put(mlx, window, s.x, s.y, 0xFF0000);
		}

		while (line[s.j] == ' ' && line[s.j] != '\0')
			s.j++;
		s.x += 20;
		ft_putstr("x = ");
		ft_putnbr(s.x);
		ft_putchar('\n');
	}
	return (s);
}
