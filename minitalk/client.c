/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:45:44 by rlane             #+#    #+#             */
/*   Updated: 2024/06/24 19:28:55 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bits(int server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(server_pid, BIT1);
		else
			kill(server_pid, BIT0);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID] [message]\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		char_to_bits(server_pid, *message);
		message++;
	}
	char_to_bits(server_pid, '\0');
	return (0);
}
