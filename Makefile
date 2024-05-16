# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaigle <llaigle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 15:51:04 by llaigle           #+#    #+#              #
#    Updated: 2024/05/16 17:02:39 by llaigle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirc
CPP = main.cpp\
	Clients.cpp Server.cpp

OOO = $(CPP:.cpp=.o)

FLAG = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OOO)
	c++ $(OOO) $(FLAG) -o $(NAME)
$(OOO): $(CPP)
	c++ -c $(CPP) $(FLAG)
clean:
	rm -f $(OOO)
fclean: clean
	rm -f $(NAME)
re: fclean all