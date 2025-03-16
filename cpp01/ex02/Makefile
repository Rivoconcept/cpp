REF = main.cpp
 
DIR_REF = ./
SRC_REF = $(addprefix $(DIR_REF),$(REF))

OBJ_REF = $(SRC_REF:.cpp=.o)

EXEC = ref

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_REF)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_REF)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re