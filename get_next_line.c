/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:25 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/03 17:11:20 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**ft_init_buf(char **buf_tab, int *buf_len)
{
	int	i;

	*buf_len = 0;
	if (buf_tab != NULL)
	{
		while (buf_tab[*buf_len] != NULL)
			(*buf_len)++;
		return (buf_tab);
	}
	*buf_len = 10;
	buf_tab = (char **)malloc(sizeof(char *) * (*buf_len + 1));
	if (buf_tab == NULL)
		return (NULL);
	i = 0;
	while (i < *buf_len)
	{
		buf_tab[i] = (char *)malloc(1);
		if (buf_tab[i] == NULL)
			return (ft_free_buf(&buf_tab, i), NULL);
		buf_tab[i][0] = '\0';
		i++;
	}
	buf_tab[i] = NULL;
	return (buf_tab);
}

char	**ft_realloc_buf_tab(char **old_tab, int old_size, int new_size)
{
	char	**new_tab;
	int		i;

	i = 0;
	if (old_tab == NULL)
		return (NULL);
	new_tab = (char **)malloc(sizeof(char *) * (new_size + 1));
	if (new_tab == NULL)
		return (ft_free_buf(&old_tab, old_size), NULL);
	while (i < old_size)
	{
		new_tab[i] = old_tab[i];
		old_tab[i] = NULL;
		i++;
	}
	while (i < new_size)
	{
		new_tab[i] = (char *)malloc(1);
		if (new_tab[i] == NULL)
			return (ft_free_buf(&new_tab, i), ft_free_buf(&old_tab, old_size), NULL);
		new_tab[i][0] = '\0';
		i++;
	}
	new_tab[new_size] = NULL;
	return (ft_free_buf(&old_tab, old_size), new_tab);
}

char    *ft_free_buf(char ***buf_tab, int buf_len)
{
    int    i;

    i = 0;
    if (*buf_tab == NULL)
        return (NULL);
    while (i <= buf_len)
    {
        if ((*buf_tab)[i])
        {
            free((*buf_tab)[i]);
            (*buf_tab)[i] = NULL;
        }
        i++;
    }
    free(*buf_tab);
    (*buf_tab) = NULL;
    return (NULL);
}
#include <stdio.h>
char	*ft_read(char ***buf_tab, int fd, int tab_len, int *buf_len)
{
	int	len;

	len = read(fd, &(*buf_tab)[fd][*buf_len], BUFFER_SIZE);
	*buf_len += len;
	while (len > 0)
	{
		if (ft_strchr((*buf_tab)[fd], buf_len) > 0)
			return (ft_substr((*buf_tab)[fd], buf_len));
		(*buf_tab)[fd] = ft_realloc((*buf_tab)[fd], buf_len);
		if ((*buf_tab)[fd] == NULL)
			return (NULL); // ft_free_buf((*buf_tab), tab_len),
		len = read(fd, &(*buf_tab)[fd][ft_strlen((*buf_tab)[fd])], BUFFER_SIZE);
	}
	if (len < 0)
		return (ft_free_buf(buf_tab, tab_len), NULL); // ft_free_buf((*buf_tab), tab_len),
	if (ft_strchr((*buf_tab)[fd], buf_len) > 0)
		return (ft_substr((*buf_tab)[fd], buf_len));
	*buf_len = tab_len;
	printf("len %d\n", len);

	//printf("buf_en %d\n", *buf_len);
	while (buf_tab != NULL && *buf_tab != NULL  && *buf_tab[6] != NULL && tab_len >= 0)
	{
		if (ft_strlen(*buf_tab[6]) > 0)
			return (NULL);
		else
			return NULL;
		tab_len--;
	}

	ft_free_buf(buf_tab, *buf_len);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	**buf_tab = NULL;
	char		*new_line;
	int			tab_len;
	int			buf_len;

	buf_tab = ft_init_buf(buf_tab, &tab_len);
	// if (tab_len <= fd)
	// 	buf_tab = ft_realloc_buf_tab(buf_tab, tab_len, fd + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || buf_tab == NULL)
		return (ft_free_buf(&buf_tab, tab_len), NULL);
	buf_tab[fd] = ft_realloc(buf_tab[fd], 0);
	if (buf_tab[fd] == NULL)
		return (ft_free_buf(&buf_tab, tab_len), NULL);
	buf_len = ft_strlen(buf_tab[fd]);
	printf("size:%d fd:%d\n", buf_len, fd);
	new_line = ft_read(&buf_tab, fd, tab_len, &buf_len);
	buf_len = tab_len;
	while (buf_tab != NULL && buf_len-- >= 0) // new_line != NULL &&
		if (ft_strlen(buf_tab[buf_len + 1]) > 0)
			return (new_line);
	// if (new_line != NULL)
	// 	return (new_line);
	ft_free_buf(&buf_tab, tab_len);
	return (new_line);
}


/*when realloc NULL */
