/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:14:36 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/03 06:38:03 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	locate_player(char **map, t_game *game)
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
				game->p->pos[0] = j;
				game->p->pos[1] = i;
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
			ft_pixel_put(img, coord[0] + j, coord[1] + i,
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

void	change_direction(t_player *p, int x, int y)
{
	p->dir[0] = x;
	p->dir[1] = y;
}

void	move(t_player *p, t_vars *vars)
{
	int	i;

	i = 0;
	p->state = 0;
	p->animation = 1;
	while (i < 4)
	{
		p->pos[0] += 8 * p->dir[0];
		p->pos[1] += 8 * p->dir[1];
		p->animation += 1;
		if (p->animation == 5)
			p->animation = 0;
		map_generation(vars->t->map, vars->t, vars->w->next);
		put_character(vars->w->window, vars->p, vars->w->next, vars->t);
		mlx_put_image_to_window(vars->w->screen, vars->w->window, vars->w->next->img, 0, 0);
		i++;
	}
	p->animation = 0;
	p->state = 1;
}
