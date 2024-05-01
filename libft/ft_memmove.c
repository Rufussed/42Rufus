/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:26:28 by rlane             #+#    #+#             */
/*   Updated: 2024/05/01 13:02:12 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>	// for printf
#include <string.h>	// for memmove

int	main(void)
{
	char str1[100] = "Hello, world!";
	char str2[100];
	char std_str2[100];

	// Test 1: non-overlapping copy
	ft_memmove(str2, str1, sizeof(str1));
	memmove(std_str2, str1, sizeof(str1));
	printf(" ft_memmove Test 1: %s\n", str2);
	printf("std_memmove Test 1: %s\n", std_str2);

	// Test 2: overlapping copy where src is 2 mem locations before dest
	char overlap1[] = "1234567890";
	char std_overlap1[] = "1234567890";
	ft_memmove(overlap1 + 2, overlap1, 5);
	memmove(std_overlap1 + 2, std_overlap1, 5);
	printf(" ft_memmove Test 2: %s\n", overlap1);
	printf("std_memmove Test 2: %s\n", std_overlap1);

	// Test 3: overlapping copy where src is 2 mem locations after dest
	char overlap2[] = "abcdefghij";
	char std_overlap2[] = "abcdefghij";
	ft_memmove(overlap2, overlap2 + 2, 5);
	memmove(std_overlap2, std_overlap2 + 2, 5);
	printf(" ft_memmove Test 3: %s\n", overlap2);
	printf("std_memmove Test 3: %s\n", std_overlap2);

	return (0);
}
*/
