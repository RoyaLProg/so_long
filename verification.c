/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:58:11 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/18 12:54:41 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_up_down_wall(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '\n')
		{
			ft_printf("Error\nmap not surronded by walls\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	is_map_rect(char **map)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
	{
		if (len != ft_strlen(map[i]))
		{
			ft_printf("Error\nmap not rectangular\n");
			return (0);
		}
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
	if (!v[0] || v[1] != 1 || !v[2])
		return (0);
	return (1);
}

static int	char_conform(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C'
				&& map[i][j] != 'E'
				&& map[i][j] != 'P'
				&& map[i][j] != '0'
				&& map[i][j] != '1'
				&& map[i][j] != '\n'
			)
			{
				ft_printf("Error \nmap contain illegal char :\
					%c\n", map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	map_verification(char **map, t_vars *game, char *mappath)
{
	size_t	i;

	if (map == NULL)
	{
		ft_printf("Error\n map either empty or inexisting\n");
		return (1);
	}
	if (!is_dot_ber(mappath))
		return (1);
	i = is_map_rect(map);
	if (!i)
		return (1);
	if (is_up_down_wall(map[0]) || is_up_down_wall(map[i - 1]))
		return (1);
	if (!char_conform(map))
		return (1);
	game->w->height = i * 32;
	game->w->width = (ft_strlen(map[0]) - 1) * 32;
	return (verification2(map, i));
}
