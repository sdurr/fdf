/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 13:01:09 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/09 16:14:33 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/libft.h"
#include <stdio.h>
#include "fdf.h"

static int	**ft_realloc_new(char **split, int x, int y, int **old)
{
	int i;
	int **new;

	x = ft_inttablen(old);
	if (!(new = (int **)malloc(sizeof(int *) * x)))
		return (NULL);
	x = -1;
	i = ft_tablen(split);
	while (old[++x])
	{
		if (!(new[x] = (int *)malloc(sizeof(int) * i + 1)))
			return (NULL);
		y = -1;
		while (++y <= i)
			new[x][y] = old[x][y];
	}
	if (!(new[x] = (int *)malloc(sizeof(int) * ft_tablen(split) + 1)))
		return (NULL);
	y = -1;
	while (split[++y])
		new[x][y] = ft_atoi(split[y]);
	new[x + 1] = NULL;
	while (--x >= 0)
		ft_memdel((void **)&old[x]);
	return (new);
}

int			**ft_realloc(int **old, char **split, t_env *e)
{
	int		**new;
	int		y;
	int		x;

	x = 0;
	y = -1;
	if (old)
		return (ft_realloc_new(split, x, y, old));
	if (!(new = (int **)malloc(sizeof(int *) * 2)))
		return (NULL);
	new[0] = (int *)malloc(sizeof(int) * ft_tablen(split));
	while (split[++y])
		new[0][y] = ft_atoi(split[y]);
	e->width = y;
	new[1] = NULL;
	return (new);
}
