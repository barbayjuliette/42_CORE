# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 15:42:14 by jbarbay           #+#    #+#              #
#    Updated: 2024/06/09 16:28:51 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp \
	BitcoinExchange.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = btc
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