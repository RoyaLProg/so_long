/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:48:00 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/08 03:32:11 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ft_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color_by_char(char ***colors, char c)
{
	size_t	i;

	if (c == '8')
		return (0xFF000000);
	i = 0;
	while (colors[i])
	{
		if (colors[i][0][0] == c)
			return (hex_to_int(colors[i][1]));
		i++;
	}
}

void	put_sprite_to_img(char **sprite, int *coord, char ***colors, void *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			ft_pixel_put(img, coord[0] * 32 + j, coord[1] * 32 + i,
				get_color_by_char(colors, sprite[i][j]));
			j++;
		}
		i++;
	}
}

char	**get_sprite(t_tileset *sprite, int x, int y)
{
	char	**v;
	size_t	i;

	i = 0;
	v = malloc(sizeof(char *) * 33);
	if (v == NULL)
		return (NULL);
	while (i < 32)
	{
		v[i] = ft_substr(sprite->img[y * 32 + i], x * 32, 32);
		i++;
	}
	v[i] = NULL;
	return (v);
}

void	put_sprite(t_tileset *t, int *s_coord, int *coord, t_image *img)
{
	char	**sprite;
	size_t	i;

	sprite = get_sprite(t, s_coord[0], s_coord[1]);
	put_sprite_to_img(sprite, coord, t->colors, img);
	free_split(sprite);
}
