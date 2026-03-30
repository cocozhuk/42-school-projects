/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <kzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:36:38 by kzhu              #+#    #+#             */
/*   Updated: 2026/03/10 17:11:32 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_list	*map_initial(int fd)
{
	char	*lines;
	t_list	*map_head;
	t_list	*map_nodes;

	map_head = NULL;
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		map_nodes = ft_lstnew(lines);
		if (map_nodes == NULL)
			return (free(lines), ft_lstclear(&map_head, free), NULL);
		ft_lstadd_back(&map_head, map_nodes);
		lines = get_next_line(fd);
	}
	return (map_head);
}

int	map_check(t_list *map_head)
{
	int		first_line_width;
	int		each_line_width;
	char	*current_node;

	first_line_width = ft_strlen_so_long(map_head->content);
	map_head = map_head->next;
	while (map_head != NULL)
	{
		current_node = map_head->content;
		each_line_width = ft_strlen_so_long(current_node);
		if (first_line_width != each_line_width)
			return (ft_printf("Error\nPlease use a rectangular map.\n"), 1);
		map_head = map_head->next;
	}
	return (0);
}

t_map	*map_trans(t_list *map_head)
{
	int		i;
	char	*cur_node;
	t_map	*game_map;

	game_map = malloc(sizeof(t_map));
	if (game_map == NULL)
		return (NULL);
	game_map->height = ft_lstsize(map_head);
	game_map->width = ft_strlen_so_long(map_head->content);
	game_map->grid = malloc(sizeof(char *) * (game_map->height + 1));
	if (game_map->grid == NULL)
		return (free(game_map), NULL);
	i = 0;
	while (map_head != NULL)
	{
		cur_node = map_head->content;
		game_map->grid[i] = ft_hold_space_so_long(cur_node, game_map->width);
		if (game_map->grid[i] == NULL)
			return (ft_free_grid(game_map->grid, i), free(game_map), NULL);
		i++;
		map_head = map_head->next;
	}
	game_map->grid[i] = NULL;
	return (game_map);
}

int	map_rules(t_map *game_map)
{
	int	x;
	int	y;

	x = game_map->width;
	y = game_map->height;
	if (check_walls(game_map, x, y) != 0)
		return (ft_printf("Error\nPlease use the correctly enclosed map.\n"), 1);
	if (check_components(game_map, x, y) != 0)
		return (ft_printf("Error\nPlease use the correct set up.\n"), 1);
	return (0);
}

t_map	*map_parsing(int fd)
{
	t_list	*map_head;
	t_map	*game_map;
	t_map	*dup_map;

	map_head = map_initial(fd);
	if (map_head == NULL)
		return (NULL);
	if (map_check(map_head) != 0)
		return (ft_lstclear(&map_head, free), NULL);
	game_map = map_trans(map_head);
	ft_lstclear(&map_head, free);
	dup_map = duplicate_map(game_map);
	if (game_map == NULL || map_rules(game_map) != 0 || dup_map == NULL)
		return (ft_free_map (game_map), ft_free_map (dup_map), NULL);
	find_player(dup_map);
	flood_fill(dup_map, dup_map->p_y, dup_map->p_x);
	if (valid_path(dup_map) == 1)
	{
		ft_printf("Error\nPlease have a valid path.\n");
		return (ft_free_map (game_map), ft_free_map (dup_map), NULL);
	}
	ft_free_map (dup_map);
	return (game_map);
}
