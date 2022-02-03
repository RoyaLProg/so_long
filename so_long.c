/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:58:11 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/03 13:46:24 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	main(void)
{
	void		*screen;
	t_window	w;
	t_image		image;
	t_tileset	tileset;

	screen = mlx_init;
	w.window = mlx_new_window(screen, w.width, w.height, "./so_long");
	image.img = mlx_new_image(screen, w.width, w.height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	w.next = &image;
	w.current = NULL;
	xpm_to_sprite(&tileset);
}
