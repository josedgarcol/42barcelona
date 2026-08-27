/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_final5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:07:30 by jcolque           #+#    #+#             */
/*   Updated: 2026/07/01 15:07:47 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	char	*line;

	if (argc < 2)
	{
		write(2, "Error: indique argumentos\n", 52 - 27 + 1);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			perror("Error abriendo archivo");
			return (1);
		}
		while ((line = get_next_line(fd)))
		{
			printf("%s", line);
			free(line);
		}	
		i++;
		close(fd);
	}
	return (0);
}
