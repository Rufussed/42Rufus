/*assignment: picoshell

Allowed functions: close, fork, wait, exit, execvp, dup2, pipe
--------------------------------------------------------------------------------
Write the followingfunction

int picoshell(char **cmds[]);

The goal of this function is to execute a pipeline.
It must execute each commands of cmds and connect the output of one to the input
of the next command (just like a shell)

Cmds contains a null-terminated list of valid commands.
Each rows of cmds are an argv array directly useable for a call to execvp.
The first arguments of each command is the command name or path and can be
passed directly as the first argument of execvp.

If any error occur, the function must return 1 (you must of course close all the
open fds before), otherwise the function must wait all child processes and return 0

You will find in this directory a file main.c which contain something to help you
test your function.

For example this should work:
$>./picoshell /bin/ls "|" /usr/bin/grep picoshell
picoshell

$>./picoshell echo 'squalala!' "|" cat "|" sed 's/a/b/g'
squblblb!

Hints:
Do not leak file descriptors*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
    int fd[2];
    int prev_fd = 0;
    int i = 0;
    int pid;
    
    while(cmds[i])
    {
        if (cmds[i + 1])
            pipe(fd);
       	pid = fork();
        if (pid == 0)
        {
            if (prev_fd)
            {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }
            if (cmds[i + 1])
            {
                close(fd[0]);
            	dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }
        else
        {
            if (prev_fd)
                close(prev_fd);
            if (cmds[i + 1])
            {
                prev_fd = fd[0];
                close(fd[1]);
            }
        }
        i++;
    }
    while (wait(NULL) > 0)
        ;
    return 0;
}

// int picoshell(char **cmds[])
// {
//     int fd[2];
//     int prev_fd = 0;
//     int i = 0;
//     int pid;
    
//     while(cmds[i])
//     {
//         if (cmds[i + 1]) // if next cmd exists we need a pipe
//         {
//             if (pipe(fd) < 0)
//             {
//                 if (prev_fd)
//                     close(prev_fd);
//                 return 1;
//             }
//         }
//         pid = fork();
//         if (pid == 0) // child process
//         {
//             if (prev_fd)
//             {
//                 if (dup2(prev_fd, STDIN_FILENO) < 0)
//                 {
//                     close(prev_fd);
//                     exit(1);
//                 }
//                 close(prev_fd);
//             }
//             if (cmds[i + 1])
//             {
//                 close(fd[0]);
//                 if (dup2(fd[1], STDOUT_FILENO) < 0)
//                 {
//                     close(fd[0]);
//                     close(fd[1]);
//                     exit(1);
//                 }
//                 close(fd[1]);
//             }
//             execvp(cmds[i][0], cmds[i]);
//             exit(1);
//         }
//         else if (pid < 0) // fork failed
//         {
//             if (prev_fd)
//                 close(prev_fd);
//             if (cmds[i + 1])
//             {
//                 close(fd[0]);
//                 close(fd[1]);
//             }
//             return 1;
//         }
//         else // parent process
//         {
//             if (prev_fd)
//                 close(prev_fd);
//             if (cmds[i + 1])
//             {
//                 prev_fd = fd[0];
//                 close(fd[1]);
//             }
//         }
//         i++;
//     }
//     while (wait(NULL) > 0)
//         ;
//     return 0;
// }



int main() 
{
    // Example usage: picoshell with commands
    // char *cmd1[] = {"/bin/echo","hello", "\n","berlin", "|" };
    // char *cmd2[] = {"/usr/bin/wc", NULL};

    char *cmd1[] = {"/bin/ls", "-l", NULL };
    char *cmd2[] = { "/bin/cat", "-e", NULL};
    char **cmds[] = {cmd1, cmd2, NULL};

    picoshell(cmds);
    return 0;
}



