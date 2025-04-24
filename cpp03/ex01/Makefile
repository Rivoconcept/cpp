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

SCAVTRAP = main.cpp ClapTrap.cpp ScavTrap.cpp
 
DIR_SCAVTRAP = ./
SRC_SCAVTRAP = $(addprefix $(DIR_SCAVTRAP),$(SCAVTRAP))

OBJ_SCAVTRAP = $(SRC_SCAVTRAP:.cpp=.o)

NAME = ScavTrap

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_SCAVTRAP)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_SCAVTRAP)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re