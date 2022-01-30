/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 09:00:55 by ccambium          #+#    #+#             */
/*   Updated: 2021/10/31 09:00:55 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*v;

	i = 0;
	len = ft_strlen(s);
	v = malloc(len + 1);
	if (v == NULL)
		return (NULL);
	while (i < len)
	{
		*(v + i) = *(s + i);
		i++;
	}
	*(v + i) = 0;
	return (v);
}
