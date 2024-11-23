/*Write a program that will print the result of a math expression given as an argument.
You must handle the operations plus(+), multiplication (*) and parentheses.
Values will be between 0 and 9. For example this should work:
$> .vbc '1' | cat -e
1$
$> .vbc '2+3' | cat -e
5$
$> .vbc '3*4+5' | cat -e
1$
$> .vbc '3+4*5' | cat -e
23$
$> .vbc '(3+4)*5' | cat -e
35$
$> .vbc '(((((2+2)*2+2)*2+2)2+2)*2+2)*2' | cat -e
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
int evaluate_expression(char **expr);
int evaluate_term(char **expr);
int evaluate_factor(char **expr);
int evaluate_factor(char **expr)
{
	int result;
		
	if(**expr == '(')
	{
		(*expr)++;
		result = evaluate_expression(expr);
		if(**expr == ')')
			(*expr)++;
		else if(**expr != ')')
		{
			printf("Missing ')'\n");
			exit (1);
		}
		if(isdigit(**expr) || **expr == '(')
			result *=evaluate_factor(expr);
	}
	else if(isdigit(**expr))
	{
		result = 0;
		while (isdigit(**expr))
		{
        		result = result * 10 + (**expr - '0'); // Build the number
			(*expr)++;
		}		
		if(**expr == '(')
			result *= evaluate_factor(expr);
	}
	else
	{
		fprintf(stderr, "Error: Unexpected character '%c'\n", **expr);
		exit (1);
	}
	return (result);
}
int evaluate_term(char **expr)
{
	int result;
	
	result = evaluate_factor(expr);
	while(**expr == '*')
	{
		(*expr)++;
		result *= evaluate_factor(expr);
	}
	return (result);
}
int evaluate_expression(char **expr)
{
	int result;
	
	result = evaluate_term(expr);
	while(**expr == '+')
	{
		(*expr)++;
		result +=evaluate_term(expr);
	}
	return (result);
}
int main(int argc, char **argv)
{
	int result;
	char *expr;
	if (argc != 2)
		return (1);
	expr = argv[1];
	result = evaluate_expression(&expr);
	printf("%d\n", result);
	return (0);
}