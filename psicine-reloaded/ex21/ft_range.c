/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:51:12 by rlane             #+#    #+#             */
/*   Updated: 2024/04/20 06:06:55 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long	range;
	int		*dest;
	int		i;

	range = max - min;
	if (range <= 0 || range > 2147483647)
		return (0);
	dest = malloc(range * sizeof(int));
	if (!dest)
		return (0);
	i = 0;
	while (i < range)
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	int max = 10;
	int min = -10;
	int *testrange;
	int i = 0;

	testrange = ft_range(min, max);
	while (i < max - min)
	{
		printf("%d\n", testrange[i]);
		i++;
	}
}*/
