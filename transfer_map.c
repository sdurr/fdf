/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfert_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:01:08 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/19 17:16:24 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		transfer_map(t_list *lst, char *line, int ab, int or, char *test)
{
	char	*recup;
	int		i;
	char	*recup_y2;

	while(*line != '\0')
	{
		i = 0;
		recup = ft_strnew(15);
		while(*line != ' ' && *line != '\0')
			recup[i++] = *line++;
		while(*line == ' ' && *line != '\0')
			line++;
		i = 0;
		recup_y2 = ft_strnew(15);
		while(*test != ' ' && *test != '\0')
			recup_y2[i++] = *test++;
		while(*test == ' ' && *test != '\0')
			test++;
		ft_create_elem(lst, or+=20, ab, ft_atoi(recup), ft_atoi(recup_y2));
	}
}
