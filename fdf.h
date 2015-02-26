/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 10:01:35 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/26 11:49:09 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_env
{
	void	*mlx;
	void	*window;
	char	*map;
	int		size;
	int		coeff_move_x;
	int		coeff_move_y;
}				t_env;

typedef struct	s_list
{
	int	x;
	int y;
	int z;
	struct		s_list *next;
}				t_list;

typedef struct	s_diag
{
	int dx;
	int dy;
	int x;
	int y;
	int d;
	int e;
	int ne;
}				t_diag;

typedef struct	s_base
{
	int x;
	int y;
}				t_base;

void			windows(t_env *e);

void			calc_x_y(void *mlx, void *window, t_list *s);
void			transfer_map(t_list *lst, char *line, t_base s);

t_list			*ft_create_elem(t_list *lst, int map, int ab, int alt, int y2, int stop);

int				ft_abs(int c);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				define_color(int y);



void		calc_x_y(void *mlx, void *window, t_list *s);


#endif
