/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:56:04 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/14 12:59:44 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	render_next_frame(void *v)
{
	t_vars	*vars;

	vars = (t_vars *)v;
	update_frame(vars);
	map_generation(vars->t->map, vars->t, vars->w->next);
	put_character(vars->w->window, vars->p, vars->w->next, vars->t);
}

int	update_frame(void *v)
{
	t_vars	*vars;

	vars = (t_vars *)v;
	move(vars->p);
	switch_image(vars->w->screen, vars->w);
}
