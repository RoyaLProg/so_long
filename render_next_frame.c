#include "so_long.h"

int	render_next_frame(t_vars *vars)
{
	move(vars->p);
	map_generation(vars->t->map, vars->t, vars->w->next);
	put_character(vars->w->window, vars->p, vars->w->next, vars->t);
	switch_image(vars->w->screen, vars->w);
	return (1);
}
