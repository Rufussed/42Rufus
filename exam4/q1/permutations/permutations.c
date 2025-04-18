#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void alpha_sort(char *str, int start, int end)
{
	int i = start;
	int j;

	while(i <= end - 1)
	{
		j = i + 1;
		while (j <= end)
		{
			if (str[i] > str[j])
				swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void permute(char *str, int start, int end)
{
	int i = 0;

	alpha_sort(str, start, end);
	if (start == end) // base case
	{
		puts(str);
		return;
	}

	i = start;
	while(i <= end)
	{
		swap(&str[start], &str[i]); 	//swap
		permute(str, start + 1, end); 	//recurse
		swap(&str[start], &str[i]);		//backtrack reverse the swap
		i++;
	}
}


int	main(void)
{
	char	input[4] = {"acbd"};

	if (argc != 2)
		return (1);
	input = argv[1];
	//alpha_sort(input, 0, strlen(input) - 1);
	//puts(input);
	puts("\n");
	permute(input, 0, strlen(input) - 1);
	return (0);
}

