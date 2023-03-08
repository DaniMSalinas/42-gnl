/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:36:17 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/08 14:12:14 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	find_nl(char *ptr)
{
	ssize_t	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_line(char *buffer, ssize_t size)
{
	char	*line;

	if (ft_strlen(buffer) == 0)
		return (NULL);
	line = (char *)malloc(size + 1);
	if (!line)
		return (NULL);
	line[size + 1] = '\0';
	line = ft_memcpy(line, buffer, size + 1);
	line[ft_strlen(line)] = '\0';
	return (line);
}

char	*fill_buffer(int fd, char *buffer)
{
	ssize_t		nr;
	ssize_t		nl;
	char		*ptr;

	ptr = (char *)malloc(BUFFER_SIZE);
	if (!ptr)
		return (NULL);
	nr = 1;
	nl = 1;
	while (nr != 0 && nl == nr)
	{
		nr = read(fd, ptr, BUFFER_SIZE);
		if (nr == -1)
		{
			free(ptr);
			free(buffer);
			return (NULL);
		}
		ptr[nr] = '\0';
		nl = find_nl(ptr);
		buffer = ft_strjoin(buffer, ptr);
	}
	free (ptr);
	ptr = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	buffer = fill_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer, find_nl(buffer));
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line[ft_strlen(line)] = '\0';
	buffer = realloc_buffer(buffer, ft_strlen(buffer), ft_strlen(line));
	return (line);
}
