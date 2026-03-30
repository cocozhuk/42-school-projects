/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:07:35 by kzhu              #+#    #+#             */
/*   Updated: 2025/12/03 22:26:24 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -Wall -Wextra -Werror ft_printf.c ft_printf_helper.c ft_toolbox.c libft.a 

#include "ft_printf.h"

int	ft_type(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (type == 's')
		return (ft_forstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_forptr(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_fornbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_forunnbr(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_forhex((va_arg(args, unsigned int)), type));
	else if (type == '%')
		return (ft_putchar_fd('%', 1), 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			count += ft_type(format[i + 1], args);
			i = i + 2;
		}
		else
		{
			write(1, &format[i++], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
