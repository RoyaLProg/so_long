/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:58:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/03 13:58:35 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	switch_image(void *screen, t_window *w)
{
	t_image	new;
	t_image	*ptr;

	ptr = w->current;
	w->current = w ->next;
	mlx_put_image_to_window(screen, w->window, w->current, 0, 0);
	if (ptr != NULL)
	{
		mlx_destroy_image(screen, ptr);
	}
	new.img = mlx_new_image(screen, w->width, w->height);
	new.addr = mlx_get_data_addr(new.img, &new.bits_per_pixel,
			&new.line_length, &new.endian);
	w->next = &new;
}
