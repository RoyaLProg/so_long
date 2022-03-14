#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"
#include <mlx.h>

int	main(int ac, char **av)
{
	if (ac == 1)
		return (1);

	t_tileset test;
	t_window window;
	t_image img;
	t_image img2;
	t_vars	vars;
	t_exit	e;
	t_collec c;
	t_collec c2;
	void *screen;
	size_t i;
	t_player player;

	vars.p = &player;
	vars.t = &test;
	vars.w = &window;
	vars.c = &c;
	vars.e = &e;
	test.map = map_to_tab("maps/map1.ber");
	if (map_verification(test.map, &vars))
	{
		free_split(test.map);
		return (1);
	}
	screen = mlx_init();
	window.screen = screen;
	player.animation = 0;
	player.pos[0] = 5;
	player.pos[1] = 3;
	player.dir[0] = 0;
	player.dir[1] = 0;
	player.state = 1;
	window.window = mlx_new_window(screen, window.width, window.height, "test");
	img.img = mlx_new_image(screen, window.width, window.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img2.img = mlx_new_image(screen, window.width, window.height);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length,
			&img2.endian);
	window.current = &img2;
	window.next = &img;
	test.path = "tileset/Beach Tileset.xpm";
	i = 0;
	xpm_to_sprite(&test);
	c.pos[0] = 5;
	c.pos[1] = 5;
	c.state = 1;
	c.next = &c2;
	c2.pos[0] = 9;
	c2.pos[1] = 3;
	c2.state = 1;
	c2.next = NULL;
	e.next = NULL;
	e.pos[1] = 2;
	e.pos[0] = 10;
	event_handler(&vars);
	mlx_loop_hook(screen, render_next_frame, &vars);
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
