#ifndef MY_MLX_H

# define MY_MLX_H

# include "../libft/libft.h"

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_img
{
	int		height;
	int		width;
	void	*i;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_img *data, int x, int y);
void			my_mlx_area_put(t_img *d, t_vector p, t_vector dim, int c);
t_img			*mlx_load_img(void *ptr, char *path);
void			mlx_img_to_img(int p[2], t_img img[2], int c1);
void			mlx_draw_vline(t_img img, int i, int j[2], int color);
t_vector	ft_newvector(int x, int y);

#endif