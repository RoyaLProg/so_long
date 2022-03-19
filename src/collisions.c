/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:25:08 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/09 05:57:26 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	will_collide_wall(int *pos, int *dir, char **map)
{
	return (map[pos[1] + dir[1]][pos[0] + dir[0]] == '1');
}

int	is_on_collectible(t_player *p, t_collec *c)
{
	return (p->pos[0] == c->pos[0] && p->pos[1] == c->pos[1]);
}

int	is_near(int	*pos1, int *pos2)
{
	return (
		(pos1[0] == pos2[0] - 1
			&& pos1[1] == pos2[1] + 1)
		|| (pos1[0] == pos2[0] + 1
			&& pos1[1] == pos2[1] + 1)
		|| (pos1[0] == pos2[0] - 1
			&& pos1[1] == pos2[1] - 1)
		|| (pos1[0] == pos2[0] + 1
			&& pos1[1] == pos2[1] - 1)
		|| (pos1[0] == pos2[0]
			&& pos1[1] == pos2[1] - 1)
		|| (pos1[0] == pos2[0]
			&& pos1[1] == pos2[1] + 1)
		|| (pos1[0] == pos2[0] + 1
			&& pos1[1] == pos2[1])
		|| (pos1[0] == pos2[0] - 1
			&& pos1[1] == pos2[1])
	);
}
