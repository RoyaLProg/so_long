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

void	switch_image(void *screen, t_window *w)
{
	t_image	*ptr;

	ptr = w->current;
	w->current = w ->next;
	w->next = ptr;
	mlx_put_image_to_window(screen, w->window, w->current->img, 0, 0);
}
