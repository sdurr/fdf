/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 10:01:35 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/17 15:28:26 by sdurr            ###   ########.fr       */
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
	int y;
	int i;
	int j;
}				t_size;

void		windows(void *mlx, void *window, char *map);
int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
int			mouse_hook(int button, int x, int y, t_env *e);

#endif
