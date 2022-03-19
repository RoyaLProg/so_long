/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 07:23:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/18 10:07:57 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_collec(t_collec *head, t_vars *v)
{
	int			x;
	int			i;
	t_collec	*tmp;
	t_collec	*y;

	x = count_collec(v->t->map);
	i = 0;
	y = head;
	y->state = 1;
	while (i < x - 1)
	{
		tmp = (t_collec *)malloc(sizeof(t_collec));
		tmp->state = 1;
		y->next = tmp;
		y = tmp;
		i++;
	}
	y->next = NULL;
	collec_foreach(head, locate_next_collectible, v);
}

int	all_collect_taken(t_collec *head)
{
	t_collec	*x;

	x = head;
	while (x != NULL)
	{
		if (x->state == 1)
			return (0);
		x = (t_collec *)x->next;
	}
	return (1);
}

void	free_collec(t_collec *head)
{
	if (head == NULL)
		return ;
	free_collec((t_collec *)head->next);
	free(head);
}
