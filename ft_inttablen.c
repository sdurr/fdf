/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttablen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 13:49:24 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/07 13:50:18 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_inttablen(int **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i + 2);
}
