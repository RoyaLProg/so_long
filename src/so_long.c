/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:58:11 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/26 20:12:56 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	so_long(t_vars *v, char *map_path)
{
	if (map_verification(v->t->map, v, map_path))
	{
		if (v->t->map != NULL)
			free_split(v->t->map);
		free(v->c);
		free(v->e);
		return ;
	}
	v->w->screen = mlx_init();
	if (v->w->screen == NULL)
		return (write(1, "Error\nScreen failed", 19));
	v->w->window = mlx_new_window(v->w->screen, v->w->width,
			v->w->height, "./so_long");
	v->count = 0;
	tileset_load(v);
	refresh_count(v);
	locate_player(v->t->map, v);
	locate_collec(v->c, v);
	locate_exit(v->e, v);
	event_handler(v);
	mlx_loop_hook(v->w->screen, render_next_frame, v);
	mlx_loop(v->w->screen);
	safe_end(v);
}

int	main(int ac, char **av)
{
	t_vars		v;
	t_window	w;
	t_tileset	t;
	t_player	p;

	if (ac != 2)
	{
		printf("Error\n no map given\n");
		return (1);
	}
	v.p = &p;
	v.t = &t;
	v.w = &w;
	v.c = (t_collec *)malloc(sizeof(t_collec));
	v.e = (t_exit *)malloc(sizeof(t_exit));
	t.map = map_to_tab(av[1]);
	so_long(&v, av[1]);
	return (1);
}
