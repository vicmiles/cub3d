#ifndef CUB3D_H

# define CUB3D_H

#include "../libft/libft.h"
# include "keycodes.h"
# include <mlx.h>
# include "get_next_line.h"
# include "my_mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# ifndef WIN_H
#  define WIN_H 480
# endif

# ifndef WIN_W
#  define WIN_W 640
# endif

# ifndef SIZE
#  define SIZE 7
# endif

/* Enum to handle various exit/error messages */
typedef enum e_cub_err
{
	end,
	inv_argc,
	inv_ext,
	inv_file,
	empty_file,
	no_memory,
	inv_color,
	inv_wall,
	inv_map,
	inv_charac,
	inv_player,
	inv_tex
}				t_cub_err;

/* Struct to handle rgb colors with transparency */
typedef struct s_color
{
	long	t;
	long	r;
	long	g;
	long	b;
}				t_color;

/* Every image corresponding to a wall texture, plus floor and ceiling */
typedef struct s_tex
{
	t_list	*n;
	t_list	*n_bak;
	t_list	*s;
	t_list	*s_bak;
	t_list	*w;
	t_list	*w_bak;
	t_list	*e;
	t_list	*e_bak;
	t_img	*b;
	int		floor;
	int		ceiling;
}				t_tex;

/* Struct to check when keys are pressed */
typedef struct s_key
{
	int	w_pressed;
	int	a_pressed;
	int	s_pressed;
	int	d_pressed;
	int	left_pressed;
	int	right_pressed;
}				t_key;

/* Struct to store various attributes of our player */
typedef struct s_player
{
	float	x;
	float	y;
	char	dir;
	float	speed;
	t_key	keys;
}				t_player;

/* Struct to store all ray-casting-related data */
typedef struct s_ray
{
	float	incre_angle;
	float	angle;
	float	hfov;
	float	lim;
	int		precision;
}				t_ray;

/* Handles most game attributes */
typedef struct s_game
{
	int			fd;
	char		**map;
	int			height;
	int			width;
	int			mouse_x;
	int			rate;
	long		nframes;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		win_img;
	t_img		win_g;
	t_img		win_r;
	t_img		minimap;
	t_img		miniview;
	t_img		*scope;
	t_tex		tex;
	t_ray		ray;
	t_player	pl;
	float		x;
	float		y;
}				t_game;

/* Check possible map errors */
void	check_map(t_game *g);

/* Reads file with gnl */
void	read_map(char *file, t_game *g);

/* Retrieves next line from a given fd */
char	*get_next_line(int fd);

/* Prints appropriate error message and exits, freeing everything */
int		cub_perror(t_cub_err err, t_game *g, char *param, int c);

/* Prints usage for the cub3D program */
void	cub_usage(int errno);

/* Function called by mlx when exiting */
int		cub_exit(void *param);

/* Atoi for colors (more restrictive than original) */
int		cub_atoi(const char *nptr, long *nbr);

/* Fills color int for floor and ceiling */
void	get_cf_color(char **dir, t_game *g);

/* Drecreases RGB value of color as object gets further */
int		get_dist_color(int color, float ds, int tr);

/* Frees all necessary things before exiting */
void	cub_end(t_game *g);

/* Initializes game */
void	game_init(t_game *g);

/* Draws game */
void	draw_game(t_game *g);

/* Initialize raycast data */
void	init_ray(t_game *g);

/* Converts degrees to radians */
float	degree_to_radians(float degree);

/* Draws a 2D minimap */
void	cub_minimap(t_game *g);

/* Draws a section of the 2D minimap */
void	cub_miniview(t_game *g);

/* Function to shoot rays in a given direction to find walls */
void	cub_raycast(t_game *g);

/* Function called inside mlx loop */
int		cub_update(void *param);

/* Checks if there're c's in position range [n0,n1] of m */
int		checkcn(char *m, char c, int n0, int n1);

/* Check every element of the map: spaces + characters */
void	check_elements(t_game *g);

/* Draws 3D view on window-sized image */
void	cub_draw(t_game *g, int ray_count, float dis);

/* Checks which wall has been hit to choose proper texture */
t_img	*get_texture(t_game *g);

/* Moves player depending on which key was pressed */
void	move_pl(int k, t_game *g, float ray_cos, float ray_sin);

/* Checks player surroundings to open/close doors */
void	action_door(t_game *g);

/* Inverts color of window-sized image */
void	cub_invert_color(t_game *g);

/* Adds spaces to end of all lines to ensure all lines have the same width */
char	**square_map(t_game *g);

