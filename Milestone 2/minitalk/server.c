/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:20:27 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/25 19:41:04 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	get_sig(int sig)
{
	static int	count;
	static char	c;

	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	count++;
	if (count == 8)
	{
		if (c != '\0')
			write (1, &c, 1);
		else
			write (1, "\n", 1);
		c = '\0';
		count = 0;
	}
}

int	main(void)
{
	pid_t	id;

	id = getpid();
	ft_printf("-----------------------------\n");
	ft_printf("   /\\_/\\   \n");
	ft_printf("  ( o.o )  MINITALK SERVER \n");
	ft_printf("   > ^ <   PID: %d\n", id);
	ft_printf("-----------------------------\n");
	ft_printf(" Waiting for your signals...\n\n");
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	while (1)
		pause();
	return (0);
}
