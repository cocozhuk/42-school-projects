/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:12:20 by kzhu              #+#    #+#             */
/*   Updated: 2025/12/11 16:47:32 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
// »»-----► Number of lines: 12
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (s1 == NULL)
	{
		s1 = malloc(1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (free(s1), NULL);
	final = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (final == NULL)
		return (free(s1), NULL);
	while (s1[++i])
		final[i] = s1[i];
	while (s2[j])
		final[i++] = s2[j++];
	final[i] = '\0';
	free(s1);
	return (final);
}
