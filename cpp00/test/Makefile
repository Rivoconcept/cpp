BRICKWALL = test.cpp
 
DIR_BRICKWALL = ./
SRC_BRICKWALL= $(addprefix $(DIR_BRICKWALL),$(BRICKWALL))

OBJ_BRICKWALL = $(SRC_BRICKWALL:.cpp=.o)

EXEC = test

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