/*Assignment name:    sandbox
Expected files:     sandbox.c
Allowed functions:  fork, waitpid, exit, alarm, sigaction, kill, printf, strsignal, errno
--------------------------------------------------------------------------------
Write the following function:

#include <stdbool.h>
int sandbox(void(*f)(void), unsigned int timeout, bool verbose);

This function must test if the function f is a nice function or a bad function,
you will return 1 if it is nice, 0 if f is bad or -1 in case of an error in your
function.

A function is considered bad if it is terminated or stopped by a signal
(segfault, abort...), if it exits with any other exit code than 0 or if it times
out.

If verbose is true, you must write the appropriate message among the following:
"Nice function!\n"
"Bad function: exited with code <exit_code>\n"
"Bad function: <signal_description>\n"
"Bad function: timed out after <timeout> seconds\n"

You must not leak processes (even in zombie state, this will be checked using wait).

We will test your code with very bad functions.*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int sandbox(void(*f)(void), unsigned int timeout, bool verbose)
{
	pid_t pid;
	int status;
	int result;
	int exit_code;
	int sig;

	if(!f || timeout == 0 || timeout > 100000000)
		return -1;
	pid = fork();
	if (pid < 0)
	{
		if (verbose)
		{
			printf("Fork failed");
			printf("Error_code: %d\n", errno);
		}
		return -1;
	}
	if (pid == 0)
	{
		alarm(timeout);
		f();
		exit(0);
	}
	result = waitpid(pid, &status, 0);
	if(result < 0)
	{
		if(verbose)
		{
			printf("Waitpid failed");
			printf("Error_code :%d\n", errno);
		}
		return -1;
	}
	if(WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGALRM)
		{
			if (verbose)
				printf("Bad function: timed out after %d seconds\n", timeout); // Timeout message
			return 1; // Indicate a timeout
		}
		if (verbose)
			printf("Bad function: %s\n", strsignal(sig));
		return 1;
	}
	if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		if (exit_code !=0)
		{
			if(verbose)
				printf("Bad function : exited with code %d\n", exit_code);
			return 1;
		}
		else if (exit_code == 0)
		{
			if(verbose)
				printf("Nice function!\n");
			return 0;
		}
	}
	if (verbose)
		printf("Unknown termination\n");
    return -1;
}
void nice_function(void) {
    printf("I am a nice function!\n");
}

void bad_function(void) {
    printf("I will segfault now.\n");
    int *p = NULL;
    *p = 42; // Segfault here
}

void slow_function(void) {
    printf("I am a slow function...\n");
    sleep(10); // Longer than timeout
}

int main() {
    sandbox(nice_function, 2, true);  // Expected: "Nice function!"
    sandbox(bad_function, 2, true);  // Expected: "Bad function: Segmentation fault"
    sandbox(slow_function, 2, true); // Expected: "Bad function: timed out after 2 seconds"
    return 0;
}
