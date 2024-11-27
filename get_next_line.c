/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:25 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/27 13:43:11 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *buffer, int i)
{
	char	*new_line;

	if (buffer[i] == '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * i + 1);
	if (new_line == NULL)
		return (NULL);
	new_line[i] = '\0';
	while (--i >= 0)
	{
		new_line[i] = buffer[i];
	}
	return (new_line);
}

char	*ft_realloc(char *buffer, int *buf_size, int buf_len)
{
	char	*new_buffer;
	int		i;

	i = 0;
	new_buffer = (char *)malloc(sizeof(char) * (*buf_size * 2) + 1);
	if (new_buffer == NULL)
		return (free(buffer), NULL);
	while (i < buf_len)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	*buf_size *= 2;
	free(buffer);
	return (new_buffer);
}

char	*ft_find(char *buffer, int fd)
{
	int		i;
	int		buf_size;
	char	*new_line;

	buf_size = BUFFER_SIZE;
	i = 0;
	while (i < buf_size)
	{
		if (read(fd, &buffer[i], 1) <= 0)
			return (free(buffer), NULL);
		if (buffer[i] == 0 || buffer[i] == '\n')
		{
			new_line = ft_substr(buffer, i);
			return (free(buffer), new_line);
		}
		i++;
		if (i == buf_size)
		{
			buffer = ft_realloc(buffer, &buf_size, i);
			if (buffer == NULL)
				return (NULL);
		}
	}
	return (free(buffer), NULL);
}

char	*get_next_line(int fd)
{
	static char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	return (ft_find(buffer, fd));
}
