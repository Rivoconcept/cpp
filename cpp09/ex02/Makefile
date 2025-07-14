# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/07/14 15:43:25 by rivoinfo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PMERGEME = main.cpp 
 
DIR_PMERGEME = ./
SRC_PMERGEME = $(addprefix $(DIR_PMERGEME),$(PMERGEME))

OBJ_PMERGEME = $(SRC_PMERGEME:.cpp=.o)

NAME = PmergeMe

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_PMERGEME)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_PMERGEME)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re