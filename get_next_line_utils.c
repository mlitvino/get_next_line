/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:59:36 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/02 19:46:37 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *buffer, int size)
{
	if (buffer == NULL)
		return ;
	while (size > 0)
	{
		buffer[size - 1] = '\0';
		size--;
	}
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

char	*ft_substr(char *buffer, int *buf_len)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	new_line = (char *)malloc(sizeof(char) * (*buf_len + 2));
	if (new_line == NULL)
		return (NULL);
	while (i <= *buf_len)
	{
		new_line[i] = buffer[i];
		i++;
	}
	new_line[i] = '\0';
	j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
	return (new_line);
}

int	ft_strchr(char *buffer, int *buf_len)
{
	int	i;

	i = 0;
	if (!buffer || *buf_len <= 0)
		return (-1);
	while (i < *buf_len)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			*buf_len = i;
			return (1);
		}
		i++;
	}
	return (-1);
}

char	*ft_realloc(char *buffer, int *new_size)
{
	char	*new_buffer;
	int		i;
	int		buf_size;

	i = 0;
	buf_size = ft_strlen(buffer);
	new_buffer = (char *)malloc(sizeof(char) * (buf_size + BUFFER_SIZE + 1));
	if (new_buffer == NULL)
		return (NULL);
	if (new_size != NULL)
		*new_size = buf_size + BUFFER_SIZE;
	while (i < buf_size)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	ft_bzero(new_buffer + buf_size, BUFFER_SIZE + 1);
	if (buffer == NULL)
		ft_bzero(new_buffer, BUFFER_SIZE);
	if (buffer != NULL)
		free(buffer);
	return (new_buffer);
}
