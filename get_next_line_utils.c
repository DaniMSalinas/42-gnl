/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:37:06 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/03 22:16:27 by dmaldona         ###   ########.fr       */
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

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count && (count > SIZE_MAX / size))
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}