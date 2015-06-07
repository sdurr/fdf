/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 12:49:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/06/07 12:55:43 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**split(char *s)
{
	char **split;
	int i;
	int j;
	int k;

	j = 0;
	i = 1;
	while (s[j])
	{
		if (s[j] == ' ')
			i++;
		j++;
	}
	if (!(split = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != ' ' && s[i])
		{
			split[j][k] = s[i];
			k++;
		}
		j++;
	}
	split[j] = NULL;
	return (split);
}
