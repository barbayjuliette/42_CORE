# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 18:55:38 by jbarbay           #+#    #+#              #
#    Updated: 2024/02/23 10:55:54 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Weapon.cpp \
		main.cpp \
		HumanA.cpp \
		HumanB.cpp \

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = fight
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
