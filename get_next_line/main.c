#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

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
}

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
