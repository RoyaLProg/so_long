/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:56:04 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/25 17:29:40 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	render_next_frame(t_vars *vars)
{
	if (all_collect_taken(vars->c))
		exit_foreach(vars->e, ft_on_exit, vars);
	map_generation(vars);
	collec_foreach(vars->c, take_collectible, vars);
	collec_foreach(vars->c, put_collectible, vars);
	if (all_collect_taken(vars->c))
		exit_foreach(vars->e, put_exit, vars);
	put_character(vars);
	return (1);
}
