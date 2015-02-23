/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfert_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:01:08 by sdurr             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/02/23 14:30:55 by sdurr            ###   ########.fr       */
=======
/*   Updated: 2015/02/18 18:38:11 by sdurr            ###   ########.fr       */
>>>>>>> parent of 503ec73... all
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		transfer_map(t_list *lst, char *line, int ab, int or)
{
	char	*recup;
	int		i;
<<<<<<< HEAD
	char	*recup_y2;
	int stop;
=======
>>>>>>> parent of 503ec73... all

	while(*line != '\0')
	{
		i = 0;
		recup = ft_strnew(15);
		while(*line != ' ' && *line != '\0')
			recup[i++] = *line++;
		while(*line == ' ' && *line != '\0')
			line++;
<<<<<<< HEAD
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
		ab+=15;
		ft_create_elem(lst, or+= 30, ab, ft_atoi(recup), i, stop);
=======
		ft_create_elem(lst, or+=20, ab, ft_atoi(recup));
>>>>>>> parent of 503ec73... all
	}
}
