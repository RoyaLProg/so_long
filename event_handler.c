/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:19:10 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/03 14:19:10 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

enum e_events{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_keycodes
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
};

int	ft_close(int keycode, t_vars *vars)
{
	exit(1);
}

int	ft_keys(int keycode, t_player *p)
{
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_W)
		change_direction(p, 0, -8);
	if (keycode == KEY_A)
		change_direction(p, -8, 0);
	if (keycode == KEY_S)
		change_direction(p, 0, 8);
	if (keycode == KEY_D)
		change_direction(p, 8, 0);
}

int	ft_reset(int keycode, t_player *p)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		change_direction(p, 0, 0);
	}
}

void	event_handler(t_player *p, t_window *w)
{
	t_vars	vars;

	mlx_hook(w->window, ON_DESTROY, 0, ft_close, NULL);
	mlx_hook(w->window, ON_KEYDOWN, 1L << 0, ft_keys, p);
	mlx_hook(w->window, ON_KEYUP, 1L << 1, ft_reset, p);
}