void	ft_free_matranspix(char ***matrix);
int	ft_matranspixlen(char **matrix);
char	**ft_extend_matrix(char **in, char *newstr);
int	ft_stranspncmp(const char *s1, const char *s2, size_t n);
void	ft_free_matrix(char ***matrix);
int	ft_matrixlen(char **m);

#endif

// #ifndef CUB3D_H
// #define CUB3D_H

// #include "../libft/libft.h"
// #include "mlx.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdlib.h>
// # include "keycodes.h"
// # include <mlx.h>
// // # include "get_next_line.h"   i don`t have get_next_line in myown laptop so i created new littel one in parser if you need you can use or add yor get_nex_line 
// # include "my_mlx.h"
// # include <math.h>

// # ifndef WIN_H
// #  define WIN_H 480
// # endif

// # ifndef WIN_W
// #  define WIN_W 640
// # endif

// # ifndef SIZE
// #  define SIZE 7
// # endif

// #ifndef TILE_SIZE
// #  define TILE_SIZE 32
// # endif

// #ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 32
// # endif

// typedef enum e_cub_err
// {
// 	end,
// 	inv_argc,
// 	inv_ext,
// 	inv_file,
// 	empty_file,
// 	no_memory,
// 	inv_color,
// 	inv_wall,
// 	inv_map,
// 	inv_charac,
// 	inv_player,
// 	inv_tex,
// 	inv_pwd
// }	t_cub_err;

// typedef struct s_color
// {
// 	long	t;
// 	long	r;
// 	long	g;
// 	long	b;
// }				t_color;

// typedef struct s_ray
// {
// 	float	incre_angle;
// 	float	angle;
// 	float	cos;
// 	float	sin;
// 	float	hfov;
// 	float	limit;
// 	int		precision;
// }				t_ray;

// // typedef struct s_map_state
// // {
// // 	int	in_map;
// // 	int	map_ended;
// // 	int	row_count;
// // }	t_map_state;

// // typedef struct s_path
// // {
// // 	char *no_path;
// // 	char *so_path;
// // 	char *we_path;
// // 	char *ea_path;
// // 	int floor_color;
// // 	int ceiling_color;
// // 	int no_exist;
// // 	int so_exist;
// // 	int we_exist;
// // 	int ea_exist;
// // 	int f_exist;
// // 	int c_exist;
// // } t_path;

// // typedef struct s_map
// // {
// //     char **map;
// // 	char **copy;
// // 	int fd;
// // 	char *l;
// //     int row;
// //     int col;
// //     int x;
// //     int y;
// //     int player_count;
// //     int player;
// //     double			casetotal;
// //     int				player_x;
// // 	int	player_y;
// //     t_path      *path;
// // } t_map;

// typedef struct s_key
// {
// 	int	w_pressed;
// 	int	a_pressed;
// 	int	s_pressed;
// 	int	d_pressed;
// 	int	left_pressed;
// 	int	right_pressed;
// }				t_key;

// typedef struct s_tex
// {
// 	t_list	*n;
// 	t_list	*n_bak;
// 	t_list	*s;
// 	t_list	*s_bak;
// 	t_list	*w;
// 	t_list	*w_bak;
// 	t_list	*e;
// 	t_list	*e_bak;
// 	t_img	*b;
// 	int		floor;
// 	int		ceiling;
// }				t_tex;

// typedef struct s_player
// {
// 	float	x;
// 	float	y;
// 	char	dir;
// 	float	speed;
// 	//int		door_cooldown;
// 	t_key	keys;
// }				t_player;

// typedef struct s_game
// {
// 	int			fd;
// 	char		**map;
// 	int			height;
// 	int			width;
// 	int			mouse_x;
// 	int			rate;
// 	int			neg;
// 	long		nframes;
// 	void		*mlx_ptr;
// 	void		*win_ptr;
// 	t_img		win_img;
// 	t_img		win_g;
// 	t_img		win_r;
// 	t_img		minimap;
// 	t_img		miniview;
// 	t_img		*scope;
// 	t_tex		tex;
// 	t_ray		ray;
// 	t_player	pl;
// 	float		x;
// 	float		y;
// }				t_game;


// // /* ..parsing/checkmap.c */
// // int	check_exten(int argc, char *str);
// // int	incorect_char(t_game *g);
// // char	*pad_line_with_spaces(char *line, size_t max_len);
// // void	add_space(t_map *map);
// // char	**copy_map(char **map, int height);

// // /* check_valid_map.c */ 
// // int is_map_full(t_game *g, t_map *map);
// // int is_map_closed_by_walls(t_game *g);

// // /* ..parsing_error_and_free.c */ 
// // void	free_split(char **arr);
// // int	ft_error(t_game *game, const char *msg);
// // void	free_map_array(char **map);
// // void	free_game_map(t_game *game);

