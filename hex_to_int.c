/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:28:36 by ccambium          #+#    #+#             */
/*   Updated: 2022/01/29 20:51:32 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	value_x(char c)
{
	char	*s;
	char	*s2;
	int		i;

	i = 0;
	s = "0123456789ABCDEF";
	s2 = "0123456789abcdef";
	while (s[i])
	{
		if (s[i] == c || s2[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static int	convert_h_x(char *hex, size_t max)
{
	if (max == 1)
		return (value_x(hex[-(max - ft_strlen(hex))]));
	return (ft_pow(16, max - 1) * value_x(hex[-(max - ft_strlen(hex))])
		+ convert_h_x(hex, max - 1));
}

int	hex_to_int(char *hex)
{
	int		x;
	char	*nhex;

	nhex = ft_strtrim(hex, "x #");
	x = convert_h_x(nhex, ft_strlen(nhex));
	free(nhex);
	return (x);
}
