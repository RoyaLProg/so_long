/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:56:04 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/10 05:30:32 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	render_next_frame(t_vars *vars)
{
	map_generation(vars->t->map, vars->t, vars->w->next);
	collec_foreach(vars->c, take_collectible, vars);
	collec_foreach(vars->c, put_collectible, vars);
	put_character(vars->w->window, vars->p, vars->w->next, vars->t);
	switch_image(vars->w->screen, vars->w);
}
