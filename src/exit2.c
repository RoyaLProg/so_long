/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:58:26 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/17 12:19:05 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_next_exit(t_exit *e, t_vars *v)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (v->t->map[i])
	{
		j = 0;
		while (v->t->map[i][j])
		{
			if (v->t->map[i][j] == 'E')
			{
				e->pos[0] = j;
				e->pos[1] = i;
				v->t->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	locate_exit(t_exit *head, t_vars *v)
{
	int		x;
	int		i;
	t_exit	*tmp;
	t_exit	*y;

	x = count_exit(v->t->map);
	i = 0;
	y = head;
	while (i < x - 1)
	{
		tmp = (t_exit *)malloc(sizeof(t_exit));
		y->next = tmp;
		y = tmp;
		i++;
	}
	y->next = NULL;
	exit_foreach(head, locate_next_exit, v);
}

void	free_exit(t_exit *head)
{
	if (head == NULL)
		return ;
	free_exit(head->next);
	free(head);
}
