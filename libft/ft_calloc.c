/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:48:09 by rlane             #+#    #+#             */
/*   Updated: 2024/04/24 12:16:37 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  nmemb is number of members, size is number of bytes per member

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buffer;
	size_t			i;

	buffer = malloc(nmemb * size * sizeof(unsigned char));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		buffer[i] = '\0';
		i++;
	}
	return ((void *)buffer);
}
