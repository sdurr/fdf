/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 09:47:06 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/04 14:41:29 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

# include <mlx.h>

typedef struct s_env
{
	void	*mlx;
	void	*win;
	char	*map;

}				t_env;

void		draw(void *mlx, void *win);
int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);

#endif
