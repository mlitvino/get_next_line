/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:53:44 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/26 15:43:09 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	int p = open("text.txt", O_RDWR);
	char *line;

	line = get_next_line(p);
	printf("%s\n", line);
	if (line != NULL)
		free(line);

	line = get_next_line(p);
	printf("%s\n", line);
	if (line != NULL)
		free(line);


	/*line = get_next_line(p);
	printf("%s\n", line);
	free(line);*/
	/*while((line = get_next_line(p)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(p);*/


	return (0);
}
