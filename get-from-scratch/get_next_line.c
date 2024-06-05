/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:52:54 by rlane             #+#    #+#             */
/*   Updated: 2024/06/05 15:07:17 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_str_return_null(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*get_line(char *line_buf)
{
	size_t	i;
	char	*line;

	if (!line_buf)
		return (NULL);
	i = 0;
	while (line_buf[i] != '\n' && line_buf[i] != '\0')
		i++;
	if (line_buf[i] == '\n')
		i++;
	line = ft_substr(line_buf, 0, i);
	free_str_return_null(line_buf);
	return (line);
}

char	*get_next(char *line_buf)
{
	size_t	i;
	char	*next_line;

	if (!line_buf)
		return (NULL);
	i = 0;
	while (line_buf[i] != '\n' && line_buf[i] != '\0')
		i++;
	next_line = ft_strdup(&line_buf[i + 1]);
	return (next_line);
}

char	*fill_buf(char *next_line, int fd)
{
	char	*read_buf;
	char	*temp;
	int		bytes_read;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (free_str_return_null(next_line));
	bytes_read = read(fd, read_buf, BUFFER_SIZE);
	if (bytes_read == -1 || bytes_read == 0)
		return (free_str_return_null(next_line));
	while (bytes_read > 0)
	{
		read_buf[bytes_read] = '\0';
		if (!next_line)
			next_line = ft_strdup("");
		temp = next_line;
		next_line = ft_strjoin(temp, read_buf);
		free_str_return_null(temp);
		if (ft_strchr(next_line, '\n'))
			break ;
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
	}
	free_str_return_null(read_buf);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line[MAX_FD];
	char		*line_buf;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (next_line[fd] && (ft_strchr(next_line[fd], '\n')))
		line_buf = next_line[fd];
	else
		line_buf = fill_buf(next_line[fd], fd);
	if (!line_buf)
		free_str_return_null(next_line[fd]);
	next_line[fd] = get_next(line_buf);
	return (get_line(line_buf));
}

