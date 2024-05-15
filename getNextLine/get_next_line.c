/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:49:23 by rlane             #+#    #+#             */
/*   Updated: 2024/05/15 14:22:48 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Retrieves the characters after the newline character (\n) in a given line.
// line: The line to extract the extra characters from.
// Also trims (with \0) the line after the newline character.
// Return: A pointer to the extra characters after the \n, 
// or NULL if there are none. 

static char	*extract_chars_after_newline(char *line)
{
	char	*extra_chars;
	char	*newline_pos;

	newline_pos = ft_strchr(line, '\n');
	if (!line || !line[1] || !newline_pos || !newline_pos[1])
		return (NULL);
	extra_chars = ft_strdup(&newline_pos[1]);
	if (extra_chars && *extra_chars == '\0')
	{
		free(extra_chars);
		extra_chars = NULL;
	}
	newline_pos[1] = '\0';
	return (extra_chars);
}

// Fill the line buffer with data read from fd, until /n found in read_buffer.
// Return: The updated line buffer, or NULL if error occurred
// bytes_read is ssize_t (signed int) as read returns it (-1 for error)

static char	*fill_line_buffer(int fd, char *line_buffer, char *read_buffer)
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

// Reads the next line from a file descriptor.
// fd: The file descriptor to read from.
// line_buffer: The buffer to store the read data.
// buffer: The temporary buffer to read data into.
// Return: The next line read from the file descriptor, or NULL if an error
// occurred or the end of file was reached.

// line_buffer is static and so is initiallised to NULL on 1st call
// and can contain leftover chars from previous calls

// read() returns 0 when EOF is reached, -1 on error, and the number 
// of bytes read otherwise

char	*get_next_line(int fd)
{
	static char	*line_buffer;
	char		*line;
	char		*read_buffer;

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(line_buffer);
		free(read_buffer);
		line_buffer = NULL;
		read_buffer = (NULL);
		return (NULL);
	}
	line = fill_line_buffer(fd, line_buffer, read_buffer);
	free(read_buffer);
	read_buffer = NULL;
	if (!line)
		return (NULL);
	line_buffer = extract_chars_after_newline(line);
	return (line);
}
