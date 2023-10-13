# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 11:06:32 by jbarbay           #+#    #+#              #
#    Updated: 2023/10/10 11:06:35 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_printf.c \
		helpers.c \
		library.c \
		conversions.c

CC = cc
# CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME): $(OBJS)
			$(CC) -c $(SRCS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

%.o: %.c
	${CC} -c $< 

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
