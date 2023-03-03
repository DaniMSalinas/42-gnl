# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 19:26:50 by dmaldona          #+#    #+#              #
#    Updated: 2023/03/02 15:16:13 by dmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -D BUFFER_SIZE=42 -I.
SRCS	= get_next_line.c \
			get_next_line_utils.c \
			main.c

OBJS	= $(SRCS:%.c=%.o)
NAME	= get_next_line.a

$(NAME):	$(OBJS)
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

all:		$(NAME) 
clean:		
				rm -f $(OBJS)
fclean:		clean
				rm -f $(NAME)
re:			fclean all
.PHONY:		all clean fclean re
