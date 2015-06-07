/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 12:36:47 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/07 15:26:49 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <fcntl.h>
#include "./libft/libft.h"

int			**recup_map(char *file, t_env *e)
{
	int		fd;
	char	*line;
	int		**tab;
	char	**split;

	tab = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putendl_fd("Connot open the file", 2);
		exit(0);
	}
	e->height = 0;
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, ' ');
		tab = ft_realloc(tab, split, e);
		e->height++;
	}
	return (tab);
}
