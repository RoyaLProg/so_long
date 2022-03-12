/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 07:23:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/12 07:26:32 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
