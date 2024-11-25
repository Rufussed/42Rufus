/*
Assignment name:    sandbox
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

We will test your code with very bad functions. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

// int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
// {
// 	if (!f || timeout == 0 || timeout > 100000000)
// 		return -1;

// 	pid_t pid = fork();
// 	// if (pid < 0)
// 	// {
// 	// 	if (verbose)
// 	// 		printf("Fork failed: %d\n", errno);
// 	// 	return -1;
// 	// }

// 	if (pid == 0)
// 	{
// 		alarm(timeout); // Set timeout in child process
// 		f();			// Execute the function
// 		exit(EXIT_SUCCESS);		// Exit successfully if function returns
// 	}

// 	int status;
// 	// if (waitpid(pid, &status, 0) == -1)
// 	// {
// 	// 	if (verbose)
// 	// 		printf("Waitpid failed: %d\n", errno);
// 	// 	return -1;
// 	// }
// 	waitpid(pid, &status, 0);

// 	// Check if process was terminated by a signal
// 	if (WIFSIGNALED(status))
// 	{
// 		int sig = WTERMSIG(status);
// 		if (sig == SIGALRM)
// 		{
// 			if (verbose)
// 				printf("Bad function: timed out after %u seconds\n", timeout);
// 		}
// 		else
// 		{
// 			if (verbose)
// 				printf("Bad function: %s\n", strsignal(sig));
// 		}
// 		return 0;
// 	}

// 	//  if not signal terminated Check exit status
// 	if (WIFEXITED(status))
// 	{
// 		int exit_code = WEXITSTATUS(status);
// 		if (exit_code == 0)
// 		{
// 			if (verbose)
// 				printf("Nice function!\n");
// 			return 1;
// 		}
// 		else
// 		{
// 			if (verbose)
// 				printf("Bad function: exited with code %d\n", exit_code);
// 			return 0;
// 		}
// 	}

// 	if (verbose)
// 		printf("Unknown termination\n");
// 	return -1;
// }

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	pid_t pid;
	int status;
	int sig;
	int exit_code;
		
	if (!f || timeout == 0 || timeout > 100)
		return -1;
	pid = fork(); //optionally added failure check (== -1) ret -1
	if (pid == 0) //child
	{
		alarm(timeout);
		f();
		exit(EXIT_SUCCESS);
	} //parent
	waitpid(pid, &status, 0); //optionally added failure check (== -1)  ret -1
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGALRM)
			printf("Bad function: timed out after %d seconds\n", timeout);
		else
			printf("Bad function: %s\n", strsignal(sig));
		return(0);
	}
	if (WIFEXITED(status))
	{
		exit_code = WIFEXITED(status);
		if (exit_code == 0)
		{
			printf("Nice Function!\n");
			return 1;
		}
		printf("Bad function: exited with code %d\n", exit_code);
		return 0;
	}
	return -1;	
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Test functions
void nice_function(void) {
    printf("Running nice function\n");
}

void segfault_function(void) {
    printf("Running segfault function\n");
    int *p = NULL;
    *p = 42;
}

void timeout_function(void) {
    printf("Running timeout function\n");
    while (1)
        sleep(1);
}

void abort_function(void) {
    printf("Running abort function\n");
    abort();
}

void exit_bad_function(void) {
    printf("Running exit bad function\n");
    exit(42);
}

void floating_point_error(void) {
    printf("Running floating point error function\n");
    int x = 0;
    printf("%d\n", 42 / x);
}

int main(void) {
	int ret;
    printf("\n=== Testing nice function ===\n");
    ret = sandbox(nice_function, 1, true);
	printf("ret = %d\n", ret);

    printf("\n=== Testing segfault ===\n");
    ret =  sandbox(segfault_function, 1, true);
	printf("ret = %d\n", ret);

    printf("\n=== Testing timeout ===\n");
    ret =  sandbox(timeout_function, 2, true);
	printf("ret = %d\n", ret);

    printf("\n=== Testing abort ===\n");
   ret =  sandbox(abort_function, 1, true);
	printf("ret = %d\n", ret);

    printf("\n=== Testing bad exit code ===\n");
    ret = sandbox(exit_bad_function, 1, true);
	printf("ret = %d\n", ret);

    printf("\n=== Testing floating point error ===\n");
    ret = sandbox(floating_point_error, 1, true);
	printf("ret = %d\n", ret);

    printf("\n=== Testing NULL function pointer ===\n");
   ret =  sandbox(NULL, 1, true);
	printf("ret = %d\n", ret);

    printf("\n=== Testing invalid timeout ===\n");
   ret =  sandbox(nice_function, 0, true);
	printf("ret = %d\n", ret);

    return 0;
}