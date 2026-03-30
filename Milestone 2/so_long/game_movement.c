/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <kzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:59:53 by cocozhu           #+#    #+#             */
/*   Updated: 2026/03/10 16:40:57 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "mlx/mlx.h"

void	move_player(t_game *game, int target_y, int target_x)
{
	char	target_cell;

	target_cell = game->game_map->grid[target_y][target_x];
	if (target_cell == '1')
		return ;
	else if (target_cell == 'E')
	{
		if (game->game_map->collectibles == 0)
		{
			game->steps++;
			ft_printf("You found the one! (total steps: %d)\n", game->steps);
			close_game(game);
		}
		else
			return ;
	}
	else if (target_cell == 'C')
		game->game_map->collectibles--;
	game->game_map->grid[game->game_map->p_y][game->game_map->p_x] = '0';
	game->game_map->grid[target_y][target_x] = 'P';
	game->game_map->p_y = target_y;
	game->game_map->p_x = target_x;
	game->steps++;
	ft_printf("Steps count: %d\n", game->steps);
	render_map(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("game closed\n");
		close_game (game);
	}
	if (keycode == KEY_W)
		move_player(game, game->game_map->p_y - 1, game->game_map->p_x);
	else if (keycode == KEY_S)
		move_player(game, game->game_map->p_y + 1, game->game_map->p_x);
	else if (keycode == KEY_A)
		move_player(game, game->game_map->p_y, game->game_map->p_x - 1);
	else if (keycode == KEY_D)
		move_player(game, game->game_map->p_y, game->game_map->p_x + 1);
	return (0);
}
