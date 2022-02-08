#include <stdio.h>
#include "so_long.h"
#include <mlx.h>

int main(int ac, char **av)
{
	t_tileset test;
	t_window window;
	t_image img;
	t_image img2;
	void *screen;
	size_t i;
	char **map;
	t_player player;

	screen = mlx_init();
	window.screen = screen;
	player.animation = 0;
	player.pos = malloc(sizeof(int) * 2);
	player.pos[0] = 1;
	player.pos[1] = 5;
	player.dir = malloc(sizeof(int) * 2);
	window.window = mlx_new_window(screen, 900, 900, "test");
	img.img = mlx_new_image(screen, 900, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img2.img = mlx_new_image(screen, 900, 900);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length,
								&img2.endian);
	window.s_layer = &img;
	window.m_layer = &img2;
	test.path = "tileset/Beach Tileset.xpm";
	i = 0;
	xpm_to_sprite(&test);
	map = map_to_tab("maps/map1.ber");
	map_generation(map, &test, window.s_layer);
	put_character(&window, &player, window.s_layer, &test);
	mlx_put_image_to_window(screen, window.window, window.s_layer->img, 0, 0);
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
	free(player.pos);
	free(player.dir);
	free_split(test.img);
	free_split(map);
}
