/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmileshk <vmileshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:42:15 by vmileshk          #+#    #+#             */
/*   Updated: 2025/07/02 11:42:15 by vmileshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_walls(t_game *g, char **map, int i, int j)
{
	if (j - 1 >= 0 && j - 1 < g->height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, g, NULL, map[j - 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, g, NULL, map[j - 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, g, NULL, map[j - 1][i] == '0');
	}
	if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j]))
		cub_perror(inv_wall, g, NULL, map[j][i - 1] == '0');
	if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j]))
		cub_perror(inv_wall, g, NULL, map[j][i + 1] == '0');
	if (j + 1 >= 0 && j + 1 < g->height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, g, NULL, map[j + 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, g, NULL, map[j + 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, g, NULL, map[j + 1][i] == '0');
	}
}

void	check_characters(t_game *g, char **map, int i, int j)
{
	if (!g->pl.dir && ft_strchr("NSWE", map[j][i]))
	{
		g->pl.dir = map[j][i];
		g->pl.x = (float)i;
		g->pl.y = (float)j;
	}
	else if (g->pl.dir && ft_strchr("NSWE", map[j][i]))
		cub_perror(inv_player, g, NULL, 1);
	else if (!ft_strchr("01", map[j][i]))
		cub_perror(inv_charac, g, NULL, 1);
	if (j == g->height - 1 && !g->pl.dir)
		cub_perror(inv_player, g, NULL, 1);
}

char	**square_map(t_game *g)
{
	char	**temp;
	int		i;
	int		j;

	temp = malloc(sizeof(char *) * (g->height + 1));
	j = -1;
	while (++j < g->height)
	{
		temp[j] = malloc(sizeof(char) * (g->width + 1));
		i = -1;
		while (++i < g->width)
		{
			if (i >= (int)ft_strlen(g->map[j]))
				temp[j][i] = ' ';
			else
				temp[j][i] = g->map[j][i];
		}
		temp[j][i] = '\0';
	}
	temp[j] = NULL;
	return (temp);
}

void	check_elements(t_game *g)
{
	int		i;
	int		j;

	j = -1;
	while (++j < g->height)
	{
		i = -1;
		while (++i < g->width)
		{
			if (g->map[j][i] == ' ')
				check_walls(g, g->map, i, j);
			else
				check_characters(g, g->map, i, j);
		}
	}
}
