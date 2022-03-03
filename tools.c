/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:31:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/25 16:27:12 by ccambium         ###   ########.fr       */
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

int	ft_ceil(double n)
{
	int		x;
	double	y;

	x = n;
	y = (n - x);
	if (y > 1)
		return (x - 1);
	return (x);
}

int	ft_flour(double n)
{
	int		x;
	double	y;

	x = n;
	y = (n - x);
	if (y < 1)
		return (x);
	return (x - 1);
}
