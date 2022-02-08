/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:14:36 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/08 03:35:36 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		put_chara_to_img(get_sprite(t, 14, 0), p->pos, t->colors, img);
	else
	{
		put_chara_to_img(get_sprite(t, 14 + p->animation / 10, 0),
			p->pos, t->colors, img);
	}
}

