/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:09:57 by ccambium          #+#    #+#             */
/*   Updated: 2022/05/02 14:44:25 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	safe_end(t_vars	*v)
{
	free_split(v->t->map);
	free_collec(v->c);
	free_exit(v->e);
	tileset_safeend(v);
	mlx_destroy_window(v->w->screen, v->w->window);
	mlx_destroy_display(v->w->screen);
}
