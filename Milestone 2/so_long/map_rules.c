/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <kzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:01:44 by kzhu              #+#    #+#             */
/*   Updated: 2026/03/10 17:15:34 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	check_walls(t_map *game, int x, int y)
{
	int	check_x;
	int	check_y;

	check_x = 0;
	check_y = 1;
	while (check_x < x)
	{
		if (game->grid[0][check_x] != '1')
			return (1);
		else if (game->grid[y - 1][check_x] != '1')
			return (1);
		check_x++;
	}
	while (check_y < y - 1)
	{
		if (game->grid[check_y][0] != '1')
			return (1);
		else if (game->grid[check_y][x - 1] != '1')
			return (1);
		check_y++;
	}
	return (0);
}

void	check_lines(char **grid, int x, int y, t_map *game)
{
	x = x - 2;
	while (x > 0)
	{
		if (grid[y][x] != '0' && grid[y][x] != '1'
			&& grid[y][x] != 'C' && grid[y][x] != 'E' && grid[y][x] != 'P')
			game->validity = 1;
		else if (grid[y][x] == 'E')
			game->exit++;
		else if (grid[y][x] == 'P')
			game->player++;
		else if (grid[y][x] == 'C')
			game->collectibles++;
		x--;
	}
}

int	check_components(t_map *game_map, int x, int y)
{
	y = y - 2;
	game_map->collectibles = 0;
	game_map->exit = 0;
	game_map->player = 0;
	game_map->validity = 0;
	while (y > 0)
	{
		check_lines(game_map->grid, x, y, game_map);
		y--;
	}
	if (game_map->exit != 1 || game_map->player != 1
		|| game_map->collectibles == 0 || game_map->validity == 1)
		return (1);
	return (0);
}

t_map	*duplicate_map(t_map *game_map)
{
	t_map	*dup_map;
	int		y;

	dup_map = malloc(sizeof(t_map));
	if (dup_map == NULL)
		return (NULL);
	dup_map->height = game_map->height;
	dup_map->width = game_map->width;
	dup_map->grid = malloc(sizeof(char *) * (dup_map->height + 1));
	if (dup_map->grid == NULL)
		return (free(dup_map), NULL);
	y = 0;
	while (game_map->grid[y] != NULL)
	{
		dup_map->grid[y] = ft_strdup(game_map->grid[y]);
		if (dup_map->grid[y] == NULL)
			return (ft_free_grid(dup_map->grid, y), free(dup_map), NULL);
		y++;
	}
	dup_map->grid[y] = NULL;
	return (dup_map);
}

void	flood_fill(t_map *dup_map, int y, int x)
{
	if (x < 1 || y < 1 || x >= dup_map->width - 1 || y >= dup_map->height - 1)
		return ;
	if (dup_map->grid[y][x] == '1' || dup_map->grid[y][x] == 'F')
		return ;
	dup_map->grid[y][x] = 'F';
	flood_fill(dup_map, y + 1, x);
	flood_fill(dup_map, y - 1, x);
	flood_fill(dup_map, y, x - 1);
	flood_fill(dup_map, y, x + 1);
}
