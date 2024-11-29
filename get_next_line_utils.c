/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ne.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:59:36 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/29 18:08:15 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *buffer, int size)
{
	while (size >= 0)
		buffer[size--] = '\0';
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

char	*ft_substr(char *buffer)
{
	return (NULL);
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
	while (i < buf_size + BUFFER_SIZE && buffer != NULL)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	if (buffer == NULL)
		ft_bzero(new_buffer, BUFFER_SIZE);
	return (free(buffer), new_buffer);
}
