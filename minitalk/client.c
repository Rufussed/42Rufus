/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:45:44 by rlane             #+#    #+#             */
/*   Updated: 2024/06/25 16:09:12 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	send_message(int server_pid, const char *message)
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
	char	*message;

	if (argc != 3)
	{
		ft_printf("\nUsage: ./client [Server PID] [message]\n\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = ft_strdup(argv[2]);
	ft_printf("\nSending message to server \033[35mPID: %d\033[0m\n\n\n", server_pid);
	send_message(server_pid, message);
	free(message);
	return (0);
}
