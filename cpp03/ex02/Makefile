# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/04/09 14:06:44 by rivoinfo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAGTRAP = main.cpp ClapTrap.cpp ScavTrap.cpp
 
DIR_FRAGTRAP = ./
SRC_FRAGTRAP = $(addprefix $(DIR_FRAGTRAP),$(FRAGTRAP))

OBJ_FRAGTRAP = $(SRC_FRAGTRAP:.cpp=.o)

EXEC = FragTrap

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_FRAGTRAP)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_FRAGTRAP)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re