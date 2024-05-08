/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_elements_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:40:57 by rlane             #+#    #+#             */
/*   Updated: 2024/05/08 19:35:45 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// count the number of printable char elemements in a num of given base
size_t	ft_count_elements_base(long long n, long long base)
{
	size_t	i;


	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= base)
	{
		n = n / base;
		i++;
	}
	return (i);
}