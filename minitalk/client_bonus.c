/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:45:44 by rlane             #+#    #+#             */
/*   Updated: 2024/06/21 12:01:13 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	ping(int server_pid)
// {
// 	kill(server_pid, BIT0);
// 	kill(server_pid, BIT1);
// }

int	connection_success = 0;

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

void	send_client_pid(int server_pid, int client_pid)
{
	int		bit;

	bit = 0;
	while (bit < 32)
	{
		if ((client_pid & (0x01 << bit)) != 0)
			kill(server_pid, BIT1);
		else
			kill(server_pid, BIT0);
		usleep(100);
		bit++;
	}
}

void	handler(int signum)
{
	if (signum == BIT1)
	{
		connection_success = 1;
		ft_printf("Connection established\n");
	}
	else
		ft_printf("Error\n");
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		client_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID] [message]\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	client_pid = getpid();
	ft_printf("MY PID: %d\n", client_pid);
	send_client_pid(server_pid, client_pid);
	signal(BIT1, handler);
	while (!connection_success)		
		pause();
	message = argv[2];
	while (*message)
	{
		char_to_bits(server_pid, *message);
		message++;
	}
	char_to_bits(server_pid, '\0');
	return (0);
}


