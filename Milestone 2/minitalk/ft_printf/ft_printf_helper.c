/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:28:07 by kzhu              #+#    #+#             */
/*   Updated: 2025/12/03 22:26:23 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_forstr(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
}

int	ft_forptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		count = 2 + ft_putnbrhex_ptr((unsigned long)ptr);
	}
	return (count);
}

int	ft_fornbr(int i)
{
	long int	num;
	int			count;
	char		c;

	num = i;
	count = 0;
	if (num < 0)
	{
		num = -num;
		write (1, "-", 1);
		count++;
	}
	if (num > 9)
		count += ft_fornbr(num / 10);
	c = (num % 10) + '0';
	write (1, &c, 1);
	count++;
	return (count);
}

int	ft_forunnbr(unsigned int u)
{
	unsigned int	num;
	int				count;
	char			c;

	num = u;
	count = 0;
	if (num > 9)
		count += ft_forunnbr(num / 10);
	c = (num % 10) + '0';
	write (1, &c, 1);
	count++;
	return (count);
}

int	ft_forhex(int x, char type)
{
	int	count;

	count = 0;
	if (type == 'x')
		count = ft_putnbrhex((unsigned long)x);
	if (type == 'X')
		count = ft_putnbrhexcap((unsigned long)x);
	return (count);
}
