// char *get_next_line(int fd)
// {
//     char    *buffer;
//     char    *line;   
//     ssize_t bytes_read;

//     if (fd == -1) {
//         return (NULL);
//     }

//     buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
//     if (buffer == NULL)
//         return (NULL);
//     bytes_read = read(fd, (void*)buffer, BUFFER_SIZE);
//     if (bytes_read < 0)
//         return (NULL);
//     line =(char *)buffer;
//     return (line);
// }

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	line_count = 0;
	char	*next_line;

	// Open the file in read-only mode
	fd = open("test.txt", O_RDONLY);
	if (fd == -1) 
	{
		perror("Error opening file");
		return 1;
	}
    // call function;
    next_line = get_next_line(fd);

    //print lines in a loop
    while (next_line)
    {
        line_count++;
        printf("\nLine %i: %s", line_count, next_line);
        next_line = get_next_line(fd);
    }
  
    // Close the file descriptor
    close(fd);
    return 0;
}
