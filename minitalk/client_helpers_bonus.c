/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_helpers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:45:44 by rlane             #+#    #+#             */
/*   Updated: 2024/06/25 16:55:13 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern int	g_connection_success;

int	connection_check(void)
{
	int	timer;

	timer = 0;
	while (!g_connection_success && timer++ < 100)
		usleep(10000);
	if (!g_connection_success)
	{
		ft_printf("Connection failed. Check Server PID.\n\n");
		return (0);
	}
	return (1);
}
