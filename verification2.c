/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:51:45 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/18 12:54:09 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_dot_ber(char *mappath)
{
	size_t	i;

	i = ft_strlen(mappath);
	i--;
	if (mappath[i] == 'r'
		&& mappath[i - 1] == 'e'
		&& mappath[i - 2] == 'b'
		&& mappath[i - 3] == '.'
	)
	{
		return (1);
	}
	ft_printf ("Error\n not a .ber map\n");
	return (0);
}

int	surround_by_wall(char **map, size_t	i)
{
	size_t	j;

	j = 1;
	while (j < i - 1)
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 2] != '1')
		{
			ft_printf("Error\nmap not surronded by walls\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	verification2(char **map, size_t i)
{
	if (!is_there_requirements(map))
	{
		ft_printf(
			"Error\n map missing one of these elements :\n\
			a starting position\n\
			a collectible\n\
			an exit\n"
			);
		return (1);
	}
	if (!surround_by_wall(map, i))
		return (1);
	return (0);
}
