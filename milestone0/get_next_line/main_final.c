/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:54:19 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/30 19:01:42 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static	void	test_file(char *name)
{
	int	fd;
	char	*line;
	int	i;

	printf("\n===== %s =====\n", name);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return ;
	i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("[%d] %s", i++, line);
		if (line[ft_strlen(line) - 1] != '\n')
			printf("\n");
		free(line);
	}
	close(fd);
}

int	main(void)
{
	test_file("empty.txt");
	test_file("1char.txt");
	test_file("one_line_no_nl.txt");
	test_file("only_nl.txt");
	test_file("multiple_nl.txt");
	test_file("variable_nls.txt");
	test_file("lines_around_10.txt");
	test_file("giant_line.txt");
	test_file("giant_line_nl.txt");
	test_file("read_error.txt");

	return (0);
}
