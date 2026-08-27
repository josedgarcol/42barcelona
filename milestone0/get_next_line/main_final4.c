/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_final4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:15:52 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/30 18:36:36 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

static void	print_line(char *line, int fd)
{
	if (line)
	{
		printf("[fd %d] %s", fd, line);
		free(line);
	}
}

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	char	*line;
	int	alive;

	fd1 = open("multiple_nl.txt", O_RDONLY);
	fd2 = open("lines_around_10.txt", O_RDONLY);
	fd3 = open("variable_nls.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (1);
	
	while (1)
	{
		alive = 0;

		line = get_next_line(fd1);
		if (line)
		{
			print_line(line, fd1);
			alive = 1;
		}
		line = get_next_line(fd2);
		if (line)
		{
			print_line(line, fd2);
			alive = 1;
		}
		line = get_next_line(fd3);
		if (line)
		{
			print_line(line, fd3);
			alive = 1;
		}
		if (!alive)
			break ;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
