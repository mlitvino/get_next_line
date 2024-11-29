/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:25 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/29 11:35:36 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *from, char *to)
{
	return (NULL);
}

char	*ft_strjoin()
{
	return (NULL);
}

char	*ft_realloc(char *buffer)
{
	char	*new_buffer;
	int		i;
	int 	buf_len;

	i = 0;
	buf_len = ft_strlen(buffer);
	new_buffer = (char *)malloc(sizeof(char) * buf_len + BUFFER_SIZE + 1);
	if (new_buffer == NULL)
		return (NULL);
	while (i < buf_len + BUFFER_SIZE)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	return (free(buffer), new_buffer);
}

int	ft_check(char *buff, int buf_len, char *check, int fd)
{
	int	i;

	i = 0;
	while (fd >= 0 && i < buf_len)
	{
		if (buff[i] == '\n'|| buff[i] == '\0')
			return (1);
		i++;
		if (i == buf_len)
			return (0);
	}

	return (0);
}

int	ft_mark()
{


	return (0);
}

int	ft_is_null(char *short_buff, char *long_buff, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (1);
	if (long_buff == NULL)
	{
		long_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (long_buff == NULL)
			return (1);
		long_buff[0] = '\0';
	}
	short_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (short_buff == NULL)
		return (free(long_buff), 1);
	short_buff[BUFFER_SIZE] = '\0';
	return (0);
}

int	ft_read(char *long_buff, char *short_buff, int fd)
{
	int	len;

	len = read(fd, short_buff, BUFFER_SIZE);
	if (len < 0)
		return (free(short_buff), free(long_buff), -1);
	if (len == 0)
	{
		if (ft_strlen(long_buff) != 0)
			return (free(short_buff), 0);
		free(long_buff);
		long_buff = NULL;
		return (free(short_buff), 0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*long_buff;
	char			*short_buff;
	char			*new_line;
	int				len;

	if (ft_is_null(short_buff, long_buff, fd))
		return (NULL);
	while (1)
	{
		len = ft_read(long_buff, short_buff, fd);
		if (len <= 0)
			return (NULL);
		if (ft_check(short_buff, len, "\n\0", -1) == 0)
		{
			if (ft_realloc(short_buff) == NULL)
				return (free(short_buff), free(long_buff), NULL);
			continue;
		}
		if (ft_check(long_buff, "\n", fd, 0) == 0)
		{
			if (ft_substr(short_buff, long_buff) == NULL)
				return (NULL);
			ft_mark(long_buff, fd);
			return (ft_substr(short_buff, NULL));
		}
		new_line = ft_strjoin(ft_substr, ft_substr);
		if (new_line == NULL)
			return (free(short_buff), free(long_buff), NULL);
		break;
	}
	return (free(short_buff), new_line);
}

