/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:31:31 by kzhu              #+#    #+#             */
/*   Updated: 2026/03/25 15:50:32 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhex_ptr(unsigned long address)
{
	char	*hex;
	char	c;
	char	count;

	count = 0;
	hex = "0123456789abcdef";
	if (address > 15)
		count += ft_putnbrhex_ptr(address / 16);
	c = hex[(address % 16)];
	write (1, &c, 1);
	count ++;
	return (count);
}

int	ft_putnbrhex(unsigned int address)
{
	char	*hex;
	char	c;
	char	count;

	count = 0;
	hex = "0123456789abcdef";
	if (address > 15)
		count += ft_putnbrhex(address / 16);
	c = hex[(address % 16)];
	write (1, &c, 1);
	count ++;
	return (count);
}

int	ft_putnbrhexcap(unsigned int address)
{
	char	*hex;
	char	c;
	char	count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (address > 15)
		count += ft_putnbrhexcap(address / 16);
	c = hex[(address % 16)];
	write (1, &c, 1);
	count ++;
	return (count);
}
