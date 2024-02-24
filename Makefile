# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 09:33:09 by qpupier           #+#    #+#              #
#    Updated: 2024/02/24 20:17:42 by qpupier          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	hotrace
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
# CFLAGS	+=	-fsanitize=address -g
SRCS	=	main.c	\
			utils.c	\
			gnl.c	\
			gnl_utils.c \
			hash_map.c	
OBJS	=	$(SRCS:.c=.o)
INCS	=	hotrace.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(INCS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PNONY: all clean fclean re
