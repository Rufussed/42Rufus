#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int check_replace(char *c, char a, char b)
{
	if (c[0] == a)
	{
		c[0] = b;
		return 1;
	}
	return 0;
}

// count brackets return difference
int count_brackets(char *str)
{
	int i = -1;
	int open_b = 0;
	int close_b = 0;

	while(str[++i])
	{
		if (str[i] == '(')
			open_b++;
		if (str[i] == ')')
			close_b++;
	}
	return (open_b - close_b);
}

// check for close brackets at start
int check_start(char *str)
{
	int i = 0;
	while(str[i] != '(')
	{
		if (str[i] == ')')
			return 0;
		i++;
	}
	return 1;
}

// check for open brackets at end
int check_end(char *str)
{
	int i = ft_strlen(str) - 1;
	while(str[i] != ')')
	{
		if (str[i] == '(')
			return 0;
		i--;
	}
	return 1;
}

// check balanced solution for closing unopened bracket
int check_balance(char *str)
{
	int dif = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] == '(')
			dif++;
		if (str[i] == ')')
			dif--;
		if (dif < 0)
			return 0;
		i++;
	}
	return 1;
}

// char *ft_strcpy(char *str)
// {
// 	char sc[1024];
// 	int i = 0;

// 	while(str[i])
// 	{
// 		sc[i] = str[i];
// 		i++;
// 	}
// 	sc[i] = '\0';
// 	return sc;
// }

void remove_brackets(char *str, int start, int end, int dif)
{
	int i = 0;
	
	int dif_check;
	char sc[1024];
	char b = '(';

	if (dif < 0)
	{
		b = ')';
		dif = -dif;
	}
	int dif_reset = dif;

	while (1)
	{
		i=0;
		while(str[i])
		{
			sc[i] = str[i];
			i++;
		}
		sc[i] = '\0';
		i=0;
		dif = dif_reset;
		dif_check = dif;
		while(dif)
		{			
			if (check_replace(&sc[start + i], b, '_'))
			{
				if (check_balance(sc))
					dif--;
				else
				{
					check_replace(&sc[start + i], '_', b); //swap change back
					start += i;
					i = 0;
				}
			}		
			i++;
		}
		dif = count_brackets(sc);
		//	printf("check start: %d, check end:%d\n", check_start(sc), check_end(sc)); //debug
		if (!dif && check_start(sc) && check_end(sc) && (dif_check != dif) && check_balance(sc))
		{	
		//		printf("\nafter checks:\n\n");
			write(1, sc, ft_strlen(sc));
			puts("");
		}
		//		printf("\n\noriginal:\n\n");
		//		write(1, str, ft_strlen(str));
		start++;
		if (start == end)
			return;
	}
}

int	main(int argc, char **argv)
{
	char *str;
	int dif;
	int i = 0;
	int start = 0;
	int end = 0;
	
	if (argc != 2)
	{
		puts("Error: expected 1 str string with only brackets ()");
		return 1;
	}
	str = argv[1];

	// remove close b at start of string
	i = 0;
	while(str[i] != '(')
	{
		check_replace(&str[i], ')', '_');
		i++;
	}
	start = i;

	// remove open b at end of string
	i = ft_strlen(str) - 1;
	while(str[i] != ')')
	{
		check_replace(&str[i], '(', '_');
		i--;
	}
	end = i;	

	dif = count_brackets(str);
	printf("start: %d end: %d dif: %d\n\n",start, end, dif);
	if (dif == 0)
	{
		write(1, str, ft_strlen(str)); //debug
		return 0;
	}
	remove_brackets(str, start, end, dif);
}