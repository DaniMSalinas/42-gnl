# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 19:26:50 by dmaldona          #+#    #+#              #
#    Updated: 2023/03/18 12:53:37 by dmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror 
SRCS	= get_next_line.c \
			get_next_line_utils.c \

BONUS-SRCS = get_next_line_bonus.c \
				get_next_line_utils_bonus.c

OBJS	= $(SRCS:%.c=%.o)
BOBJS	= $(BONUS-SRCS:%.c=%.o)
NAME	= get_next_line.a
NAME_B	= .bonus


$(NAME):	$(OBJS)
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

$(NAME_B):	$(OBJS) $(BOBJS)
				ar rc $(NAME) $(OBJS) $(BOBJS)
				ranlib $(NAME)
				@touch .bonus

bonus:		$(NAME_B)
all:		$(NAME) 
clean:		
				rm -f $(OBJS) $(BOBJS)
fclean:		clean
				rm -f $(NAME) $(NAME_B)
re:			fclean all
.PHONY:		all clean fclean re
