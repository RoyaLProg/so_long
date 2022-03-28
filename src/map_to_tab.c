/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:55:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/26 19:39:18 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	get_nb_lines(char *path)
{
	int		fd;
	size_t	size;
	char	*s;

	size = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		size++;
		free(s);
	}
	free(s);
	close(fd);
	return (size);
}

char	**map_to_tab(char *path)
{
	int		fd;
	size_t	i;
	size_t	size;
	char	**map;

	i = 0;
	size = get_nb_lines(path);
	if (size == 0)
		return (NULL);
	fd = open(path, O_RDONLY);
	map = malloc(sizeof(char *) * (size + 1));
	if (map == NULL)
		return (NULL);
	while (i < size + 1)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	return (map);
}
