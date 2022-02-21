/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:25:08 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/21 13:24:44 by ccambium         ###   ########.fr       */
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

int	will_collide_wall(int *pos, char **map)
{
	return (
		(pos[0] / 32 == 0)
		|| (pos[0] / 32 == ft_strlen(map[0]))
		|| (pos[1] / 32 == 0)
		|| (pos[1] / 32 == sizeof(map))
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
