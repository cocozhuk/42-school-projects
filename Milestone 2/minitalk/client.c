/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:57:56 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/26 15:54:55 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	read_bits(pid_t pid, char c)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (c & i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (i == 1)
			usleep(800);
		else
			usleep(400);
		i /= 2;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		read_bits((pid_t)pid, argv[2][i]);
		i++;
	}
	read_bits((pid_t)pid, '\0');
	return (0);
}
