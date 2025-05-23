# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/05/21 17:46:10 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOG = main.cpp ADog.cpp Bulldog.cpp Berger.cpp Human.cpp House.cpp
 
DIR_DOG = ./
SRC_DOG = $(addprefix $(DIR_DOG),$(DOG))

OBJ_DOG = $(SRC_DOG:.cpp=.o)

NAME = Dog_test

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_DOG)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_DOG)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re