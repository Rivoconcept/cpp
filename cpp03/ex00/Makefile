# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/04/24 16:44:12 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLAPTRAP = main.cpp ClapTrap.cpp
 
DIR_CLAPTRAP = ./
SRC_CLAPTRAP = $(addprefix $(DIR_CLAPTRAP),$(CLAPTRAP))

OBJ_CLAPTRAP = $(SRC_CLAPTRAP:.cpp=.o)

NAME = ClapTrap

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_CLAPTRAP)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_CLAPTRAP)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re