/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:59:30 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/26 14:45:30 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "libft.h"

t_list		*ft_create_elem(t_list *lst, int z, t_base *s)
{
	t_list 		*elem;
	t_list 		*begin;

	begin = lst;
	elem = malloc(sizeof(t_list));
	elem->x = s->x;
	elem->y = s->y;
	elem->z = z;
	elem->next = NULL;
	ft_putnbr(z);
	if (!lst)
		return (elem);
	while (lst->next != NULL)
	{
	ft_putstr("blabl");
		lst = lst->next;
	}

	lst->next = elem;
	return(begin);
}
