/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:31:12 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/17 09:37:31 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_collectible(char **map, t_game *game)
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
			ft_pixel_put(img, coord[0] + j, coord[1] + i,
				get_color_by_char(colors, sprite[i][j]));
			j++;
		}
		i++;
	}
	free_split(sprite);
}

void	put_collectible(t_window *w, t_collec *c, t_image *img, t_tileset *t)
{
	char	**sprite;

	if (c->state == 0)
		put_collectible_to_img(get_sprite(t, 14, 0),
			c->pos, t->colors, img);
	else
		put_collectible_to_img(get_sprite(t, 14, 0),
			c->pos, t->colors, img);
}
