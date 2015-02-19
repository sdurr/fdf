/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:52:35 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/19 17:13:06 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

t_list		*ft_create_elem(t_list *lst, int map, int ab, int alt, int y2)
{
	t_list *elem;
	t_list *begin;

	begin = lst;
	elem = malloc(sizeof(t_list));
	elem->x = map;
	elem->y = ab;
	elem->x2 = map + 20;
	elem->y2 = ab + 20 - y2;
	elem->z = alt;
	elem->next = NULL;
	if (lst == NULL)
		return (elem);
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = elem;
	return(begin);
}
