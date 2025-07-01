#include "../include/cub3d.h"

void	redraw_elem(t_game *g, t_img img, int x, int y)
{
	int		p[2];
	t_img	images[2];

	p[0] = x;
	p[1] = y;
	images[0] = img;
	images[1] = g->win_img;
	mlx_img_to_img(p, images, 0xFF000000);
}

void	update_anim(t_game *g)
{
	g->tex.n = g->tex.n->next;
	if (!g->tex.n)
		g->tex.n = g->tex.n_bak;
	g->tex.s = g->tex.s->next;
	if (!g->tex.s)
		g->tex.s = g->tex.s_bak;
	g->tex.e = g->tex.e->next;
	if (!g->tex.e)
		g->tex.e = g->tex.e_bak;
	g->tex.w = g->tex.w->next;
	if (!g->tex.w)
		g->tex.w = g->tex.w_bak;
}

void	check_move(t_game *g)
{
	if (g->pl.keys.left_pressed)
		g->ray.angle -= 3;
	if (g->pl.keys.right_pressed)
		g->ray.angle += 3;
	if (g->pl.keys.w_pressed)
		move_pl(KEY_W, g, 0, 0);
	if (g->pl.keys.a_pressed)
		move_pl(KEY_A, g, 0, 0);
	if (g->pl.keys.s_pressed)
		move_pl(KEY_S, g, 0, 0);
	if (g->pl.keys.d_pressed)
		move_pl(KEY_D, g, 0, 0);
}

int	cub_update(void *param)
{
	t_game	*g;

	g = param;
	if (!(g->nframes % g->rate))
	{
		if (!(g->nframes % (2 * g->rate)))
			update_anim(g);
		check_move(g);
		cub_minimap(g);
		cub_raycast(g);
		cub_miniview(g);
		redraw_elem(g, *g->scope, WIN_W - g->scope->width - 10, \
			WIN_H - g->scope->height - 10);
		redraw_elem(g, g->miniview, WIN_W - g->miniview.width - 400, \
			WIN_H - g->miniview.height - 20);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_img.i, 0, 0);
	}
	g->nframes++;
	return (0);
}
