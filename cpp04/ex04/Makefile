# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/05/03 14:34:24 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ANIMAL = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
 
DIR_ANIMAL = ./
SRC_ANIMAL = $(addprefix $(DIR_ANIMAL),$(ANIMAL))

OBJ_ANIMAL = $(SRC_ANIMAL:.cpp=.o)

NAME = Materia

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_ANIMAL)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_ANIMAL)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re