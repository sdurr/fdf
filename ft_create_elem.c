/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:52:35 by sdurr             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/02/23 14:29:01 by sdurr            ###   ########.fr       */
=======
/*   Updated: 2015/02/18 16:24:50 by sdurr            ###   ########.fr       */
>>>>>>> parent of 503ec73... all
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

<<<<<<< HEAD
t_list		*ft_create_elem(t_list *lst, int map, int ab, int alt, int y2, int stop)
=======
t_list		*ft_create_elem(t_list *lst, int map, int ab, int alt)
>>>>>>> parent of 503ec73... all
{
	t_list *elem;
	t_list *begin;

	begin = lst;
	elem = malloc(sizeof(t_list));
	elem->x = map;
	elem->y = ab;
<<<<<<< HEAD
	elem->x2 = map + stop;
	elem->y2 = (ab + 30) - y2;
=======
>>>>>>> parent of 503ec73... all
	elem->z = alt;
	elem->next = NULL;
	if (lst == NULL)
		return (elem);
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = elem;
	return(begin);
}
