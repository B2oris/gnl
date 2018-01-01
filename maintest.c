#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int 	num;

	line = NULL;
	num = 1;
	if (argc > 1)
	{
		if (argc > 2 || (fd = open(argv[1], O_RDONLY)) != -1)
		{
			if (argc > 3)
				printf("%d", get_next_line(23, &line));
			else
			{
				if (argc > 2)
					fd = 0;
				while (get_next_line(fd, &line) == 1)
				{
					//ft_putnbr(num++);
					printf("%s\n", line);
					memset(line, '*', strlen(line));
					free(line);
					line = NULL;
				}
				if (line)
				{
					printf("%s", line);
					ft_putstr("last line");
					memset(line, '*', strlen(line));
					free(line);
					line = NULL;
				}
				close(fd);
			}
		}
	}
	return (0);
}
