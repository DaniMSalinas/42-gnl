/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:23:53 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/03 23:54:45 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*ptr;

	fd = open("/Users/maldonad1/Documents/GitHub/42-gnl/quijote.txt", O_RDONLY);
	ptr = get_next_line(fd);
	return (0);
}
