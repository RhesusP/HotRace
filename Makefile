# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 09:33:09 by qpupier           #+#    #+#              #
#    Updated: 2024/02/24 18:06:33 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	hotrace
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c	hash_map.c	utils.c		gnl.c	gnl_utils.c
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
