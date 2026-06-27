/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 13:30:32 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/27 13:35:40 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char *get_next_line(int fd);

int main(void)
{
    int fd = open("giant_line.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    printf("len = %zu\n", ft_strlen(line));
    printf("last = %d\n", line[19999]);
    printf("next = %d\n", line[20000]);

    free(line);

    line = get_next_line(fd);
    printf("%p\n", line);

    return (0);
}
