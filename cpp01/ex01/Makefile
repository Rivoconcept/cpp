HORDE = Zombie.cpp
 
DIR_HORDE = ./
SRC_HORDE = $(addprefix $(DIR_HORDE),$(HORDE))

OBJ_HORDE = $(SRC_HORDE:.cpp=.o)

EXEC = Horde

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_HORDE)
	$(CC)  $(FLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_HORDE)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re