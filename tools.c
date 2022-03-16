/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:31:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/16 07:36:14 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_pow(int x, int pow)
{
	int	v;

	v = 1;
	while (pow)
	{
		v *= x;
		pow--;
	}
	return (v);
}

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
		puts("\e[1;1H\e[2J");
		i++;
	}
}
