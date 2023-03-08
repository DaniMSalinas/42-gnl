/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:23:53 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/08 01:09:20 by dmaldona         ###   ########.fr       */
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
	limit = 1;
	fd = open("/Users/maldonad1/Documents/GitHub/42-gnl/files/43_with_nl", \
		O_RDONLY);
	while (n <= limit)
	{
		ptr = get_next_line(fd);
		printf("%i %s", n, ptr);
		n++;
	}
	return (0);
}
