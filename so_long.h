/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:24:17 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/13 07:38:28 by ccambium         ###   ########.fr       */
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
	char	**map;
	char	*path;
}	t_tileset;

typedef struct s_image{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_window{
	void	*window;
	void	*screen;
	int		height;
	int		width;
	t_image	*current;
	t_image	*next;
}	t_window;

typedef struct s_player{
	int		pos[2];
	int		dir[2];
	int		animation;
	int		state;
}	t_player;

typedef struct s_collec{
	int			pos[2];
	int			state;
	void		*next;
}	t_collec;

typedef struct s_exit{
	int		pos[2];
	void	*next;
}	t_exit;

typedef struct s_vars{
	t_tileset	*t;
	t_window	*w;
	t_player	*p;
	t_collec	*c;
	t_exit		*e;
}	t_vars;

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
void		put_sprite_to_img(char **sprite, int *coord, char ***colors, void *img);
void		switch_image(void *screen, t_window *w);
void		event_handler(t_vars *vars);
void		map_generation(char **map, t_tileset *t, t_image *img);
char		**map_to_tab(char *path);
void		put_character(t_window *w, t_player *p, t_image *img, t_tileset *t);
int			create_trgb(int t, int r, int g, int b);
char		**get_sprite(t_tileset *sprite, int x, int y);
int			get_color_by_char(char ***colors, char c);
void		ft_pixel_put(t_image *data, int x, int y, int color);
int			render_next_frame(t_vars *vars);
void		move(t_player *p, t_vars *vars, int x, int y);
int			map_verification(char **map, t_vars *vars);
void		locate_player(char **map, t_vars *vars);
void		locate_collectible(char **map, t_vars *vars);
void		remapping(char **map);
int			will_collide_wall(int *pos, int *dir, char **map);
char		*ft_itoa(int n);
int			ft_flour(double n);
int			ft_ceil(double n);
int			is_near(int	*pos1, int *pos2);
int			is_on_collectible(t_player *p, t_collec *c);
void		put_collectible(t_collec *c, t_vars *v);
void		take_collectible(t_collec *c, t_vars *vars);
void		collec_foreach(t_collec *head, void (*f)(), t_vars *param);
int			all_collect_taken(t_collec *head);
void		put_exit(t_exit *e, t_vars *v);
void		exit_foreach(t_exit *head, void (*f)(), t_vars *param);
void		ft_on_exit(t_exit *e, t_vars *v);

#endif
