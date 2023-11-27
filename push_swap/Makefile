# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:01:19 by jbarbay           #+#    #+#              #
#    Updated: 2023/11/27 15:01:23 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME):
		@make all -C libft
		$(CC) $(CFLAGS) $(SRCS) -L./libft -lft -o ${NAME}

%.o: %.c
	${CC} $(CFLAGS) -c $<

clean:
		${RM} ${OBJS}
		@make fclean -C libft

fclean: clean
		${RM} ${NAME} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
