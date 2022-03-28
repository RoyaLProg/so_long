/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:09:57 by ccambium          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/23 16:09:54 by ccambium         ###   ########.fr       */
=======
/*   Updated: 2022/03/26 19:35:21 by ccambium         ###   ########.fr       */
>>>>>>> 9649069b768d375e9289692e273b5291db149d71
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	safe_end(t_vars	*v)
{
<<<<<<< HEAD
	size_t	i;

	i = 0;
	while (v->t->colors[i])
	{
		free(v->t->colors[i][0]);
		free(v->t->colors[i][1]);
		free(v->t->colors[i][2]);
		free(v->t->colors[i]);
		i++;
	}
	free(v->t->colors[i]);
	free(v->t->colors);
	free_split(v->t->img);
=======
>>>>>>> 9649069b768d375e9289692e273b5291db149d71
	free_split(v->t->map);
	free_collec(v->c);
	free_exit(v->e);
	tileset_safeend(v);
	mlx_destroy_window(v->w->screen, v->w->window);
	mlx_destroy_display(v->w->screen);
}
