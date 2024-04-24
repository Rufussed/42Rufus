/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:24:47 by rlane             #+#    #+#             */
/*   Updated: 2024/04/24 12:16:04 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	size_t	i;
	char	*dest;

	s_len = ft_strlen((char *)s);
	dest = malloc(s_len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Argument: string_to_duplicate\n");
		printf("Return: duplicated string address\n");
		return (-1);
	}
	printf("ft return: %s\n", ft_strdup(argv[1]));
	printf("sy return: %s\n", strdup(argv[1]));
	return (0);
}*/
