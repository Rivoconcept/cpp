# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/07/10 16:53:33 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RPN = main.cpp RPN.cpp
 
DIR_RPN = ./
SRC_RPN = $(addprefix $(DIR_RPN),$(RPN))

OBJ_RPN = $(SRC_RPN:.cpp=.o)

NAME = RPN

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_RPN)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_RPN)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re