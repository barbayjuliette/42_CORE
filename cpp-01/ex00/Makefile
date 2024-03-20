# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 18:55:38 by jbarbay           #+#    #+#              #
#    Updated: 2024/03/20 17:56:19 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = newZombie.cpp \
		Zombie.cpp \
		randomChump.cpp \
		main.cpp
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=g++98
RM = rm -rf
NAME = zombie
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
