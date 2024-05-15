/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:49:23 by rlane             #+#    #+#             */
/*   Updated: 2024/05/15 07:03:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Retrieves the characters after the newline character in a given line.
// line: The line to extract the leftover characters from.
// Return: A pointer to the leftover characters after the newline character, 
// or NULL if there are none.

static char	*get_chars_after_newline(char *line)
{
	char	*leftover_chars;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (NULL);
	leftover_chars = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*leftover_chars == 0)
	{
		free(leftover_chars);
		leftover_chars = NULL;
	}
	line[i + 1] = 0;
	return (leftover_chars);
}

// Fills the line buffer with data read from the fd, until a newline char
// Return: The updated line buffer, or NULL if error occurred

static char	*fill_line_buffer(int fd, char *line_buffer, char *buffer)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line_buffer);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!line_buffer)
			line_buffer = ft_strdup("");
		temp = line_buffer;
		line_buffer = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
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

char	*get_next_line(int fd)
{
	static char	*line_buffer;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(line_buffer);
		free(buffer);
		line_buffer = NULL;
		buffer = (NULL);
		return (NULL);
	}
	line = fill_line_buffer(fd, line_buffer, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	line_buffer = get_chars_after_newline(line);
	return (line);
}
