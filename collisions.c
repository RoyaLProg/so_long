/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:25:08 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/25 16:18:29 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	will_collide(int *pos1, int	*pos2)
{
	int	p1;
	int	p2;
	int	p3;
	int	p4;

	if (pos1 != NULL)
	{
		p1 = pos1[0] / 32;
		p2 = pos1[1] / 32;
	}
	if (pos2 != NULL)
	{
		p3 = pos2[0] / 32;
		p4 = pos2[1] / 32;
	}
	if ((p1 == p3) && (p2 == p4))
		return (1);
	return (0);
}

int	will_inside_collide_wall(int *pos, int *dir, char **map)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = ft_ceil((pos[0] + dir[0]) / 32);
	y1 = ft_ceil((pos[1] + dir[1]) / 32);
	x2 = ft_flour((pos[0] + dir[0]) / 32);
	y2 = ft_flour((pos[1] + dir[1]) / 32);
	printf("x:%d y:%d\n", x2, y2);
	return (
		map[y1][x1] == '1'
		|| map[y2][x2] == '1'
	);
}

int	will_collide_wall(int *pos, int *dir, char **map)
{
	return (
		(pos[0] + dir[0]) < 32
		|| (pos[0] + dir[0]) > (ft_strlen(map[0]) - 3) * 32
		|| (pos[1] + dir[1]) < 32
		|| (pos[1] + dir[1]) > (sizeof(map) - 2) * 32
		|| will_inside_collide_wall(pos, dir, map)
	);
}

int	is_near(int	*pos1, int *pos2)
{
	return (
		pos1[0] / 32 >= pos2[0] - 1
		|| pos1[0] / 32 <= pos2[0] + 1
		|| pos1[1] / 32 >= pos2[1] - 1
		|| pos1[1] / 32 <= pos2[1] + 1
	);
}
