# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/04/08 17:24:43 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLAPTRAP = main.cpp ClapTrap.cpp
 
DIR_CLAPTRAP = ./
SRC_CLAPTRAP = $(addprefix $(DIR_CLAPTRAP),$(CLAPTRAP))

OBJ_CLAPTRAP = $(SRC_CLAPTRAP:.cpp=.o)

EXEC = ClapTrap

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_CLAPTRAP)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_CLAPTRAP)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re