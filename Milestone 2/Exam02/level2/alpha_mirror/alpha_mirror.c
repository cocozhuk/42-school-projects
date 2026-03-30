/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:55:13 by kzhu              #+#    #+#             */
/*   Updated: 2026/01/17 15:29:05 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			char c = 122 - (str[i] - 97);
			write (1, &c, 1);
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			char ca = 90 - (str[i] - 65);
			write (1, &ca, 1);
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		ft_mirror(argv[1]);
	}
	write (1, "\n", 1);
}
