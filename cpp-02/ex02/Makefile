# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 18:49:38 by jbarbay           #+#    #+#              #
#    Updated: 2024/03/20 18:52:03 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Fixed.cpp \
		main.cpp
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = fixed
OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

$(NAME): ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -o ${NAME}

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ${OBJS}

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all clean fclean re
