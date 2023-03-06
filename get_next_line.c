/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:36:17 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/06 21:00:53 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *ptr, int nr)
{
	int	i;

	i = 0;
	while (i < nr)
	{
		if (ptr[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*realloc_buffer(char *ptr, size_t l)
{
	char		*aux;

	aux = (char *)ft_calloc(sizeof(char), l + 1);
	if (!aux)
		return (NULL);
	ft_memcpy(aux, ptr, ft_strlen(ptr));
	free(ptr);
	return (aux);
}

char	*fill_buffer(int fd, char **line, char *buffer)
{
	int	nr;
	int		nl;
	int		n;
	char	*ptr;

	ptr = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	nr = BUFFER_SIZE;
	nl = -1;
	n = 1;
	while (nl == -1 && nr != 0)
	{
		buffer = realloc_buffer(buffer, BUFFER_SIZE * ++n);
		nr = read(fd, ptr, BUFFER_SIZE);
		ft_memcpy(&buffer[ft_strlen(buffer)], ptr, nr);
		nl = find_nl(ptr, nr);
	}
	*line = (char *)ft_calloc(sizeof(char), ft_strlen(buffer) - (nr - nl - 1) + 1);
	if (!*line)
		return (NULL);
	ft_memcpy(*line, buffer, ft_strlen(buffer) - (nr - nl - 1));
	ft_memcpy(buffer, &ptr[nl + 1], nr);
	return (buffer);
}

char	*check_buffer(int nl, char **line, char *buffer)
{
	*line = (char *)ft_calloc(sizeof(char), nl + 1);
	if (!*line)
		return (NULL);
	ft_memcpy(*line, buffer, nl + 1);
	ft_memcpy(buffer, &buffer[nl + 1], ft_strlen(buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			nl;

	if (!buffer)
		buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || !buffer || fd < 0)
		return (NULL);
	nl = find_nl(buffer, ft_strlen(buffer));
	if (nl != -1)
		buffer = check_buffer(nl, &line, buffer);
	else
		buffer = fill_buffer(fd, &line, buffer);
	return (line);
}
