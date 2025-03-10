ACCOUNT = Account.cpp tests.cpp
 
DIR_ACCOUNT = ./
SRC_ACCOUNT= $(addprefix $(DIR_ACCOUNT),$(ACCOUNT))

OBJ_ACCOUNT = $(SRC_ACCOUNT:.cpp=.o)

EXEC = Account

CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_ACCOUNT)
	$(CC)  $(CFLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_ACCOUNT)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re