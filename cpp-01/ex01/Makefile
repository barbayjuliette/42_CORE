# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 09:20:36 by jbarbay           #+#    #+#              #
#    Updated: 2024/03/20 17:56:19 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ZombieHord.cpp \
		Zombie.cpp \
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
