/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:29:53 by kzhu              #+#    #+#             */
/*   Updated: 2026/01/17 16:05:30 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_doop(char *first, char *operator, char *second)
{
	int fi;
	int se;
	int res;
	char ope;

	fi = atoi(first);
	se = atoi(second);
	ope = operator[0];
	if (ope == '+')
		res = fi + se;
	else if (ope == '-')
		res = fi - se;
	else if (ope == '*')
		res = fi * se;
	else if (ope == '/')
		res = fi / se;
	else if (ope == '%')
		res = fi % se;
	printf("%i\n", res);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		ft_doop(argv[1], argv[2], argv[3]);
	}
	else
		write (1, "\n", 1);
}
