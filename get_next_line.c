/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:25 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/26 16:15:03 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	ft_strcpy(char *dst, char *src, int len)
{
	int i = 0;

	if (dst == NULL || src == NULL)
		return ;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

int	ft_newline(char *buffer, int len_line)
{
	int	i;

	i = 0;
	while (i < len_line)
	{
		if (!buffer || buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_realloc(char *buffer, int *size, int len_line)
{
	char 	*new;
	int		len;

	new = (char *)malloc(sizeof(char) * *size * 2 + 1);
	if (new == NULL)
		return (NULL);
	*size *= 2;
	ft_strcpy(new, buffer, len_line);
	free(buffer);
	return (new);
}

char	*ft_substr(char *str, int len)
{
	char			*substr;
	int				i;

	substr = malloc(sizeof(*str) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = str[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_get_allocate(char *buffer, int fd)
{
	char	*line;
	ssize_t	len_line;
	int stop;
	int	size = BUFFER_SIZE;

	len_line = read(fd, buffer, BUFFER_SIZE);
	if (len_line <= 0)
		return (free(buffer), NULL);
	stop = ft_newline(buffer, len_line);
	while (stop < 0)
	{
		buffer = ft_realloc(buffer, &size, len_line);
		len_line += read(fd, buffer + len_line, BUFFER_SIZE);
		if (len_line <= 0)
			return (free(buffer), NULL);
		stop = ft_newline(buffer, len_line);
	}
	line = ft_substr(buffer,  stop);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	line = ft_get_allocate(buffer, fd);
	return (line);
}
