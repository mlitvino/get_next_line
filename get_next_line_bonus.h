/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:49 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/04 14:31:43 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_realloc(char *buffer, int *new_size);
int		ft_strchr(char *buffer, int *buf_len);
char	*ft_substr(char *buffer, int *buf_len);
int		ft_strlen(char *buffer);
void	ft_bzero(char *buffer, int size);
char	*ft_free_buf(char ***buf_tab, int buf_len);
char	**ft_init_buf(char **buf_tab, int *buf_len);
char	*ft_read(char ***buf_tab, int fd, int tab_len, int *buf_len);
char	**ft_realloc_buf_tab(char **old_tab, int *old_size, int new_size);

#endif
