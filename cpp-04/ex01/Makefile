# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:57:38 by jbarbay           #+#    #+#              #
#    Updated: 2024/05/22 13:06:05 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.cpp \
		srcs/Animal.cpp \
		srcs/Dog.cpp \
		srcs/Cat.cpp \
		srcs/WrongCat.cpp \
		srcs/WrongAnimal.cpp \
		srcs/Brain.cpp
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = animals
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