/*Name: ft_popen
Allowed functions: pipe, fork, dup2, execvp, close, exit
--------------------------------------------------------------------------------
Write the following function:

int ft_popen(const char *file, const char *argv[], char type);

The function must launch the executable file with the arguments argv (using execvp).
If type is 'r' the function must return a file descriptor connected to the output of the command.
If type is 'w' the function must return a file descriptor connected to the input of the command.
In case of error or invalid parameter the function must return -1.

For example the function could be used like that:

int main()
{
    int fd = ft_popen("ls", (const char *[]) {"ls", NULL}, 'r');
    char *line;
    while ((line = get_next_line(fd)))
        ft_putstr(line);
}

Hints:
Do not leak file descriptors.*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_popen(const char *file, const char *argv[], char type)
{
	int pid;
	int fd[2];

	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		if (type == 'r') // 'read' the output of the child in the parent
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
		}
		if (type == 'w') // 'write' to the input of the child from the parent
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		execvp(file, (char *const *)argv);
		exit(1); // execvp failed
	}
	else // child
	{
		if (type == 'r')
		{
			close(fd[1]);
			return fd[0]; // return the read end of the pipe
		}
		if (type == 'w')
		{
			close(fd[0]);
			return fd[1]; // return the write end of the pipe
		}
	}
	return -1; // reuired by subject;
}


int main() {
    // Example usage: Read the output of the 'ls' command
    int fd = ft_popen("ls", (const char *[]){"ls", NULL}, 'r');
	
    if (fd == -1) 
    {
        perror("ft_popen");
        return 1;
    }

    // Read and print the output from the 'ls' command
    char buffer[128];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) 
    {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
    }

    // Close the read-end
    close(fd);

    return 0;
}
// int main()
// {
//     int fd = ft_popen("echo", (const char *[]) {"echo","hello", NULL}, 'r');
//    char buffer[1024];
//     ssize_t bytes_read;

//     // Read from the pipe
//     while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
//     {
//         buffer[bytes_read] = '\0'; // Null-terminate the buffer
//         printf("%s", buffer);
//     }

//     close(fd);
//     return 0;
// }

// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>



// int main() {
//     int fd = ft_popen("cat", (const char *[]){"cat", NULL}, 'w');
//     if (fd == -1) 
// 	{
//         perror("ft_popen");
//         return 1;
//     }

//     // Write to the child's stdin
//     const char *message = "Hello, from parent to child via pipe!\n";
//     write(fd, message, strlen(message));

// 	 // Close the write-end to signal EOF to the child process
//     close(fd); // Close the write-end to signal EOF
//     return 0;
// }
// int main() {
//     int fd = ft_popen("cat", (const char *[]){"cat", NULL}, 'w');
//     if (fd == -1) 
//     {
//         perror("ft_popen");
//         return 1;
//     }

//     // Write to the child's stdin
//     const char *message1 = "Hello, from parent to child via pipe!\n";
//     write(fd, message1, strlen(message1));

//     // Write another message to the child's stdin
//     const char *message2 = "Another message from parent to child via pipe!\n";
//     write(fd, message2, strlen(message2));

//     // Close the write-end to signal EOF to the child process
//     close(fd);

//     // Now open a pipe to read the output of the 'cat' command
//     fd = ft_popen("cat", (const char *[]){"cat", NULL}, 'r');
//     if (fd == -1) 
//     {
//         perror("ft_popen");
//         return 1;
//     }

//     // Read and print the output from the child's stdout
//     char buffer[128];
//     ssize_t bytes_read;
//     while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) 
//     {
//         buffer[bytes_read] = '\0'; // Null-terminate the buffer
//         printf("%s", buffer);
//     }

//     // Close the read-end
//     close(fd);

//     return 0;
// }