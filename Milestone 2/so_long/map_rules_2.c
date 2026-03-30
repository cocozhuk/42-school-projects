/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <kzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:41:53 by kzhu              #+#    #+#             */
/*   Updated: 2026/03/10 17:16:39 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	find_player(t_map *map)
{
	int	x;
	int	y;

	y = map->height - 2;
	while (y > 0)
	{
		x = map->width - 2;
		while (x > 0)
		{
			if (map->grid[y][x] == 'P')
			{
				map->p_y = y;
				map->p_x = x;
				break ;
			}
			x--;
		}
		y--;
	}
}

int	valid_path(t_map *dup_map)
{
	int	x;
	int	y;

	y = dup_map->height - 2;
	while (y > 0)
	{
		x = dup_map->width - 2;
		while (x > 0)
		{
			if (dup_map->grid[y][x] != '1' && dup_map->grid[y][x] != 'F')
				return (1);
			x--;
		}
		y--;
	}
	return (0);
}
