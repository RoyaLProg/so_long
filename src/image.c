/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:47:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/23 16:09:43 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_images(t_vars *vars)
{
	t_image	*v;
	t_image	*v2;

	v = (t_image *)malloc(sizeof(t_image));
	v2 = (t_image *)malloc(sizeof(t_image));
	v->img = mlx_new_image(vars->w->screen, vars->w->width, vars->w->height);
	v->addr = mlx_get_data_addr(v->img, &v->bits_per_pixel,
			&v->line_length, &v->endian);
	v2->img = mlx_new_image(vars->w->screen, vars->w->width, vars->w->height);
	v2->addr = mlx_get_data_addr(v2->img, &v2->bits_per_pixel,
			&v2->line_length, &v2->endian);
	vars->w->next = v;
	vars->w->current = v2;
}
