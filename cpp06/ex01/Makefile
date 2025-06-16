# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/06/14 10:59:44 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CONVERT = main.cpp Serializer.cpp
 
DIR_CONVERT = ./
SRC_CONVERT = $(addprefix $(DIR_CONVERT),$(CONVERT))

OBJ_CONVERT = $(SRC_CONVERT:.cpp=.o)

NAME = Convert

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_CONVERT)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_CONVERT)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re