# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:04:56 by rhanitra          #+#    #+#              #
#    Updated: 2025/03/15 14:05:01 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ZOMBIE = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
 
DIR_ZOMBIE = ./
SRC_ZOMBIE= $(addprefix $(DIR_ZOMBIE),$(ZOMBIE))

OBJ_ZOMBIE = $(SRC_ZOMBIE:.cpp=.o)

EXEC = Zombie

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_ZOMBIE)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_ZOMBIE)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re