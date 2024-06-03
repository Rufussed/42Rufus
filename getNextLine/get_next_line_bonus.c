/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:49:23 by rlane             #+#    #+#             */
/*   Updated: 2024/06/03 12:19:57 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Retrieves the characters after the newline character (\n) in a given line.
// line: The line to extract the extra characters from.
// Also trims (with \0) the line after the newline character.
// Return: A pointer to the extra characters after the \n, 
// or NULL if there are none. 

char	*extract_chars_after_newline(char *line)
{
	char	*extra_chars;
	char	*newline_pos;
	size_t	i;

	newline_pos = ft_strchr(line, '\n');
	if (!line || !line[1] || !newline_pos || !newline_pos[1])
		return (NULL);
	extra_chars = ft_strdup(&newline_pos[1]);
	if (extra_chars && *extra_chars == '\0')
	{
		free(extra_chars);
		extra_chars = NULL;
	}
	i = 1;
	while (newline_pos[i])
	{
		newline_pos[i] = '\0';
		i++;
	}
	return (extra_chars);
}

// Fill the line buffer with data read from fd, until /n found in read_buffer.
// Return: The updated line buffer, or NULL if error occurred
// bytes_read is ssize_t (signed int) as read returns it (-1 for error)

char	*fill_line_buffer(int fd, char *line_buffer, char *read_buffer)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (!line_buffer)
			line_buffer = ft_strdup("");
		read_buffer[bytes_read] = '\0';
		temp = line_buffer;
		line_buffer = ft_strjoin(temp, read_buffer);
		free(temp);
		if (ft_strchr(read_buffer, '\n'))
			break ;
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		free(line_buffer);
		return (NULL);
	}
	return (line_buffer);
}

char	*get_next_line(int fd)
{
	static char	*line_buffer[MAX_FD];
	char		*line;
	char		*read_buffer;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
	{
		free(line_buffer[fd]);
		line_buffer[fd] = NULL;
		return (NULL);
	}
	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	line = fill_line_buffer(fd, line_buffer[fd], read_buffer);
	free(read_buffer);
	if (!line)
		return (NULL);
	line_buffer[fd] = extract_chars_after_newline(line);
	return (line);
}
