/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:28:36 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/08 03:31:12 by ccambium         ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	hex_to_int(char *hex)
{
	int		x;
	char	*nhex;

	if (ft_strncmp(hex, "#FF000000", ft_strlen(hex)) == 0)
		return (0xFF000000);
	nhex = ft_strtrim(hex, "x #");
	x = convert_h_x(nhex, ft_strlen(nhex));
	free(nhex);
	return (x);
}
