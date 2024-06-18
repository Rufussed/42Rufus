/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:50:09 by rlane             #+#    #+#             */
/*   Updated: 2024/06/18 17:23:12 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	read_next_map(t_data *data)
{
	static int	map_reads;

	if (map_reads == 0)
		data->map_path = MAP2;
	else if (map_reads == 1)
		data->map_path = MAP1;
	else if (map_reads == 2)
		data->map_path = MAP3;
	else if (map_reads == 3)
		data->map_path = MAP4;
	else if (map_reads == 4)
		data->map_path = MAP5;
	map_reads++;
	if (map_reads == 5)
		map_reads = 0;
	return (read_map(data));
}

int	read_map(t_data *data)
{
	char	*read_buf;
	ssize_t	bytes_read;
	int		fd;

	read_buf = malloc(BUFF_SIZE * sizeof(char));
	if (!read_buf)
		return (0);
	ft_printf("Reading map from %s\n", data->map_path);
	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
	{
		free(read_buf);
		return (0);
	}
	bytes_read = read(fd, read_buf, BUFF_SIZE);
	if (bytes_read < 15)
	{
		free(read_buf);
		close(fd);
		return (0);
	}
	read_buf[bytes_read] = '\0';
	data->map = ft_split(read_buf, '\n');
	free(read_buf);
	close(fd);
	return (1);
}
