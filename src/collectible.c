/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:31:12 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/25 16:59:50 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_next_collectible(t_collec *c, t_vars *v)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (v->t->map[i])
	{
		j = 0;
		while (v->t->map[i][j])
		{
			if (v->t->map[i][j] == 'C')
			{
				c->pos[0] = j;
				c->pos[1] = i;
				v->t->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

int	count_collec(char **map)
{
	size_t	i;
	size_t	j;
	size_t	v;

	v = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				v += 1;
			j++;
		}
		i++;
	}
	return (v);
}

void	put_collectible(t_collec *c, t_vars *v)
{
	if (is_near(v->c->pos, c->pos) || is_on_collectible(v->p, c))
	{
		if (c->state)
			mlx_put_image_to_window(v->w->screen, v->w->window, v->t->chest[2],
				c->pos[0] * 32, c->pos[1] * 32);
		else
			mlx_put_image_to_window(v->w->screen, v->w->window, v->t->chest[1],
				c->pos[0] * 32, c->pos[1] * 32);
	}
	else
		mlx_put_image_to_window(v->w->screen, v->w->window, v->t->chest[0],
			c->pos[0] * 32, c->pos[1] * 32);
}

void	collec_foreach(t_collec *head, void (*f)(), t_vars *param)
{
	t_collec	*x;

	x = head;
	while (x != NULL)
	{
		f((t_collec *)x, param);
		x = (t_collec *)x->next;
	}
}
