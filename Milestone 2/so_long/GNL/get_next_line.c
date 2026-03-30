/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:12:15 by kzhu              #+#    #+#             */
/*   Updated: 2025/12/11 16:12:15 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	ssize_t	bytes;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free(stash), NULL);
	while (stash == NULL || ft_strchr(stash, '\n') == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (stash == NULL)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

char	*get_new_line(char *stash)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!stash || !stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		new_line = malloc (sizeof(char) * (i + 2));
	else
		new_line = malloc (sizeof(char) * (i + 1));
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		new_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	int		len;
	char	*new_stash;

	i = 0;
	j = 0;
	if (!stash || !stash[0])
		return (free(stash), NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	len = ft_strlen_gnl(stash);
	new_stash = malloc(sizeof(char) * (len - i + 1));
	if (new_stash == NULL)
		return (free(stash), NULL);
	i = i + 1;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (free(stash), new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_new_line(stash);
	stash = clean_stash(stash);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}
int main()
{
    int fd;
	char *line;

	fd = open("output_test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
    {
        printf("GNL Return: %s", line);
        free(line);
    }
    close (fd);
}*/
