/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:37:06 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/01 23:23:36 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_aux;
	char	*src_aux;

	if (!dst && !src)
		return (NULL);
	dst_aux = (char *)dst;
	src_aux = (char *)src;
	while (n)
	{
		*dst_aux = *src_aux;
		dst_aux++;
		src_aux++;
		n--;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, ft_strlen(s1));
	ft_memcpy(&s[ft_strlen(s1)], s2, ft_strlen(s2));
	return (s);
}

char	*read_file(int fd, int buffer_size)
{
	int		n;
	char	*ptr;
	char	*lectura;
	char	*aux;

	n = 1;
	ptr = (char *)malloc(sizeof(char) * buffer_size * n);
	lectura = (char *)malloc(sizeof(char) * buffer_size * n);
	aux = (char *)malloc(sizeof(char) * buffer_size * n);
	read(fd, ptr, BUFFER_SIZE);
	strcpy(lectura, ptr);
	while (read(fd, ptr, BUFFER_SIZE))
	{
		strcpy(aux, lectura);
		free(lectura);
		lectura = (char *)malloc(sizeof(char) * buffer_size * n++);
		lectura = ft_strjoin(aux, ptr);
		free(aux);
		aux = (char *)malloc(sizeof(char) * buffer_size * n);
	}
	return (lectura);
}
