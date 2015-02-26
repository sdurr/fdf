/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfert_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:01:08 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/26 14:32:21 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		transfer_map(t_list *lst, char *line, t_base *s, t_env *e)
{
	char	*recup;
	int stop;
	int i;

	while(*line != '\0')
	{
		i = 0;
		recup = ft_strnew(15);
		while(*line != ' ' && *line != '\0')
			recup[i++] = *line++;
		while(*line == ' ' && *line != '\0')
			line++;
		s->x += 10 * e->size;
		ft_create_elem(lst, ft_atoi(recup), s);
	}
}
