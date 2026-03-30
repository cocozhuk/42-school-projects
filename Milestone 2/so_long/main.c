/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <kzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:56:28 by cocozhu           #+#    #+#             */
/*   Updated: 2026/03/10 16:23:30 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "mlx/mlx.h"

int	close_game(t_game *game)
{
	ft_free_map(game->game_map);
	mlx_destroy_image(game->mlx, game->wall_p);
	mlx_destroy_image(game->mlx, game->collectibles_p);
	mlx_destroy_image(game->mlx, game->exit_p);
	mlx_destroy_image(game->mlx, game->player_p);
	mlx_destroy_image(game->mlx, game->floor_p);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		return (ft_printf("Error\nPlease use: ./so_long <map_path.ber>\n"), 1);
	if (name_check(argv[1]) != 0)
		return (ft_printf("Error\nPlease use: .ber\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nCould not open file\n"), 1);
	game.game_map = map_parsing(fd);
	if (game.game_map == NULL)
		return (1);
	game.steps = 0;
	find_player(game.game_map);
	if (initial_image(&game) == 1)
		return (ft_free_map(game.game_map), 1);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
