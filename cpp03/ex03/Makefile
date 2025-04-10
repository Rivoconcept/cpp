# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/04/10 17:56:10 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIAMONDTRAP = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
 
DIR_DIAMONDTRAP = ./
SRC_DIAMONDTRAP = $(addprefix $(DIR_DIAMONDTRAP),$(DIAMONDTRAP))

OBJ_DIAMONDTRAP = $(SRC_DIAMONDTRAP:.cpp=.o)

EXEC = DiamondTrap

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_DIAMONDTRAP)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_DIAMONDTRAP)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re