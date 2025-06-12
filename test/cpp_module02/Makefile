EXAM = main.cpp Warlock.cpp ASpell.cpp ATarget.cpp Fwoosh.cpp Dummy.cpp Fireball.cpp Polymorph.cpp BrickWall.cpp TargetGenerator.cpp SpellBook.cpp

SRC_EXAM = $(addprefix ./, $(EXAM))

OBJ_EXAM = $(SRC_EXAM:.cpp=.o)

FLAGS = -g -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

NAME = Exam

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ_EXAM)
	$(CC) $(FLAGS) -o $@ $^

clean :
	$(RM) $(OBJ_EXAM)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
