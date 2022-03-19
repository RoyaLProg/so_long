/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 07:27:01 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/17 10:12:30 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_exit_to_img(char **sprite, int *coord,
								char ***colors, void *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			if (sprite[i][j] == '8')
			{
				j++;
				continue ;
			}
			ft_pixel_put(img, (coord[0] * 32) + j, (coord[1] * 32) + i,
				get_color_by_char(colors, sprite[i][j]));
			j++;
		}
		i++;
	}
	free_split(sprite);
}

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
	put_exit_to_img(get_sprite(v->t, 0, 0),
		e->pos, v->t->colors, v->w->next);
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
