# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/07/05 16:57:51 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BTC = main.cpp
 
DIR_BTC = ./
SRC_BTC = $(addprefix $(DIR_BTC),$(BTC))

OBJ_BTC = $(SRC_BTC:.cpp=.o)

NAME = btc

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_BTC)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_BTC)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re