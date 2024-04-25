/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:56:20 by rlane             #+#    #+#             */
/*   Updated: 2024/04/24 17:47:36 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char char_to_find;

	if (argc != 3)
	{
		printf("Arguments: string_to_search char_to_find\n");
		printf("Returns: string from found point\n");
		return (-1);
	}

	char_to_find = argv[2][0];
	printf("return: %s\n", ft_strchr((const char *)argv[1], char_to_find));
	return (0);
}*/
