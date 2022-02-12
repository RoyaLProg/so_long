/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:55:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/07 19:16:48 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"

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
	fd = open(path, O_RDONLY);
	map == NULL;
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