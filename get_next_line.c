/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:36:17 by dmaldona          #+#    #+#             */
/*   Updated: 2023/02/28 17:18:37 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char    *get_next_line(int fd){
	char 	*ptr;
	char	*escritura;
	size_t strlen = 0;

	while (*ptr != '\n')
	{
		read(fd, ptr, 1);
		strlen++;
	}
	escritura = (char *)malloc(sizeof(char) * strlen);
	
	return (escritura);
}*/

char	*read_buffer(int fd, int buffer_size)
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
		printf("%s",ptr);
		strcpy(lectura, aux);
		strcat(lectura, ptr);
	}
	
	/*strcpy(lectura, ptr);
	read(fd, ptr, BUFFER_SIZE);
	strcpy(aux, lectura);
	free(lectura);
	lectura = (char *)malloc(sizeof(char) * buffer_size * n++);
	strcpy(lectura, aux);
	strcat(lectura, ptr);*/                                                                                                    
	return (lectura);
}

char	*get_next_line(int fd)
{
	char	**escritura;
	char	*ptr;

	ptr = read_buffer(fd, BUFFER_SIZE);
	
	return (ptr);
}