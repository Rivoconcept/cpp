# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:05:43 by rhanitra          #+#    #+#              #
#    Updated: 2025/05/23 18:27:49 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUREAUCRAT = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
 
DIR_BUREAUCRAT = ./
SRC_BUREAUCRAT = $(addprefix $(DIR_BUREAUCRAT),$(BUREAUCRAT))

OBJ_BUREAUCRAT = $(SRC_BUREAUCRAT:.cpp=.o)

NAME = Form

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_BUREAUCRAT)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_BUREAUCRAT)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re