/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 10:01:35 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/18 10:45:08 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

typedef struct s_env
{
	void	*mlx;
	void	*window;
	char	*map;
}				t_env;

typedef struct s_size
{
	int x;
	int x2;
	int y;
	int y2;
	int i;
	int j;
}				t_size;

void		windows(void *mlx, void *window, char *map);
t_size		calc_x_y(void *mlx, void *window, t_size s, char *line);
int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
int			mouse_hook(int button, int x, int y, t_env *e);

#endif
