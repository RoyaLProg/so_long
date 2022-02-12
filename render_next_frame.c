#include "so_long.h"
#include <mlx.h>

int	render_next_frame(void *v)
{
	t_vars *vars;
	
	vars = (t_vars *)v;
	move(vars->p);
	map_generation(vars->t->map, vars->t, vars->w->next);
	put_character(vars->w->window, vars->p, vars->w->next, vars->t);
	switch_image(vars->w->screen, vars->w);
	//return (0);
}