// // /*..parsing/get_color.c */
// // int	get_color(t_game *game, char *filename);

// // /*..parsing/get_map.c */
// // int	get_map(t_map *map, char *filename);

// // /*..parsing/get_map_utils.c */
// // int	count_row(t_map *map, int fd);
// // int	is_line_map_data(char *line);
// // void	process_map_line(t_map *m, char *line, t_map_state *state);
// // int	count_map_rows(t_map *m, char *file, int *row_count);

// // /* ..parsing/get_next_line.c */
// //char	*get_next_line(int fd); 

// // /* ..parsing/parsing.c */
// // int	init_game_data(t_game *game, char *filename);

// // /* ..parsing/read_path.c */
// // char	*trim_newline(char *str);
// // void	init_path(t_path *path);
// // int	file_exists(const char *filepath);
// // int	check_path_extension(t_game *game, char *path, char *dir);
// // int chech_exist(t_game *game, t_path *path); 

// // /* ..parsing_error.c */ 
// // int	count_rdb(char **rgb);
// // int	parse_color(t_game *g, char *line);
// // int	count_color_exist(t_game *game);
// // int	get_color(t_game *game, char *filename);

// // /* ..errors_and.c */
// // int forbedden(t_game *g);
// // int error_map(t_game *g);
// // int	find_player(t_game *g);

// // /* ..parsing/utils.c */
// // int	numberblank(char *str);
// // int	str_len(const char *s);
// // int	allow_char(char c);
// // int	count_len_row(t_map *map);
// // int	is_empty_line(char *line);

// void	check_elements(t_game *g);
// char	**square_map(t_game *g);
// void	check_characters(t_game *g, char **map, int i, int j);
// void	check_walls(t_game *g, char **map, int i, int j);
// t_list	*get_anim(t_img *img, t_list **anim, int n[0][2]);
// void	check_textures(char *trim, t_game *g, int n[0][2]);
// void	read_map(char *file, t_game *g);
// void	check_map(t_game *g);
// int	ft_matrixlen(char **m);
// char	*get_next_line(int fd);
// char	*gnl_shrink_buffer(char *buf, char *line);
// char	*gnl_expand_buffer(char *buf, int fd);
// char	*gnl_newread(int fd);
// size_t	gnl_strlen(const char *s);
// char	*gnl_substr(char const *s, unsigned int start, size_t len);
// size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
// int	gnl_strchr_i(const char *s, int c);
// size_t	gnl_strlcat(char *dst, const char *src, size_t size);


// /*raycasting and utils*/
// void    ray_init(t_game *g);
// float   wall_distance(t_game *g, float ray_angle);
// float	degree_to_radians(float degree);
// void	raycast(t_game *g);
// int	check_if_c(char *m, char c, int n0, int n1);
// int	atoi_cub(const char *nptr, long *nbr);
// void	ft_free_matrix(char ***matrix);

// /*paint of textures and setting color*/
// t_img	*texture_get(t_game *g);
// int	get_tex_color(t_game *g, t_img *i, int z);
// void	draw_texture(t_game *g, t_img *i, int ray_count, int wall_height);
// void	cub_draw(t_game *g, int ray_count, float dis);
// int	create_transpgb(t_color c);
// t_color	create_rgbt(int col);
// void	get_cf_color(char **dir, t_game *g);
// int	get_dist_color(int color, float dist, int transp);
// void	ft_free_matranspix(char ***matrix);
// int	ft_matranspixlen(char **matrix);
// char	**ft_extend_matrix(char **in, char *newstr);
// int	ft_stranspncmp(const char *s1, const char *s2, size_t n);

// /*render*/
// void	redraw_element(t_game *g, t_img img, int x, int y);
// void	animation_update(t_game *g);
// void	check_move(t_game *g);
// int cub_update(void *param);

// /* player */
// float	distance_to_wall(t_game *g, float ray_angle, float *x, float *y);
// void	move_pl(int k, t_game *g, float ray_cos, float ray_sin);

// /* minimap */
// int	get_mini_color(t_game *g, int len, int xy[2]);
// void	cub_minimap(t_game *g);

// /* game */
// int	cub_keyup(int k, t_game *g);
// int	cub_keydown(int k, t_game *g);
// int	cub_mouse(int x, int y, t_game *g);
// void	init_attr(t_game *g);
// void	game_init(t_game *g);

// /* error handling */
// int	cub_perror(t_cub_err err, t_game *g, char *param, int c);
// void	cub_usage(int errno);
// int	cub_exit(void *param);

// /* finishing */
// void	free_animation(t_game *g, t_list *start);
// void	destroy_images(t_game *g);
// void	cub_end(t_game *g);

// #endif
