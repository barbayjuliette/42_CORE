# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 12:00:57 by jbarbay           #+#    #+#              #
#    Updated: 2024/06/03 16:51:46 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.cpp \
		ScalarConverter.cpp \
		check_type.cpp \
		print.cpp \

CC = c++
CFLAGS = -Wall -Wextra -Werror -Wno-conversion -std=c++98
RM = rm -rf
NAME = convert
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