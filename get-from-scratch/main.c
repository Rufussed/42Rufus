#include "get_next_line.h"

int main(void)
{
	int fd;
    char *line;
    int i;

    printf("Testing:\n");

    fd = open("test.txt", O_RDONLY);
    printf("fd:%d\n", fd);
    i = 0;
    line = "0";

    while (line)
    {
    line = get_next_line(fd);
	printf("line %d: %s", i, line);
	free(line);
    i++;
    }
    close(fd);
    return (0);    
}