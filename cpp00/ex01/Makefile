# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 19:09:27 by rhanitra          #+#    #+#              #
#    Updated: 2025/03/06 19:16:44 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN = main.cpp
CONTACT = accessorContact.cpp handleContact.cpp
PHONEBOOK = accessorPhoneBook.cpp handlePhoneBook.cpp phoneBookUtils.cpp
 
DIR_MAIN = ./
DIR_CONTACT = ./contacts/
DIR_PHONEBOOK = ./phoneBook/

SRC_MAIN = $(addprefix $(DIR_MAIN),$(MAIN))
SRC_CONTACT = $(addprefix $(DIR_CONTACT),$(CONTACT))
SRC_PHONEBOOK= $(addprefix $(DIR_PHONEBOOK),$(PHONEBOOK))

OBJ_MAIN = $(SRC_MAIN:.cpp=.o)
OBJ_CONTACT = $(SRC_CONTACT:.cpp=.o)
OBJ_PHONEBOOK = $(SRC_PHONEBOOK:.cpp=.o)

EXEC = PhoneBook

CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_MAIN) $(OBJ_CONTACT) $(OBJ_PHONEBOOK)
	$(CC)  $(CFLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_MAIN) $(OBJ_CONTACT) $(OBJ_PHONEBOOK)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re