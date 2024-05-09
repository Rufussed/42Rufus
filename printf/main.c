/*
#include <stdio.h>
#include "ft_printf.h"

// first make then
// cc main.c libftprintf.a -o a.out
// then run with ./a.out

int	main(void)
{
	int	c1 = 'a';
	int	c2 = 'b';
	int	i1 = INT_MIN;
	unsigned int	x1 = INT_MAX;
	char	s1[] = "abc";
	size_t	print_count;

	printf("\n\nft_printf u of '-1':\n");	
	print_count = ft_printf("%u", -1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nprintf u of '-1':\n");	
	print_count = printf("%u", -1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nft_printf d of '-1':\n");	
	print_count = ft_printf("%d", -1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nprintf d of '-1':\n");	
	print_count = printf("%d", -1);
	printf("\ncharacter count: %ld\n\n", print_count);


	print_count = ft_printf("char: %c str: %s char: %c int:%i", c1, s1, c2, i1);
	printf("\ncharacter count: %ld\n\n", print_count);

	print_count = ft_printf("%c", c1);
	printf("\ncharacter count: %ld\n\n", print_count);

	print_count = ft_printf("low-hex: %x upper-hex: %X:", x1, x1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nft_printf int conversion of: %i\n", i1);	
	print_count = ft_printf("%i", i1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nprintf int conversion of: %i\n", i1);	
	print_count = printf("%i", i1);
	printf("\ncharacter count: %ld\n\n", print_count);
	
	printf("\n\nft_printf hex conversion of:%d\n", x1);	
	print_count = ft_printf("%x", x1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nprintf hex conversion of:%d\n", x1);	
	print_count = printf("%x", x1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nft_printf address of s1:\n");	
	print_count = ft_printf("%p", &s1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nprintf address of s1:\n");	
	print_count = printf("%p", &s1);
	printf("\ncharacter count: %ld\n\n", print_count);	

	printf("\n\nft_printf address of '-1':\n");	
	print_count = ft_printf("%p", (void *)-1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nprintf address of '-1':\n");	
	print_count = printf("%p", (void *)-1);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nft_printf address of LONG_MAX:\n");	
	print_count = ft_printf("%p", (void *)LONG_MAX);
	printf("\ncharacter count: %ld\n\n", print_count);

	printf("\n\nprintf address of LONG_MAX:\n");	
	print_count = printf("%p", (void *)LONG_MAX);
	printf("\ncharacter count: %ld\n\n", print_count);
}*/