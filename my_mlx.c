/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmileshk <vmileshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:42:06 by vmileshk          #+#    #+#             */
/*   Updated: 2025/07/02 11:42:11 by vmileshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/my_mlx.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dist;

	dist = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dist = color;
}

unsigned int	my_mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dist;

	dist = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dist);
}

void	my_mlx_area_put(t_img *d, t_vector p, t_vector dim, int c)
{
	int	x;
	int	y;

	y = -1;
	while (++y < dim.y)
	{
		x = -1;
		while (++x < dim.x)
			my_mlx_pixel_put(d, p.x + x, p.y + y, c);
	}
}

void	mlx_img_to_img(int p[2], t_img img[2], int c1)
{
	int	xy[2];
	int	color;

	xy[1] = -1;
	while (++xy[1] < img[0].height)
	{
		xy[0] = -1;
		while (++xy[0] < img[0].width)
		{
			if (xy[0] + p[0] >= 0 && xy[1] + p[1] >= 0)
			{
				color = my_mlx_pixel_get(&img[0], xy[0], xy[1]);
				if (color != c1)
					my_mlx_pixel_put(&img[1], xy[0] + p[0], \
						xy[1] + p[1], color);
			}
		}
	}
}

t_vector	ft_newvector(int x, int y)
{
	t_vector	position;

	position.x = x;
	position.y = y;
	return (position);
}
