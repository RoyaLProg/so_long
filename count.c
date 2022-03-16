/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:49:51 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/16 08:22:49 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	refresh_count(t_vars *vars)
{
	char	*nb;

	nb = ft_itoa(vars->count);
	ft_clear();
	write(1, "steps : ", 8);
	write(1, nb, ft_strlen(nb));
	free(nb);
}
