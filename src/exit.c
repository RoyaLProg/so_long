/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 07:27:01 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/25 16:59:32 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_exit(char **map)
{
	size_t	i;
	size_t	j;
	size_t	v;

	v = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				v++;
			j++;
		}
		i++;
	}
	return (v);
}

void	put_exit(t_exit *e, t_vars *v)
{
	mlx_put_image_to_window(v->w->screen, v->w->window, v->t->exit,
		e->pos[0] * 32, e->pos[1] * 32);
}

void	exit_foreach(t_exit *head, void (*f)(), t_vars *param)
{
	t_exit	*x;

	x = head;
	while (x != NULL)
	{
		f((t_exit *)x, param);
		x = (t_exit *)x->next;
	}
}

void	ft_on_exit(t_exit *e, t_vars *v)
{
	if (v->p->pos[0] == e->pos[0]
		&& v->p->pos[1] == e->pos[1])
	{
		exit(0);
	}
}
