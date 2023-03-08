/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:37:06 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/08 14:27:43 by dmaldona         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, ft_strlen(s1));
	ft_memcpy(&s[ft_strlen(s1)], s2, ft_strlen(s2));
	s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	s1 = NULL;
	return (s);
}

char	*realloc_buffer(char *ptr, size_t l1, size_t l2)
{
	char		*aux;
	size_t		l;

	if (l1 < l2)
		l = l2 - l1;
	if (l2 <= l1)
		l = l1 - l2;
	aux = (char *)ft_calloc(l, sizeof(char));
	if (!aux)
		return (NULL);
	aux[l] = '\0';
	aux = ft_memcpy(aux, &ptr[l2], l);
	free(ptr);
	ptr = NULL;
	return (aux);
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