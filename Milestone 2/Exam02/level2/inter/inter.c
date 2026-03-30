/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:17:17 by kzhu              #+#    #+#             */
/*   Updated: 2026/01/16 17:03:52 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_union(char *str1, char *str2)
{
	int i;
	char ary[256];

	i = 0;
	while (i <= 255)
	{
		ary[i] = 0;
		i++;
	}
	i = 0;
	while (str2[i])
	{
		unsigned char flag = (unsigned char)str2[i];
		ary[flag] = 1;
		i++;
	}
	i = 0;
	while (str1[i])
	{
		if (ary[(unsigned char)str1[i]] == 1)
		{
			write (1, &str1[i], 1);
			ary[(unsigned char)str1[i]] = 2;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
}
