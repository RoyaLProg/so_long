/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:31:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/18 11:39:43 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

void	free_split(char **v)
{
	size_t	i;

	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

void	ft_clear(void)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		ft_printf("\e[1;1H\e[2J");
		i++;
	}
}
