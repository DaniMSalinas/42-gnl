/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:36:17 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/03 23:54:34 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *ptr, int nr)
{
	int	i;

	i = 0;
	while (i <= nr)
	{
		if (ptr[i] == '\n')
		{
			if (nr > i)
				return (i);
			if (nr < i)
				return (nr - i);
		}
		i++;
	}
	if (nr == 0)
		return (0);
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

char	*fill_buffer(int fd, char *ptr, char *line, char *buffer)
{
	int		nr;
	int		nl;
	int		n;
	
	nl = -1;
	n = 1;
	
	while (nl == -1)
	{
		buffer = realloc_buffer(buffer, BUFFER_SIZE * ++n);
		nr = read(fd, ptr, BUFFER_SIZE);
		ft_memcpy(&buffer[ft_strlen(buffer)], ptr, nr);
		nl = find_nl(ptr, nr);
	}
	ft_memcpy(line, buffer, ft_strlen(buffer) - (BUFFER_SIZE - nl - 1));
	ft_memcpy(buffer, &ptr[nl + 1], nr);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*ptr;
	static char	*buffer;
	char		*line;

	ptr = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer || !ptr || !line || fd < 0)
		return (NULL);
	buffer = fill_buffer(fd, ptr, line, buffer);
	printf("%s\n", line);
	return (line);
}
