#include <stdio.h>
#include "so_long.h"
#include <mlx.h>

int main(int ac, char **av)
{
	t_tileset test;
	t_window window;
	t_image img;
	t_image img2;
	t_game	g;
	t_vars	vars;
	t_collec c;
	void *screen;
	size_t i;
	t_player player;

	screen = mlx_init();
	window.screen = screen;
	player.animation = 0;
	player.pos[0] = 10;
	player.pos[1] = 10;
	player.dir[0] = 0;
	player.dir[1] = 0;
	window.window = mlx_new_window(screen, 900, 900, "test");
	//img = (t_image *)malloc(sizeof(t_image));
	//img2 = (t_image *)malloc(sizeof(t_image));
	img.img = mlx_new_image(screen, 900, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img2.img = mlx_new_image(screen, 900, 900);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length,
								&img2.endian);
	window.current = &img2;
	window.next = &img;
	test.path = "tileset/Beach Tileset.xpm";
	i = 0;
	vars.p = &player;
	vars.t = &test;
	vars.w = &window;
	xpm_to_sprite(&test);
	test.map = map_to_tab("maps/map1.ber");
	c.pos[0] = 5;
	c.pos[1] = 5;
	event_handler(&player, &window);
	mlx_loop_hook(screen, render_next_frame, &vars);
	render_next_frame(&vars);
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
	free_split(test.map);
}
