/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:55:05 by rlane             #+#    #+#             */
/*   Updated: 2024/04/20 09:24:43 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	if (nb < 0 || nb > 19)
		return (0);
	if (nb == 0)
		return (1);
	i = nb;
	result = 1;
	while (i > 1)
	{
		(result *= i);
		i--;
	}
	return (result);
}
