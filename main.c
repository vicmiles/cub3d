#include "../include/cub3d.h"

static void	check_file(int argc, char **argv)
{
	int	fd;

	cub_perror(inv_argc, NULL, NULL, argc != 2);
	if (!ft_strncmp(argv[1], "-h", 3) || \
		!ft_strncmp(argv[1], "--help", 7))
		cub_usage(0);
	fd = open(argv[1], O_RDONLY);
	close(fd);
	cub_perror(inv_file, NULL, argv[1], fd < 0);
	if (ft_strrncmp(".cub", argv[1], 4))
		cub_perror(inv_ext, NULL, NULL, 1);
}

void	init_sprites(t_game *g)
{
	g->win_img.i = NULL;
	g->win_g.i = NULL;
	g->win_r.i = NULL;
	g->minimap.i = NULL;
	g->miniview.i = NULL;
	g->tex.n = NULL;
	g->tex.n_bak = NULL;
	g->tex.s = NULL;
	g->tex.s_bak = NULL;
	g->tex.e = NULL;
	g->tex.e_bak = NULL;
	g->tex.w = NULL;
	g->tex.w_bak = NULL;
	g->tex.b = mlx_load_img(g->mlx_ptr, "textures/black.xpm");
	g->scope = mlx_load_img(g->mlx_ptr, "textures/scope.xpm");
}

static t_game	cub_init(void)
{
	t_game	g;

	g.width = 0;
	g.height = 0;
	g.nframes = 0;
	g.map = NULL;
	g.pl.dir = 0;
	g.mlx_ptr = NULL;
	g.win_ptr = NULL;
	g.mlx_ptr = mlx_init();
	init_sprites(&g);
	g.tex.floor = -1;
	g.tex.ceiling = -1;
	g.pl.x = -1;
	g.pl.y = -1;
	g.pl.speed = 0.15;
	ft_bzero(&g.pl.keys, sizeof(t_key));
	g.mouse_x = 0;
	g.rate = 50;
	return (g);
}

int	main(int argc, char **argv)
{
	t_game	g;
	char	**aux;

	check_file(argc, argv);
	g = cub_init();
	read_map(argv[1], &g);
	cub_perror(inv_tex, &g, NULL, !g.tex.n || !g.tex.s || !g.tex.e || \
		!g.tex.w);
	cub_perror(inv_color, &g, NULL, g.tex.floor == -1 || g.tex.ceiling == -1);
	aux = square_map(&g);
	ft_free_matrix(&g.map);
	g.map = aux;
	check_map(&g);
	game_init(&g);
	return (0);
}
