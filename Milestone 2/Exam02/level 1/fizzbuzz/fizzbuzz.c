/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:29:21 by kzhu              #+#    #+#             */
/*   Updated: 2026/01/16 15:52:44 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_nbr(int n)
{
	if (n > 9)
		put_nbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);

}
int	main()
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write (1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write (1, "fizz\n", 5);
		else if (i % 5 == 0)
			write (1, "buzz\n", 5);
		else
		{
			put_nbr(i);
			write (1, "\n", 1);
		}
		i++;
	}
}
