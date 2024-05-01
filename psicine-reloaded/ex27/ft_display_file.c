/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 08:12:35 by rlane             #+#    #+#             */
/*   Updated: 2024/04/20 08:29:27 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

// fd is "file descriptor" an int that is a direct reference to an open file
int	main(int argc, char **argv)
{
	char	buffer[BUF_SIZE];
	int		fd;
	int		bytes_read;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
		bytes_read = read(fd, buffer, BUF_SIZE);
		while (bytes_read > 0)
		{
			write(1, buffer, bytes_read);
			bytes_read = read(fd, buffer, BUF_SIZE);
		}
		close(fd);
	}
	return (0);
}
