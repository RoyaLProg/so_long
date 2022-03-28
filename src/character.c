/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:14:36 by ccambium          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/23 16:09:32 by ccambium         ###   ########.fr       */
=======
/*   Updated: 2022/03/26 19:11:44 by ccambium         ###   ########.fr       */
>>>>>>> 9649069b768d375e9289692e273b5291db149d71
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	player_on_collect(t_vars *v)
{
	t_collec	*x;

	x = v->c;
	while (x)
	{
		if (v->p->pos[0] == x->pos[0] && v->p->pos[1] == x->pos[1])
			return (1);
		x = x->next;
	}
	return (0);
}

void	put_character(t_vars *v)
{
	if (player_on_collect(v))
		mlx_put_image_to_window(v->w->screen, v->w->window, v->t->character[1],
			v->p->pos[0] * 32, v->p->pos[1] * 32);
	else
		mlx_put_image_to_window(v->w->screen, v->w->window, v->t->character[0],
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
