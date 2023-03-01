/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:37:06 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/01 23:54:31 by dmaldona         ###   ########.fr       */
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

char	*read_file(int fd, int buffer_size)
{
	int		n;
	char	*ptr;
	char	*lectura;
	char	*aux;

	n = 1;
	ptr = (char *)malloc(sizeof(char) * buffer_size * n);
	lectura = (char *)malloc(sizeof(char) * buffer_size * n);
	while (read(fd, ptr, BUFFER_SIZE))
	{
		aux = (char *)malloc(sizeof(char) * buffer_size * n);
		ft_memcpy(aux, lectura, ft_strlen(lectura));
		free(lectura);
		lectura = (char *)malloc(sizeof(char) * (buffer_size + 1) * n++);
		ft_memcpy(lectura, aux, ft_strlen(aux));
		ft_memcpy(&lectura[ft_strlen(aux)], ptr, ft_strlen(ptr));
		free(aux);
		free(ptr);
		ptr = (char *)malloc(sizeof(char) * buffer_size * n);
	}
	return (lectura);
}
