/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:41:04 by rlane             #+#    #+#             */
/*   Updated: 2024/05/16 12:18:50 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// if fd is present in struct array get corresponding line_buffer
// or return NULL

char	*get_fd_line_buffer(int fd, t_int_str **fd_line_buffer)
{
	size_t		i;

	i = 0;
	while (fd_line_buffer[i])
	{
		if (fd_line_buffer[i]->fd == fd)
			return (fd_line_buffer[i]->line_buffer);
		i++;
	}
	return (NULL);
}

// free new file descriptor line buffer
// fdlb = file descriptor line buffer

static int	free_new_fdlb(t_int_str *new_fdlb, char *new_lb)
{
	free(new_fdlb);
	free(new_lb);
	return (0);
}
// if fd not present in struct array, add it, and its line buffer

int	put_fd_line_buffer(int fd, char *line_buffer, t_int_str **fd_line_buffer)
{
	size_t		i;
	t_int_str	*new_fdlb;
	char		*new_lb;

	i = 0;
	while (fd_line_buffer[i])
	{
		if (fd_line_buffer[i]->fd == fd)
		{
			free(fd_line_buffer[i]->line_buffer);
			fd_line_buffer[i]->line_buffer = line_buffer;
			return (1);
		}
		i++;
	}
	new_fdlb = (t_int_str *)malloc(sizeof(t_int_str));
	new_lb = (char *)malloc(ft_strlen(line_buffer) + 1);
	if (!free_new_fdlb(new_fdlb, new_lb))
		return (0);
	fd_line_buffer[i]->fd = fd;
	fd_line_buffer[i]->line_buffer = line_buffer;
	fd_line_buffer[i + 1] = NULL;
	return (1);
}
