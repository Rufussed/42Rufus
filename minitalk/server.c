/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:45:50 by rlane             #+#    #+#             */
/*   Updated: 2024/06/25 16:00:20 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	bits_to_char(int bit)
{
	static int	i;
	static char	c;

	if (bit == 1)
		c |= (0x01 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			ft_printf("\n\033[35mEND MESSAGE\033[0m\n\n");
		i = 0;
		c = 0;
	}
	return (1);
}

void	handler(int signum)
{
	if (signum == BIT0)
		bits_to_char(0);
	else if (signum == BIT1)
		bits_to_char(1);
	else
		ft_printf("Error\n");
}

int	main(void)
{
	int	pid;
	int	i;

	i = 1;
	pid = getpid();
	ft_printf("____________________\n");
	ft_printf("\n \033[35mI  am  MiniTalk!!!\033[0m\n\n   I love gossip\n\n");
	ft_printf("Share some with me!!\n\n    \033[35mPID: %d\n\033[0m", pid);
	ft_printf("____________________\n\n");
	signal(BIT0, handler);
	signal(BIT1, handler);
	while (i == 1)
		pause();
	return (0);
}
