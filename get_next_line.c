/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:25 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/29 17:26:01 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *buffer)
{
	return (NULL);
}

int	ft_strlen(char *buffer)
{
	int	len;

	len = 0;
	if (buffer == NULL)
		return (0);
	while (buffer[len])
		len++;
	return (len);
}

char	*ft_realloc(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		buf_size;

	i = 0;
	buf_size = ft_strlen(buffer);
	new_buffer = (char *)malloc(sizeof(char) * buf_size + BUFFER_SIZE + 1);
	if (new_buffer == NULL)
		return (NULL);
	while (i < buf_size + BUFFER_SIZE)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	return (free(buffer), new_buffer);
}

char	*ft_free_buf(char **buffer, int buf_len)
{
	if (buffer == NULL)
		return (NULL);
	while (buf_len >= 0)
	{
		free(buffer[buf_len]);
		buf_len--;
	}
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	**ft_init_buf(char **buffer, int *buf_size)
{
	int	i;

	if (buffer != NULL)
	{
		while (buffer[*buf_size] != NULL)
			*buf_size++;
		return (buf_size++, buffer);
	}
	*buf_size = 11;
	buffer = (char **)malloc(sizeof(char *) * (10 + 1));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < 10)
	{
		buffer[i] = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buffer[i] == NULL)
			return (ft_free_buf(buffer, i));
		buffer[i][BUFFER_SIZE] = '\0';
		buffer[i][0] = '\0';
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}

char	*ft_read(char **buffer, int fd, int buf_size)
{
	int	len;

	if (ft_strlen(buffer[fd]) > 0)
		buffer[fd] = ft_realloc(buffer[fd]);
	if (buffer[fd] == NULL)
		return (ft_free_buf(buffer, buf_size), NULL);
	len = read(fd, buffer[fd][ft_strlen(buffer[fd])], BUFFER_SIZE);
	while (len > 0)
	{
		if (ft_strchr(buffer[fd], "\n") == 1)
			return (ft_substr(buffer[fd]));
		if (ft_strchr(buffer[fd], "\n") == 0)
			buffer[fd] = ft_realloc(buffer[fd]);
		if (buffer[fd] == NULL)
			return (ft_free_buf(buffer, buf_size), NULL);
		len = read(fd, buffer[fd][ft_strlen(buffer[fd])], BUFFER_SIZE);
	}
	if (len < 0)
		return (ft_free_buf(buffer, 0), NULL);
	while (buf_size >= 0)
		if (ft_strlen(buffer[buf_size--]) > 0)
			return (NULL);
	return (free(buffer),NULL);
}

char	**ft_realloc_buffer(char **old_buffer, int old_size, int new_size)
{
	char	**new_buffer;
	int		i;

	i = 0;
	if (old_buffer == NULL)
		return (NULL);
	new_buffer = (char **)malloc(sizeof(char *) * (new_size));
	if (new_buffer == NULL)
		return (ft_free_buf(old_buffer, old_size), NULL);
	while (i < new_size)
	{
		new_buffer[i] = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (new_buffer[i] == NULL)
		{
			ft_free_buf(old_buffer, old_size);
			return (ft_free_buf(new_buffer, i), NULL);
		}
		new_buffer[i][BUFFER_SIZE] = '\0';
		new_buffer[i][0] = '\0';
		i++;
	}
	while (old_size >= 0)
		ft_bufcpy(new_buffer[old_size], old_buffer[old_size]);
	new_buffer[i] = NULL;
	return (ft_free_buf(old_buffer, old_size), new_buffer);
}

char	*get_next_line(int fd)
{
	char static	**buffer;
	char		*new_line;
	int		buf_size;

	buf_size = 0;
	buffer = ft_init_buf(buffer, &buf_size);
	if (buf_size < fd + 1)
		buffer = ft_realloc_buffer(buffer, buf_size, fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || buffer == NULL)
		return (ft_free_buf(buffer, buf_size), NULL);
	new_line = ft_read(buffer, fd, buf_size);
	return (new_line);
}
