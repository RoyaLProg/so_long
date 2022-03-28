/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:30:01 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/25 18:04:51 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_generation(t_vars *v)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (v->t->map[++i])
	{
		j = -1;
		while (v->t->map[i][++j])
		{
			if (v->t->map[i][j] == '1')
			{
				mlx_put_image_to_window(v->w->screen, v->w->window, v->t->water,
					j * 32, i * 32);
			}
			if (v->t->map[i][j] == '0' || v->t->map[i][j] == 'C'
				|| v->t->map[i][j] == 'E' || v->t->map[i][j] == 'P'
			)
			{
				mlx_put_image_to_window(v->w->screen, v->w->window, v->t->sand,
					j * 32, i * 32);
			}
		}
	}
}
