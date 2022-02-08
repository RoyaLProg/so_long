/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:08:42 by ccambium          #+#    #+#             */
/*   Updated: 2022/01/28 11:08:42 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "so_long.h"

static char	***get_colors2(char ***colors, int fd, int x)
{
	int		i;
	char	*s;
	char	**rv;

	i = 0;
	while (i < x)
	{
		colors[i] = malloc(sizeof(char **) * 3);
		if (colors[i] == NULL)
			return (NULL);
		s = get_next_line(fd);
		rv = ft_split(s, '	');
		free(s);
		colors[i][0] = ft_strtrim(rv[0], "\"");
		colors[i][1] = ft_strtrim(rv[2], "\"\n,");
		free_split(rv);
		colors[i][2] = NULL;
		i++;
	}
	colors[i] = NULL;
	return (colors);
}

static char	***get_colors(char ***colors, int fd)
{
	char	**rv;
	char	*s;
	int		x;

	s = get_next_line(fd);
	rv = ft_split(s, ' ');
	x = ft_atoi(rv[2]);
	free_split(rv);
	free(s);
	colors = malloc(sizeof(char **) * (x + 1));
	if (colors == NULL)
		return (colors);
	return (get_colors2(colors, fd, x));
}

// 18 de long - 9 de haut
char	**get_images(char **img, int fd)
{
	size_t	i;
	char	*s;

	s = get_next_line(fd);
	if (ft_strncmp("/* pixels */\n", s, ft_strlen(s)) != 0)
		return (NULL);
	free(s);
	i = 0;
	s = get_next_line(fd);
	img = malloc(sizeof(char *) * 289);
	if (img == NULL)
		return (img);
	while (i < 288)
	{
		img[i] = ft_strtrim(s, ",\"\n");
		i++;
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	img[i] = NULL;
	return (img);
}

void	xpm_to_sprite(t_tileset *tileset)
{
	char	*s;
	int		fd;

	fd = open(tileset->path, O_RDONLY);
	if (fd == -1)
		return ;
	s = get_next_line(fd);
	while (ft_strncmp("/* columns rows colors chars-per-pixel */\n", s,
			ft_strlen(s)) != 0)
	{
		free(s);
		s = get_next_line(fd);
		if (s == NULL)
		{
			tileset->colors = NULL;
			tileset->img = NULL;
			return ;
		}
	}
	free(s);
	tileset->colors = get_colors(tileset->colors, fd);
	tileset->img = get_images(tileset->img, fd);
	close(fd);
}
