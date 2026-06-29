/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:04:55 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/29 15:21:04 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
//#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	test_file("empty.txt");
	test_file("1char.txt");
	test_file("one_line_no_n1.txt");
	test_file("only_n1.txt");
	test_file("multiple_nl.txt");
	test_file("variable_nls.txt");
	test_file("lines_around_10.txt");
	test_file("giant_line.txt");
	test_file("giant_line_nl.txt");
	test_file("read_error.txt");
	return (0);
}*/

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("variable_nls.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
		free(line);
	close(fd);
}


/*
static void	test_file(char *name)
{
	int	fd;
	char	*line;
	int	i;

	printf("\n === %s === \n", name);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return ;
	i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("[%d] %s", i++, line);
		if (line[ft_strlen(line) - 1] != '\n')
			printf("\n");

		free (line);
	}
	close (fd);
}
*/
/*
int	main(int ac, char **argv)
{
	int	fd;
	char	*line;

	int fd1 = open("test2.txt", O_RDONLY);
	int fd2 = open("archivo2.txt", O_RDONLY);
	char *line1, *line2;

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);

	if (ac != 2)
	{
		printf("Uso: %s archivo\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	printf("--- Contenido de %s ---\n", argv[1]);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	printf("--- Fin del archivo ---\n");
	return (0);
}*/

/*
int	main(int ac, char **argv)
{
	int	fd1;
	int	fd2;
	char	*line1;
	char	*line2;
	int	active;

	if (ac != 3)
		return (0);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	active = 2;
	while (active > 0)
	{
		if (fd1 != -1)
		{
			line1 = get_next_line(fd1);
			if (!line1)
			{
				close(fd1);
				fd1 = -1;
				active = active - 1;
			}
			else
			{
				printf("[%s], %s", argv[1], line1);
				free(line1);
			}
		}
		if (fd2 != -1)
		{
			line2 = get_next_line(fd2);
			if (!line2)
			{
				close(fd2);
				fd2 = -1;
				active = active - 1;
			}
			else
			{
				printf("[%s] %s", argv[2], line2);
				free(line2);
			}
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}*/

/*int	main(int ac, char **argv)
{
	int	i;
	char **res;

	while (ac > 1)
	{
		i = 0;
		res = get_next_line(argv[1], ' ');
		while(res[i])
		{
			printf("%s\n", res[i]);
			i++;
		}
	}
	return (0);
}*/

/*int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}*/	
	/*while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
