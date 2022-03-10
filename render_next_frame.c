/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:56:04 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/09 05:58:14 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	render_next_frame(t_vars *vars)
{
	map_generation(vars->t->map, vars->t, vars->w->next);
	if (is_on_collectible(vars->p, vars->c))
		take_collectible(vars->c);
	put_collectible(vars);
	put_character(vars->w->window, vars->p, vars->w->next, vars->t);
	switch_image(vars->w->screen, vars->w);
}
