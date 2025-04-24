# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/04/24 16:45:07 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIAMONDTRAP = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
 
DIR_DIAMONDTRAP = ./
SRC_DIAMONDTRAP = $(addprefix $(DIR_DIAMONDTRAP),$(DIAMONDTRAP))

OBJ_DIAMONDTRAP = $(SRC_DIAMONDTRAP:.cpp=.o)

NAME = DiamondTrap

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_DIAMONDTRAP)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_DIAMONDTRAP)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re