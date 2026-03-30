/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <kzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:59:53 by cocozhu           #+#    #+#             */
/*   Updated: 2026/03/10 16:29:46 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "mlx/mlx.h"

int	initial_image(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	game->mlx_win = mlx_new_window(game->mlx,
			game->game_map->width * TS,
			game->game_map->height * TS,
			"The Game");
	if (game->mlx_win == NULL)
		return (free(game->mlx), 1);
	load_image(game);
	if (game->wall_p == NULL
		|| game->player_p == NULL
		|| game->collectibles_p == NULL
		|| game->floor_p == NULL
		|| game->exit_p == NULL)
	{
		ft_printf("Error\nMissing or invaild .xpm files\n");
		close_game(game);
	}
	render_map(game);
	return (0);
}

void	load_image(t_game *game)
{
	game->wall_p = mlx_xpm_file_to_image(game->mlx,
			"xpms/wall.xpm",
			&game->img_width,
			&game->img_height);
	game->player_p = mlx_xpm_file_to_image(game->mlx,
			"xpms/player.xpm",
			&game->img_width,
			&game->img_height);
	game->collectibles_p = mlx_xpm_file_to_image(game->mlx,
			"xpms/collectibles.xpm",
			&game->img_width,
			&game->img_height);
	game->floor_p = mlx_xpm_file_to_image(game->mlx,
			"xpms/floor.xpm",
			&game->img_width,
			&game->img_height);
	game->exit_p = mlx_xpm_file_to_image(game->mlx,
			"xpms/exit.xpm",
			&game->img_width,
			&game->img_height);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->game_map->height)
	{
		x = -1;
		while (++x < game->game_map->width)
		{
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->floor_p, x * TS, y * TS);
			if (game->game_map->grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall_p, x * TS, y * TS);
			if (game->game_map->grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->collectibles_p, x * TS, y * TS);
			if (game->game_map->grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->player_p, x * TS, y * TS);
			if (game->game_map->grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->exit_p, x * TS, y * TS);
		}
	}
}
