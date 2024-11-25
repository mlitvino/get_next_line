/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:53:44 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/25 17:11:26 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int p = open("text.txt", O_RDWR);

	char *line;

	line = get_next_line(p);
	printf("%s", line);
	free(line);
	/*while((line = get_next_line(p)) != NULL)
	{
		printf("%s", line);
		free(line);
	}*/
	close(p);

	return (0);
}
