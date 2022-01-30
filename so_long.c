/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:58:11 by ccambium          #+#    #+#             */
/*   Updated: 2022/01/29 22:02:27 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_put_square(t_image *data, int x, int y, int width,
			int height, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i == 0 || i == height - 1)
				my_mlx_pixel_put(data, x + j, y + i, color);
			else if (j == 0 || j == width - 1)
				my_mlx_pixel_put(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void		*screen;
	t_window	window;
	t_image		image;
	t_sprite	test;

	screen = mlx_init();
	test.path = "./tileset/Beach Tileset.xpm";
	test.img = mlx_xpm_file_to_image(screen, test.path, &test.img_width, &test.img_height);
	window.height = test.img_height;
	window.width = test.img_width;
	window.window = mlx_new_window(screen, window.width, window.height,
			"./so_long");
	//image.img = mlx_new_image(screen, window.height, window.width);
	//image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			//&image.line_length, &image.endian);
	//my_put_square(&image, window.height / 2 - 50, window.width / 2 - 50,
		//100, 100, 0x00FFFFFF);
	//mlx_put_image_to_window(screen, window.window, image.img, 0, 0);
	mlx_put_image_to_window(screen, window.window, test.img, 0, 0);
	mlx_loop(screen);
}
