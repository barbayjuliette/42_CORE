# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:36:21 by jbarbay           #+#    #+#              #
#    Updated: 2024/02/19 12:48:17 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Account.cpp \
		tests.cpp \

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = accounts
OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

$(NAME): ${OBJS}
	$(CC) ${OBJS} -o ${NAME}

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	$(RM) ${OBJS}

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all clean fclean re
