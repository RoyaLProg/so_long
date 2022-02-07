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
	char **map;
	t_player player;

	screen = mlx_init();
	window.window = mlx_new_window(screen, 900, 900, "test");
	img.img = mlx_new_image(screen, 900, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	window.next = &img;
	test.path = "tileset/Beach Tileset.xpm";
	i = 0;
	xpm_to_sprite(&test);
	map = map_to_tab("maps/map1.ber");
	map_generation(map, &test, window.next);
	mlx_put_image_to_window(screen, window.window, window.next->img, 0, 0);
	event_handler(screen, window.window);
	mlx_loop(screen);
	mlx_destroy_window(screen, window.window);
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
	free_split(map);
}
