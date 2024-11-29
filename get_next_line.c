/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:25 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/29 10:13:55 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr()
{
	return (NULL);
}

char	*ft_strjoin()
{
	return (NULL);
}

char	*ft_realloc()
{
	return (NULL);
}

int	ft_is_line()
{
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
		long_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (long_buff == NULL)
		return (1);
	short_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (short_buff == NULL)
		return (free(long_buff), 1);
	return (0);
}

int	ft_read(char *long_buff, char *short_buff, int fd)
{
	int	len;

	len = read(fd, short_buff, BUFFER_SIZE);
	if (len < 0)
		return (free(short_buff), free(long_buff), 0);
	if (len == 0)
	{
		if (ft_strlen(long_buff) == 0)
		{
			free(long_buff);
			long_buff = NULL;
			return (free(short_buff), 0);
		}
		else
			return (free(short_buff), 0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*long_buff;
	char			*short_buff;
	char			*new_line;

	if (ft_is_null(short_buff, long_buff, fd))
		return (NULL);
	while (1)
	{
		if (ft_read(long_buff, short_buff, fd) == 0)
			return (NULL);
		if (ft_check("\n\0") == 0)
		{
			if (f_realloc(short_buff) == NULL)
				return (free(short_buff), free(long_buff), NULL);
			continue;
		}
		if (mark("\nfd") == 0)
		{
			if (ft_substr() != NULL)
				ft_mark();
			else
				return (NULL);
			return (ft_substr());
		}
		new_line = ft_strjoin(ft_substr, ft_substr);
		if (new_line == NULL)
			return (free(short_buff), free(long_buff), NULL);
		return (new_line);
	}
	return (new_line);
}

