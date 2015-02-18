/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 10:01:35 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/18 16:24:32 by sdurr            ###   ########.fr       */
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

typedef struct s_list
{
	int x;
	int y;
	int z;
	struct s_list *next;
}				t_list;

void		windows(void *mlx, void *window, char *map);


void		calc_x_y(void *mlx, void *window, t_list *s);
t_list      *ft_create_elem(t_list *lst, int map, int ab, int alt);
void		transfer_map(t_list *lst, char *line, int ab, int or);

int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
int			mouse_hook(int button, int x, int y, t_env *e);
int			define_color(int y);

#endif
