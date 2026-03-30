/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:48:55 by kzhu              #+#    #+#             */
/*   Updated: 2026/01/16 14:18:07 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_first(char *str)
{
	int i;

	i = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i] != 32 || str[i] != 9)
	{
		while (str[i] != 32 && str[i] != 9 && str[i])
		{
			write (1, &str[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_first(argv[1]);
	}
	write (1, "\n", 1);
}
