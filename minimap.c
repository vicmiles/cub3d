/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmileshk <vmileshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:41:53 by vmileshk          #+#    #+#             */
/*   Updated: 2025/07/02 11:42:02 by vmileshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cub_miniview(t_game *g)
{
	int	xy[2];
	int	temp[2];

	temp[1] = -1;
	xy[1] = (g->pl.y + 0.5) * SIZE - (int)(g->miniview.height / 2);
	while (++temp[1] < (g->miniview.height))
	{
		temp[0] = -1;
		xy[0] = (g->pl.x + 0.5) * SIZE - (int)(g->miniview.width / 2);
		while (++temp[0] < g->miniview.width)
		{
			if (xy[1] >= 0 && xy[1] < (g->height * SIZE) && xy[0] >= 0 \
						&& xy[0] < (g->width * SIZE))
				my_mlx_pixel_put(&g->miniview, temp[0], temp[1], \
					my_mlx_pixel_get(&g->minimap, xy[0], xy[1]));
			else
				my_mlx_pixel_put(&g->miniview, temp[0], temp[1], 0xFF000000);
			xy[0]++;
		}
		xy[1]++;
	}
}

int	get_mini_color(t_game *g, int len, int xy[2])
{
	int	color;

	color = 0xFF000000;
	if (xy[0] < len && g->map[xy[1]][xy[0]] == ' ')
		color = 0xFF000000;
	else if (xy[0] < len && g->map[xy[1]][xy[0]] != '1')
		color = 0x005E5C64;
	else if (xy[0] < len)
		color = 0x008BB5F8;
	return (color);
}

void	cub_minimap(t_game *g)
{
	int	xy[2];
	int	len;

	xy[1] = -1;
	while (++xy[1] < g->height)
	{
		xy[0] = -1;
		len = ft_strlen(g->map[xy[1]]);
		while (++xy[0] < g->width)
			my_mlx_area_put(&g->minimap, \
				ft_newvector(xy[0] * SIZE, xy[1] * SIZE), \
				ft_newvector(SIZE, SIZE), get_mini_color(g, len, xy));
	}
}
