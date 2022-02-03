/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:24:17 by ccambium          #+#    #+#             */
/*   Updated: 2022/02/03 14:18:09 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct s_tileset{
	char	***colors;
	char	**img;
	char	*path;
}	t_tileset;
typedef struct s_image{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_sprite{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
}	t_sprite;

typedef struct s_window{
	void	*window;
	int		height;
	int		width;
	t_image	*current;
	t_image	*next;
}	t_window;

void		xpm_to_sprite(t_tileset *tileset);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_isdigit(int c);
int			hex_to_int(char *hex);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);
int			ft_pow(int x, int pow);
void		free_split(char **v);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		put_sprite(t_tileset *t, int *s_coord, int *coord, t_image *img);
void		switch_image(void *screen, t_window *w);

#endif
