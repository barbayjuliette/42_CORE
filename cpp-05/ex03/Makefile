# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 14:37:06 by jbarbay           #+#    #+#              #
#    Updated: 2024/05/28 17:41:40 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/main.cpp \
		srcs/Bureaucrat.cpp \
		srcs/AForm.cpp \
		srcs/ShrubberyCreationForm.cpp \
		srcs/RobotomyRequestForm.cpp \
		srcs/PresidentialPardonForm.cpp \
		srcs/Intern.cpp

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = form
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
