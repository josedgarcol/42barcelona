#include <stdio.h>
#include "get_next_line.h"

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

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
