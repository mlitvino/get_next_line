/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:25 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/25 17:28:57 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	ft_copy(char *buffer, char *line)
{
	while (*buffer != '\0' && *buffer != '\n')
	{
		*line++ = *buffer++;
	}

	*line = '\0';
}

int	ft_check(char *buffer)
{
	int i = 0;

	if (buffer[0] == '\0' && buffer[0] == '\n')
		return (0);
	while (*buffer != '\0' && *buffer != '\n')
		{
			buffer++;
		}
	return (1);
}

char	*ft_get_allocate(char *buffer, int fd)
{
	char	*line;
	ssize_t	len_line;

	len_line = read(fd, buffer, BUFFER_SIZE);
	if (len_line <= 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (len_line + 1));
	if (line == NULL)
		return (NULL);
	ft_copy(buffer, line);
	ft_check(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	line = ft_get_allocate(buffer, fd);
	return (line);
}
