/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:56:20 by rlane             #+#    #+#             */
/*   Updated: 2024/04/24 12:14:06 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	s_len;

	c = (unsigned char)c;
	s_len = ft_strlen((char *)s);
	i = s_len;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
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
		printf("Returns: string from found point in reverse\n");
		return (-1);
	}

	char_to_find = argv[2][0];
	printf("return: %s\n", ft_strrchr((const char *)argv[1], char_to_find));
	return (0);
}*/