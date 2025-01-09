/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:07:02 by rlane             #+#    #+#             */
/*   Updated: 2025/01/09 18:33:07 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3d.h"
#include <stdbool.h>

bool is_map_line(const char *line)
{
	int i = 0;

	while (line[i] == ' ') // Skip leading spaces
		i++;
	if (line[i] != '1') // Map lines must start with '1'
		return (false);
	while (line[i] && line[i] != '\n') // Validate characters
	{
		if (!(line[i] == ' ' || line[i] == '1' || line[i] == '0' ||
			  line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'))
			return (false);
		i++;
	}
	return (true);
}


char check_line_type(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		return ('N');
	if (line[i] == 'S' && line[i + 1] == 'O')
		return ('S');
	if (line[i] == 'W' && line[i + 1] == 'E')
		return ('W');
	if (line[i] == 'E' && line[i + 1] == 'A')
		return ('E');
	if (line[i] == 'F')
		return ('F');
	if (line[i] == 'C')
		return ('C');
	if (line[i] == '1')
		return ('M'); // M for map
	if (line[i] == '\n')
		return ('I'); // I for ignore
	perror("Error\nInvalid line type");
	exit(1);
}

void handle_line_type(t_data *data, char *line, char type)
{
	char *start;
	int i;

	start = ft_strchr(line, '/');
	if (start)
		start++;
	if (type == 'N')
	{
		data->north_texture_path = ft_strdup(start);
		printf("North texture: %s\n", data->north_texture_path);
	}
	if (type == 'S')
		data->south_texture_path = ft_strdup(start);
	if (type == 'W')
		data->west_texture_path = ft_strdup(start);
	if (type == 'E')
		data->east_texture_path = ft_strdup(start);
	if (type == 'F')
	{
		i = 0;
		while (line[i] == ' ' || line[i] == 'F')
			i++;
		data->floor_colour = ft_strdup(&line[i]);
	}
	if (type == 'C')
	{
		i = 0;
		while (line[i] == ' ' || line[i] == 'C')
			i++;
		data->ceiling_colour = ft_strdup(&line[i]);
	}
}

void count_map_lines(t_data *data, char *file_path)
{
	int		fd;
	int		length;
	char	*line;

	data->map_height = 0;
	data->map_width = 0;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nFailed to open file");
		exit(1);
	}

	while ((line = get_next_line(fd)))
	{
		char type = check_line_type(line);
		if (type == 'M')
		{
			// Count map lines and track the longest line
			while (line && is_map_line(line))
			{
				length = ft_strlen(line);
				if (length > data->map_width)
					data->map_width = length;
				data->map_height++;
				free(line); // Free the line after processing
				line = get_next_line(fd);
			}
			break; // Exit once map lines are processed
		}
		else if (type != 'I')
			handle_line_type(data, line, type);
		free(line); // Free non-map lines
	}
	close(fd);
}

void read_map(t_data *data)
{
	int		i;
	char	*line;

	// Allocate the map array
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
	{
		perror("Error\nFailed to allocate memory for map");
		exit(1);
	}

	// Open the file again to read the map
	data->fd = open(data->map_path, O_RDONLY);
	if (data->fd < 0)
	{
		perror("Error\nFailed to open file");
		exit(1);
	}

	// Skip lines until the map section
	while ((line = get_next_line(data->fd)))
	{
		printf("Skipping line: '%s'\n", line);
		if (is_map_line(line))
			break; // Map section starts
		free(line);
	}

	// Read map lines
	i = 0;
	while (line && is_map_line(line))
	{
		printf("Reading map line %d: '%s'\n", i, line);
		data->map[i] = malloc(sizeof(char) * (data->map_width + 1));
		if (!data->map[i])
		{
			perror("Error\nFailed to allocate memory for map line");
			exit(1);
		}
		ft_strlcpy(data->map[i], line, data->map_width + 1);
		free(line); // Free the line after copying
		line = get_next_line(data->fd);
		i++;
	}
	data->map[i] = NULL; // Null-terminate the map array
	close(data->fd);
}


void print_map(t_data *data)
{
	int i;

	i = 0;
	while (i < data->map_height && data->map[i])
	{
		printf("%s", data->map[i]);
		i++;
	}
}

int parse_map(t_data *data)
{
	// Count lines and find the longest line for the map only
	count_map_lines(data, data->map_path);

	// Read and allocate the map
	read_map(data);

	// Optional: Print the map for debugging
	print_map(data);

	return (0);
}
