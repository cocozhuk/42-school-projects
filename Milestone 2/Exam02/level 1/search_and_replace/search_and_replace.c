/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:24:01 by kzhu              #+#    #+#             */
/*   Updated: 2026/01/16 13:21:57 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	searchandre (char *str, char search, char replace)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == search)
			write(1, &replace, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] != '\0' && argv[2][1] == '\0' && argv[3][0] != '\0' && argv[3][1] == '\0')
		{
				searchandre(argv[1], argv[2][0], argv[3][0]);
		}
	}
	write (1, "\n", 1);
}
