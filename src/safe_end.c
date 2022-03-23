/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:09:57 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/23 14:56:39 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	safe_end(t_vars	*v)
{
	size_t	i;

	i = 0;
	while (v->t->colors[i])
	{
		free(v->t->colors[i][0]);
		free(v->t->colors[i][1]);
		free(v->t->colors[i][2]);
		free(v->t->colors[i]);
		i++;
	}
	free(v->t->colors[i]);
	free(v->t->colors);
	free_split(v->t->img);
	free_split(v->t->map);
	free_collec(v->c);
	free_exit(v->e);
	mlx_destroy_window(v->w->screen, v->w->window);
}
