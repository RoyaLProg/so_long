/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:30:01 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/18 12:52:16 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_generation2(t_vars *v, size_t i, size_t j, int *coords)
{
	int	*scoords;

	scoords = malloc(sizeof(int) * 2);
	if (scoords == NULL)
		return ;
	coords[1] = i;
	coords[0] = j;
	if (v->t->map[i][j] == '1')
	{
		scoords[0] = 1;
		scoords[1] = 2;
		put_sprite(v->t, scoords, coords, v->w->next);
	}
	if (v->t->map[i][j] == '0' || v->t->map[i][j] == 'C'
		|| v->t->map[i][j] == 'E' || v->t->map[i][j] == 'P'
	)
	{
		scoords[0] = 0;
		scoords[1] = 2;
		put_sprite(v->t, scoords, coords, v->w->next);
	}
	free(scoords);
}

void	map_generation(t_vars *v)
{
	size_t	i;
	size_t	j;
	int		*coords;

	coords = malloc(sizeof(int) * 2);
	if (coords == NULL)
		return ;
	i = -1;
	while (v->t->map[++i])
	{
		j = -1;
		while (v->t->map[i][++j])
		{
			map_generation2(v, i, j, coords);
		}
	}
	free(coords);
}
