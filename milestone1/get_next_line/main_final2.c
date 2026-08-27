/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_final2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:05:59 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/30 19:20:53 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("variable_nls.txt", O_RDONLY);
	if (fd < 0)
	{
		return (1);
	}
	while ((line = get_next_line(fd)))
		free(line);
	close(fd);
}
