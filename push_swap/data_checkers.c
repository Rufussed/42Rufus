/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:19:37 by rlane             #+#    #+#             */
/*   Updated: 2024/06/27 12:51:46 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// takes a str, converts to int and stores it in location pointed to by num
// returns 0 if str is not a valid number
int	check_atoi(const char *str, int *num)
{
	int	sign;
	int	i;
	int	len;

	*num = 0;
	len = ft_strlen(str);
	sign = 1;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		*num = *num * 10 + (str[i] - '0');
		i++;
	}
	*num = (*num * sign);
	return (1);
}
