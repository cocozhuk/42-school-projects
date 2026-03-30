/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <kzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:14:16 by kzhu              #+#    #+#             */
/*   Updated: 2026/03/10 17:17:21 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_forstr(char *str);
int		ft_forptr(void *ptr);
int		ft_putnbrhex_ptr(unsigned long address);
int		ft_putnbrhex(unsigned int address);
int		ft_putnbrhexcap(unsigned int address);
int		ft_fornbr(int i);
int		ft_forunnbr(unsigned int u);
int		ft_forhex(int x, char type);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
