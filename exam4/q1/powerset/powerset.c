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
	int	*set;
	int set_size = 0;
	int set_sum;
	int found_set = 0;
	int i = 1 << num_members;   // this bitshift gives 2^num_members, eg 4 members gives 16 combos,  1111 in binary
								// each bit represents a member, 1 means member is in the set, 
								// 0 means member is not in the set, and we iterate through all the possible combos
	int j;

	while (i > 0)
	{
		set = malloc(num_members * sizeof(int));
		if (!set)
			return 1;
		set_sum = 0;
		set_size = 0;
		j = 0;
		while(j < num_members)
		{
			if (i & (1 << j))  // j steps through each possition in the binary number, and if the bit is set, 
								// we add the member to the set
			{
				set[set_size] = members[j];
				set_sum += members[j];
				set_size++;
			}
			j++;
		}
		if (set_sum == sum) // if the sum of the set is the target sum, we print the set
		{
			found_set = 1;
			j = 0;
			while(j < set_size)
			{
				printf("%d", set[j]);
				if (j < set_size -1)
					printf(" ");
				if (j == set_size - 1)
					printf("\n");
				j++;
			}
		}
		i--;
		free(set);
	}
	if (!found_set)
			printf("\n");
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
