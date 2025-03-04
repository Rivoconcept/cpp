# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 19:09:27 by rhanitra          #+#    #+#              #
#    Updated: 2025/03/04 19:10:14 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BRICKWALL = main.cpp accessorContact.cpp accessorPhoneBook.cpp \
			handleContact.cpp handlePhoneBook.cpp
 
DIR_BRICKWALL = ./
SRC_BRICKWALL= $(addprefix $(DIR_BRICKWALL),$(BRICKWALL))

OBJ_BRICKWALL = $(SRC_BRICKWALL:.cpp=.o)

EXEC = phoneBook

CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_BRICKWALL)
	$(CC)  $(CFLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_BRICKWALL)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re