# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/04/22 18:19:07 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ANIMAL = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
 
DIR_ANIMAL = ./
SRC_ANIMAL = $(addprefix $(DIR_ANIMAL),$(ANIMAL))

OBJ_ANIMAL = $(SRC_ANIMAL:.cpp=.o)

EXEC = Animal

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_ANIMAL)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_ANIMAL)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re