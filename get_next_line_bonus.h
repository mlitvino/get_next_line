/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:51:07 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/04 17:51:08 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_realloc_buf(char *buffer, int *new_size);
int		ft_strchr_buf(char *buffer, int *buf_len);
char	*ft_sub_buf(char *buffer, int *buf_len, char ***buf_tab, int tab_len);
int		ft_strlen_buf(char *buffer);
void	ft_bzero_buf(char *buffer, int size);
char	*free_buf(char ***buf_tab, int buf_len);
char	**ft_init_buf(char **buf_tab, int *buf_len);
char	*ft_read(char ***buf_tab, int fd, int tab_len, int *buf_len);
char	**ft_realloc_buf_tab(char **old_tab, int *old_size, int new_size);


#endif
