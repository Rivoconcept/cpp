# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/04/24 16:43:58 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAGTRAP = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
 
DIR_FRAGTRAP = ./
SRC_FRAGTRAP = $(addprefix $(DIR_FRAGTRAP),$(FRAGTRAP))

OBJ_FRAGTRAP = $(SRC_FRAGTRAP:.cpp=.o)

NAME = FragTrap

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_FRAGTRAP)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_FRAGTRAP)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re