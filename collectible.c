/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:31:12 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/12 08:36:32 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_collectible(char **map, t_vars *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				game->c->pos[0] = j;
				game->c->pos[1] = i;
				map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	put_collectible_to_img(char **sprite, int *coord,
								char ***colors, void *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			if (sprite[i][j] == '8')
			{
				j++;
				continue ;
			}
			ft_pixel_put(img, (coord[0] * 32) + j, (coord[1] * 32) + i,
				get_color_by_char(colors, sprite[i][j]));
			j++;
		}
		i++;
	}
	free_split(sprite);
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
	if (is_near(v->p->pos, c->pos) || is_on_collectible(v->p, c))
	{
		if (c->state)
			put_collectible_to_img(get_sprite(v->t, 3, 0),
				c->pos, v->t->colors, v->w->next);
		else
			put_collectible_to_img(get_sprite(v->t, 2, 0),
				c->pos, v->t->colors, v->w->next);
	}
	else
		put_collectible_to_img(get_sprite(v->t, 1, 0),
			c->pos, v->t->colors, v->w->next);
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
