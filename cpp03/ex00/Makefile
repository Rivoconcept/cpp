# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/03/31 18:03:23 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HORDE = main.cpp ClapTrap.cpp
 
DIR_HORDE = ./
SRC_HORDE = $(addprefix $(DIR_HORDE),$(HORDE))

OBJ_HORDE = $(SRC_HORDE:.cpp=.o)

EXEC = ClapTrap

FLAGS = -Wall -Wextra -Werror -std=c++98 -std=c++11
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