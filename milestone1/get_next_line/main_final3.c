/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_final3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:10:24 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/30 18:12:28 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("one_line_no_nl.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("'%s'", line);
	free(line);

	line = get_next_line(fd);
	printf("%p\n", line);

	close(fd);
}
