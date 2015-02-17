/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:39:48 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/17 11:47:52 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int		key_hook(int keycode, t_env *e)
{
	e = e;
	if (keycode == 65307)
		exit(0);
	return (0);
}
