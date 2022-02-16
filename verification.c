/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:58:11 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/16 09:25:47 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_up_down_wall(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' || s[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	is_map_rect(char **map)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (i);
}

int	is_there_requirements(char **map)
{
	int		v[3];
	size_t	i;
	size_t	j;

	i = -1;
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	while (map[++i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				v[0]++;
			if (map[i][j] == 'P')
				v[1]++;
			if (map[i][j] == 'E')
				v[2]++;
			j++;
		}
	}
	if (!v[0] || !v[1] || !v[2])
		return (0);
	return (1);
}

int	map_verification(char **map, t_game *game)
{
	int		fd;
	size_t	i;

	i = is_map_rect(map);
	if (!i)
		return (1);
	if (is_up_down_wall(map[0]) || is_up_down_wall(map[i - 1]))
		return (1);
	if (!is_there_requirements(map))
		return (1);
	game->w->height = i * 32;
	game->w->width = ft_strlen(map[0]) * 32;
	return (0);
}
