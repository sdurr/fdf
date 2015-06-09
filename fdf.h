/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 09:47:06 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/09 15:19:08 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

# include <mlx.h>

typedef struct s_env
{
	void	*mlx;
	void	*win;
	int		**map;
	int		width;
	int		height;
	int		**tab_x;
	int		**tab_y;
	int		x;
	int		y;
	int color_a;
	int color_b;
	int color_c;
}				t_env;

typedef struct s_bressen
{
	int x;
	int y;
	int x0;
	int y0;
	int dx;
	int dy;
	int ince;
	int incne;
	int sx;
	int sy;
	int err;
	int e2;
}			t_bressen;

typedef struct s_init
{
	int width;
	int coeff;
	int height;
	int x;
	int y;
}				t_init;

int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
int			**recup_map(char *file, t_env *e);
int			**ft_realloc(int **old, char **split, t_env *e);
int			ft_inttablen(int **tab);

#endif
