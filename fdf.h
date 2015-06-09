/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 09:47:06 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/09 11:51:23 by sdurr            ###   ########.fr       */
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
}				t_env;

int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
int			**recup_map(char *file, t_env *e);
int			**ft_realloc(int **old, char **split, t_env *e);
int			ft_inttablen(int **tab);

#endif
