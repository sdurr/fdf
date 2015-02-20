/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfert_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:01:08 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/20 18:27:31 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		transfer_map(t_list *lst, char *line, int ab, int or, char *test)
{
	char	*recup;
	int		i;
	char	*recup_y2;
	int stop;

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
		if (test != NULL)
		{
			while(*test != ' ' && *test != '\0')
				recup_y2[i++] = *test++;
			while(*test == ' ' && *test != '\0')
				test++;
			i = ft_atoi(recup_y2);
		}
		else
			i = ab - 30;
		if (*line == '\0')
			stop = 0;
		else
			stop = 30;
		ft_create_elem(lst, or+=30, ab, ft_atoi(recup), i, stop);
	}
}
