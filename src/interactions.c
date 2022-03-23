/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 05:55:04 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/23 16:09:45 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_collectible(t_collec *c, t_vars *vars)
{
	if (is_on_collectible(vars->p, c))
		c->state = 0;
}
