/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfert_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:01:08 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/26 11:51:54 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		transfer_map(t_list *lst, char *line, t_base s)
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
		if (*line == '\0')
			stop = 30;
	}
}
