/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tileset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:55 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/26 19:34:19 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tileset	*tileset_load(t_vars *v)
{
	v->t->character[0] = mlx_xpm_file_to_image(v->w->screen,
			"tileset/character.xpm", &v->t->tile_width, &v->t->tile_height);
	v->t->character[1] = mlx_xpm_file_to_image(v->w->screen,
			"tileset/character2.xpm", &v->t->tile_width, &v->t->tile_height);
	v->t->sand = mlx_xpm_file_to_image(v->w->screen, "tileset/sand.xpm",
			&v->t->tile_width, &v->t->tile_height);
	v->t->water = mlx_xpm_file_to_image(v->w->screen, "tileset/water.xpm",
			&v->t->tile_width, &v->t->tile_height);
	v->t->chest[0] = mlx_xpm_file_to_image(v->w->screen,
			"tileset/chest1.xpm", &v->t->tile_width, &v->t->tile_height);
	v->t->chest[1] = mlx_xpm_file_to_image(v->w->screen,
			"tileset/chest2.xpm", &v->t->tile_width, &v->t->tile_height);
	v->t->chest[2] = mlx_xpm_file_to_image(v->w->screen,
			"tileset/chest3.xpm", &v->t->tile_width, &v->t->tile_height);
	v->t->exit = mlx_xpm_file_to_image(v->w->screen,
			"tileset/exit.xpm", &v->t->tile_width, &v->t->tile_height);
	return (v->t);
}

void	tileset_safeend(t_vars *v)
{
	mlx_destroy_image(v->w->screen, v->t->character[0]);
	mlx_destroy_image(v->w->screen, v->t->character[1]);
	mlx_destroy_image(v->w->screen, v->t->exit);
	mlx_destroy_image(v->w->screen, v->t->sand);
	mlx_destroy_image(v->w->screen, v->t->water);
	mlx_destroy_image(v->w->screen, v->t->chest[0]);
	mlx_destroy_image(v->w->screen, v->t->chest[1]);
	mlx_destroy_image(v->w->screen, v->t->chest[2]);
}
