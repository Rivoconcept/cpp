# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/04/09 08:28:57 by rivoinfo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCAVTRAP = main.cpp ClapTrap.cpp ScavTrap.cpp
 
DIR_SCAVTRAP = ./
SRC_SCAVTRAP = $(addprefix $(DIR_SCAVTRAP),$(SCAVTRAP))

OBJ_SCAVTRAP = $(SRC_SCAVTRAP:.cpp=.o)

EXEC = ScavTrap

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_SCAVTRAP)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_SCAVTRAP)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re