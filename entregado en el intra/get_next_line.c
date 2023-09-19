/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgonzal2 <cgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:46:25 by cgonzal2          #+#    #+#             */
/*   Updated: 2023/08/28 16:41:43 by cgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*allocate_memory(char *temp, size_t len, char *line)
{
	temp = malloc(len + 2);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char	*line;
	size_t	len;
	char	buf[1];
	char	*temp;

	line = NULL;
	len = 0;
	if (BUFFER_SIZE < 0)
		return (NULL);
	while (read(fd, buf, 1) > 0)
	{
		temp = allocate_memory(temp, len, line);
		if (temp == NULL)
			return (NULL);
		ft_memcpy(temp, line, len);
		free(line);
		line = temp;
		line[len++] = buf[0];
		line[len] = '\0';
		if (buf[0] == '\n')
			return (line);
	}
	if (len > 0)
		return (line);
	return (NULL);
}
/*
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line:%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
