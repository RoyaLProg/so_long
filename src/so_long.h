/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:24:17 by ccambium          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/23 16:10:46 by ccambium         ###   ########.fr       */
=======
/*   Updated: 2022/03/26 18:53:38 by ccambium         ###   ########.fr       */
>>>>>>> 9649069b768d375e9289692e273b5291db149d71
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../libftprintf/ft_printf.h"
# include "../mlx_linux/mlx.h"

typedef struct s_tileset{
	void	*water;
	void	*character[2];
	void	*sand;
	void	*chest[3];
	void	*exit;
	char	**map;
	int		tile_height;
	int		tile_width;
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
	int			count;
}	t_vars;

char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_isdigit(int c);
int			hex_to_int(char *hex);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_split(char **v);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		event_handler(t_vars *vars);
void		map_generation(t_vars *v);
char		**map_to_tab(char *path);
void		put_character(t_vars *v);
char		**get_sprite(t_tileset *sprite, int x, int y);
int			render_next_frame(t_vars *vars);
void		move(t_player *p, t_vars *vars, int x, int y);
int			map_verification(char **map, t_vars *vars, char *mappath);
void		locate_player(char **map, t_vars *vars);
void		locate_next_collectible(t_collec *c, t_vars *v);
int			will_collide_wall(int *pos, int *dir, char **map);
char		*ft_itoa(int n);
int			ft_atoi(const char *s);
int			is_near(int	*pos1, int *pos2);
int			is_on_collectible(t_player *p, t_collec *c);
void		put_collectible(t_collec *c, t_vars *v);
void		take_collectible(t_collec *c, t_vars *vars);
void		collec_foreach(t_collec *head, void (*f)(), t_vars *param);
int			all_collect_taken(t_collec *head);
void		put_exit(t_exit *e, t_vars *v);
void		exit_foreach(t_exit *head, void (*f)(), t_vars *param);
void		ft_on_exit(t_exit *e, t_vars *v);
void		refresh_count(t_vars *vars);
void		ft_clear(void);
int			count_collec(char **map);
void		locate_collec(t_collec *head, t_vars *v);
int			count_exit(char **map);
void		locate_exit(t_exit *head, t_vars *v);
void		safe_end(t_vars	*v);
void		free_exit(t_exit *head);
void		free_collec(t_collec *head);
int			is_there_requirements(char **map);
int			verification2(char **map, size_t i);
int			is_dot_ber(char *mappath);
t_tileset	*tileset_load(t_vars *v);
void		tileset_safeend(t_vars *v);

#endif
