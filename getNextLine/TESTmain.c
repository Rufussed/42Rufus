#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	line_count = 0;
	char	*next_line;

	printf("\n Compile SUCCESS!! \n");

	fd = open("test.txt", O_RDONLY);
	printf("\nfd: %i, test.txt contains some sentences\n", fd);
	next_line = get_next_line(fd);
	while (next_line)
	{
		line_count++;
		printf("Line %i: %s", line_count, next_line);
		next_line = get_next_line(fd);
	}
	printf("\n");
	close(fd);
	line_count = 0;

	// test 1
	fd = open("test1.txt", O_RDONLY);
	printf("\nfd: %i, test2.txt contains only EOF\n", fd);
	next_line = get_next_line(fd);
	while (next_line)
	{
		line_count++;
		printf("Line %i: %s", line_count, next_line);
		next_line = get_next_line(fd);
	}
	printf("\n");
	close(fd);
	line_count = 0;

	// test 1
	fd = open("test2.txt", O_RDONLY);
	printf("\nfd: %i, test2.txt contains 1\n", fd);
	next_line = get_next_line(fd);
	while (next_line)
	{
		line_count++;
		printf("Line %i: %s", line_count, next_line);
		next_line = get_next_line(fd);
	}
	printf("\n\n");
	close(fd);
	line_count = 0;
	
	return (0);
}
