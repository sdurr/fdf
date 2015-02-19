/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 10:01:35 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/19 17:15:23 by sdurr            ###   ########.fr       */
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
	int x2;
	int y2;
	int z;
	struct s_list *next;
}				t_list;

typedef struct s_trace
{
	int sx;
	int dx;
	int dy;
	int err;
	int e2;
	int sy;

}				t_trace;

void		windows(void *mlx, void *window, char *map);

void		point_trace(t_list *s, void *mlx, void *window, int color);
void		calc_x_y(void *mlx, void *window, t_list *s);
void		ft_get_coord(t_list *s);
void		transfer_map(t_list *lst, char *line, int ab, int or, char *test);

t_list      *ft_create_elem(t_list *lst, int map, int ab, int alt, int y2);

int			ft_abs(int c);
int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
int			mouse_hook(int button, int x, int y, t_env *e);
int			define_color(int y);

#endif
