/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:14:36 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/25 18:22:54 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	locate_player(char **map, t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				vars->p->pos[0] = j;
				vars->p->pos[1] = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	put_character(t_vars *v)
{
	mlx_put_image_to_window(v->w->screen, v->w->window, v->t->character,
		v->p->pos[0] * 32, v->p->pos[1] * 32);
}

void	move(t_player *p, t_vars *v, int x, int y)
{
	p->dir[0] = x;
	p->dir[1] = y;
	if (will_collide_wall(p->pos, p->dir, v->t->map))
		return ;
	v->count++;
	refresh_count(v);
	p->pos[0] += x;
	p->pos[1] += y;
}
