/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:45:44 by rlane             #+#    #+#             */
/*   Updated: 2024/06/25 16:57:27 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_connection_success = 0;

void	char_to_bits(int server_pid, char c, int message_len)
{
	int			bit;
	static int	chars_sent;
	int			percent_sent;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(server_pid, BIT1);
		else
			kill(server_pid, BIT0);
		usleep(SLEEPTIME);
		if (bit == 7)
		{
			chars_sent++;
			percent_sent = ((float)chars_sent / (float)message_len * 100);
			ft_printf("\033[A\033[K\033[32mSent %d%%\033[0m\n", percent_sent);
		}
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
		usleep(SLEEPTIME);
		bit++;
	}
}

void	handler(int signum)
{
	if (signum == BIT1)
	{
		g_connection_success = 1;
		ft_printf("Connection established.\n\n\n");
	}
	else
		ft_printf("Error\n");
}

void	send_message(int server_pid, char *message)
{
	int	message_len;
	int	i;

	message_len = ft_strlen(message) + 1;
	i = 0;
	while (i < message_len)
	{
		char_to_bits(server_pid, message[i], message_len);
		i++;
	}
	ft_printf("\nMessage Sent.\n\n");
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		client_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("\nUsage: ./client [Server PID] [message]\n\n");
		return (1);
	}
	signal(BIT1, handler);
	server_pid = ft_atoi(argv[1]);
	client_pid = getpid();
	ft_printf("\n\033[35mMY PID: %d\033[0m\n\n", client_pid);
	send_client_pid(server_pid, client_pid);
	if (!connection_check())
		return (1);
	message = ft_strdup(argv[2]);
	send_message(server_pid, message);
	free(message);
	return (0);
}
