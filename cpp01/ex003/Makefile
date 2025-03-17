# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/03/16 13:07:02 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HORDE = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
 
DIR_HORDE = ./
SRC_HORDE = $(addprefix $(DIR_HORDE),$(HORDE))

OBJ_HORDE = $(SRC_HORDE:.cpp=.o)

EXEC = Attack

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_HORDE)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_HORDE)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re