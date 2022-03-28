/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:56:04 by ccambium          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/23 16:09:51 by ccambium         ###   ########.fr       */
=======
/*   Updated: 2022/03/26 19:15:49 by ccambium         ###   ########.fr       */
>>>>>>> 9649069b768d375e9289692e273b5291db149d71
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_vars *vars)
{
	mlx_clear_window(vars->w->screen, vars->w->window);
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
