#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int eval_factor(char **expr);
int eval_term(char **expr);
int eval_expr(char **expr);

int eval_factor(char **expr)
{
	int result;

	if (**expr == '(')
	{
		(*expr)++;
		result = eval_expr(expr);
		if (**expr == ')')
			(*expr)++;
		else if (**expr != ')')
		{
			printf("expected )\n");
			exit(1);
		}
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
	{
		printf("unexpected char %c\n", **expr);
		exit(1);
	}
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
	return result;
}

int eval_expr(char **expr)
{
	int result = eval_term(expr);
	while (**expr == '+')
	{
		(*expr)++;
		result += eval_term(expr);
		
	}
	return result;
}

int main (int argc, char **argv)
{
	char *expr;
	int result;

	if (argc != 2)
		return 1;
	expr = argv[1];
	result = eval_expr(&expr);
	printf("%d\n", result);
	return 0;
}