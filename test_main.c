#include <stdio.h>
#include "so_long.h"
#include <mlx.h>

int main(int ac, char **av)
{
	t_tileset test;
	t_window window;
	t_image img;
	void *screen;
	size_t i;
	int *coord;
	int *coord2;

	screen = mlx_init();
	window.window = mlx_new_window(screen, 500, 500, "test");
	img.img = mlx_new_image(screen, 32, 32);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	window.next = &img;
	test.path = "tileset/Beach Tileset.xpm";
	i = 0;
	coord = malloc(sizeof(int) * 3);
	coord2 = malloc(sizeof(int) * 3);
	if (ac == 3)
	{
		coord[0] = ft_atoi(av[1]);
		coord[1] = ft_atoi(av[2]);
		coord[2] = 0;
	}
	else
	{
		coord[0] = 0;
		coord[1] = 0;
		coord[2] = 0;
	}
	coord2[0] = 0;
	coord2[1] = 0;
	coord2[2] = 0;
	xpm_to_sprite(&test);
	put_sprite(&test, coord, coord2, &img);
	mlx_put_image_to_window(screen, window.window, window.next->img, 0, 0);
	mlx_loop(screen);
	while (test.colors[i])
	{
		free(test.colors[i][0]);
		free(test.colors[i][1]);
		free(test.colors[i][2]);
		free(test.colors[i]);
		i++;
	}
	free(test.colors[i]);
	free(test.colors);
	free_split(test.img);
}
