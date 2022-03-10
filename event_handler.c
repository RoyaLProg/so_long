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

int	ft_close(int keycode)
{
	exit(1);
}

int	ft_keys(int keycode, t_vars *v)
{
	if (v->p->state == 0)
		return (1);
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_W)
	{
		v->p->state = 0;
		move(v->p, v, 0, -1);
	}
	if (keycode == KEY_A)
	{
		v->p->state = 0;
		move(v->p, v, -1, 0);
	}
	if (keycode == KEY_S)
	{
		v->p->state = 0;
		move(v->p, v, 0, 1);
	}
	if (keycode == KEY_D)
	{
		v->p->state = 0;
		move(v->p, v, 1, 0);
	}
}

void	event_handler(t_vars *vars)
{
	mlx_hook(vars->w->window, ON_DESTROY, 0, ft_close, NULL);
	mlx_hook(vars->w->window, ON_KEYDOWN, 1L << 0, ft_keys, vars);
}
