/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:30:01 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/07 19:16:39 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_generation(char **map, t_tileset *t, t_image *img)
{
	size_t	i;
	size_t	j;
	int		*coords;
	int		*scoords;

	coords = malloc(sizeof(int) * 3);
	scoords = malloc(sizeof(int) * 3);
	if (coords == NULL)
		return ;
	if (scoords == NULL)
		return ;
	coords[2] = (int)0;
	scoords[2] = (int)0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			coords[1] = i;
			coords[0] = j;
			if (map[i][j] == '1')
			{
				scoords[0] = 1;
				scoords[1] = 2;
				put_sprite(t, scoords, coords, img);
			}
			if (map[i][j] == '0' || map[i][j] == 'E' || map[i][j] == 'C'
				|| map[i][j] == 'P')
			{
				scoords[0] = 0;
				scoords[1] = 2;
				put_sprite(t, scoords, coords, img);
			}
		}
	}
	free(coords);
	free(scoords);
}
