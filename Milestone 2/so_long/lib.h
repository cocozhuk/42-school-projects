/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <kzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:42:59 by kzhu              #+#    #+#             */
/*   Updated: 2026/03/10 16:42:54 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# define TS 64
# define KEY_ESC 65307
# define KEY_W   119
# define KEY_A   97
# define KEY_S   115
# define KEY_D   100

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "GNL/get_next_line.h"

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		player;
	int		exit;
	int		validity;
	int		p_x;
	int		p_y;
}	t_map;

typedef struct s_game
{
	t_map	*game_map;
	void	*mlx;
	void	*mlx_win;
	void	*wall_p;
	void	*player_p;
	void	*collectibles_p;
	void	*floor_p;
	void	*exit_p;
	int		img_width;
	int		img_height;
	int		steps;
}	t_game;

t_map	*map_parsing(int fd);
t_list	*map_initial(int fd);
int		map_check(t_list *map_head);
t_map	*map_trans(t_list *map_head);
int		map_rules(t_map *game_map);

int		name_check(char *name);
size_t	ft_strlen_so_long(const char *s);
char	*ft_hold_space_so_long(char const *s, size_t len);
void	*ft_free_grid(char **final, size_t j);
void	*ft_free_map(t_map *game_map);

int		check_walls(t_map *game, int x, int y);
int		check_components(t_map *game_map, int x, int y);
void	check_lines(char **grid, int x, int y, t_map *game);
t_map	*duplicate_map(t_map *game_map);
void	flood_fill(t_map *dup_map, int x, int y);
void	find_player(t_map *map);
int		valid_path(t_map *dup_map);

int		initial_image(t_game *game);
void	load_image(t_game *game);
void	render_map(t_game *game);

int		key_hook(int keycode, t_game *game);
void	move_player(t_game *game, int target_y, int target_x);
int		close_game(t_game *game);

#endif
