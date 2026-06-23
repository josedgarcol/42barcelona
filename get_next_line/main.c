#include <stdio.h>
#include "get_next_line.h"


int	main(int ac, char **argv)
{
	int	fd;
	char	*line;

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
}


/*int	main(int argc, char **argv)
{
	int	i;
	char **res;

	while (argc > 1)
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
