/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <kzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:49:01 by kzhu              #+#    #+#             */
/*   Updated: 2026/03/10 17:17:02 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	name_check(char *name)
{
	int	len;

	if (name == NULL)
		return (1);
	len = ft_strlen(name);
	if (len < 5)
		return (1);
	return (ft_strncmp(".ber", &name[len - 4], 4));
}

size_t	ft_strlen_so_long(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_hold_space_so_long(char const *s, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc (sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	*ft_free_grid(char **final, size_t j)
{
	while (j > 0)
	{
		j--;
		free(final[j]);
	}
	free (final);
	return (NULL);
}

void	*ft_free_map(t_map *game_map)
{
	int	i;

	if (game_map == NULL)
		return (NULL);
	i = 0;
	while (i < game_map->height)
	{
		free(game_map->grid[i]);
		i++;
	}
	free(game_map->grid);
	free(game_map);
	return (NULL);
}
