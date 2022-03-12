/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:14:36 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/12 08:39:42 by ccambium         ###   ########.fr       */
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
				map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	put_chara_to_img(char **sprite, int *coord, char ***colors, void *img)
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

void	put_character(t_window *w, t_player *p, t_image *img, t_tileset *t)
{
	char	**sprite;

	if (p->animation == 0)
		put_chara_to_img(get_sprite(t, 14, 0),
			p->pos, t->colors, img);
	else
		put_chara_to_img(get_sprite(t, 14 + p->animation - 1, 2),
			p->pos, t->colors, img);
}

void	move(t_player *p, t_vars *v, int x, int y)
{
	p->dir[0] = x;
	p->dir[1] = y;
	if (will_collide_wall(p->pos, p->dir, v->t->map))
	{
		p->state = 1;
		return ;
	}
	p->pos[0] += x;
	p->pos[1] += y;
	p->state = 1;
}
