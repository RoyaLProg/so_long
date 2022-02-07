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

typedef struct s_vars{
	void	*mlx;
	void	*win;
}	t_vars;

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

int	ft_keys(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(1);
}

void	event_handler(void *screen, void *window)
{
	t_vars	vars;

	vars.win = window;
	vars.mlx = screen;

	mlx_hook(vars.win, ON_DESTROY, 0, ft_close, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, 1L << 0, ft_keys, &vars);
}
