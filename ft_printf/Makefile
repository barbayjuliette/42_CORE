# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 11:06:32 by jbarbay           #+#    #+#              #
#    Updated: 2024/02/05 16:48:22 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_printf.c \
		conversions.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) -c $(SRCS)
			ar rcs $(NAME) $(OBJS)

%.o: %.c
	${CC} $(CFLAGS) -c $<

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
