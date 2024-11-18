//Powerset - writing a program that takes multiple argument. 
// First one is the sum.
// All the others are members. 
// Print all the sets of members where the total of the
// set is the sum. 
// allowed functions: atoi, printf, malloc, calloc, realloc, free

#include <stdio.h>
#include <stdlib.h>

int find_members(int *members, int num_members, int sum)
{
	int *set;
	int i;
	int j;
	int set_sum;
	int set_size;

	i = 0;

	// we iterate through all possible combinations of members
	// 1 << num_members is same as 2^num_members 
	// since each member can be included or not (2 posisbilities)	
	while (i < (1 << num_members)) 
	{
		set = (int *)malloc(sizeof(int) * num_members);
		if (set == NULL)
		{
			printf("Malloc failed\n");
			return 1;
		}
		j = 0;
		set_size = 0;
		set_sum = 0;
		while (j < num_members)
		{
			if (i & (1 << j))
			{
				set[set_size] = members[j];
				set_sum += members[j];
				set_size++;
			}
			j++;
		}
		if (set_sum == sum)
		{
			j = 0;
			while (j < set_size)
			{
				printf("%d", set[j]);
				if (j < set_size - 1)
					printf(" ");
				j++;
			}
			printf("\n");
		}
		free(set);
		i++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	int sum;
	int *members;
	int num_members;

	if (argc == 1)
	{
		printf("Usage: %s <sum> <member1> <member2> ... <memberN>\n", argv[0]);
		return (1);
	}
	sum = atoi(argv[1]);
	num_members = argc - 2;
	
	members = (int *)malloc(sizeof(int) * (argc - 2));
	if (members == NULL)
	{
		printf("Malloc failed\n");
		return (1);
	}
	int i = 0;
	while (i < num_members)
	{
		members[i] = atoi(argv[i + 2]);
		i++;
	}
	if (find_members(members, num_members, sum))
	{
		free(members);
		return (1);
	}
	free(members);
	return (0);

}
