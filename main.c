/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:23:53 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/07 20:13:30 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		n;
	int		limit;
	char	*ptr;

	n = 1;
	limit = 2186;
	fd = open("/Users/maldonad1/Documents/GitHub/42-gnl/files/quijote2.txt", \
		O_RDONLY);
	while (n <= limit)
	{
		ptr = get_next_line(fd);
		printf("%s",ptr);
		n++;
	}
	return (0);
}
