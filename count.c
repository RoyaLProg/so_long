/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:49:51 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/15 10:40:57 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	put_count(t_vars *vars)
{
	char	*s;
	char	*nb;

	s = malloc(16);
	ft_strlcpy(s, "count : ", 9);
	nb = ft_itoa(vars->count);
	ft_strlcat(s, nb, 8 + ft_strlen(nb));
	free(nb);
	mlx_string_put(vars->w->screen, vars->w->window, 10, 10, 255, "test");
	free(s);
}
