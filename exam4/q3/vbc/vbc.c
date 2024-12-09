#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void quit(char **expr)
{
	printf("unexpected char %c\n", **expr);
	exit (1);
}

int eval_expr(char **expr);

int eval_factor(char **expr)
{
	int result;

	if (**expr == '(')
	{
		(*expr)++;
		result = eval_expr(expr); //brackets contain a new expression		
		if (**expr == ')')
			(*expr)++;
		else if (**expr != ')')
			quit(expr);
		if (**expr == '(' || isdigit(**expr))
			result *= eval_factor(expr);
	}
	else if (isdigit(**expr))
	{
		result = **expr - '0';
		(*expr)++;
		if (**expr == '(')
			result *= eval_factor(expr);
	}

	else
		quit(expr);
	return result;
}

int eval_term(char **expr)
{	
	int result = eval_factor(expr);
	while (**expr == '*')
	{	
		(*expr)++;
		result *= eval_factor(expr);
	}
	return (result);
}

int eval_expr(char **expr)
{
	int result = eval_term(expr);
	while (**expr == '+')
	{	
		(*expr)++;
		result += eval_term(expr);
	}	
	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	
	char *expr = argv[1];
	
	int result = eval_expr(&expr);
	printf("%d\n", result);
	return 0;
}
