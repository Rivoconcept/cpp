EXAM = main.cpp Warlock.cpp Fwoosh.cpp Dummy.cpp ASpell.cpp ATarget.cpp

DIR_EXAM = ./

SRC_EXAM = $(addprefix $(DIR_EXAM), $(EXAM))

OBJ_EXAM = $(SRC_EXAM:.cpp=.o)

NAME = exam

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

CC = c++

%.o:%.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ_EXAM)
	$(CC) $(FLAGS) -o $@ $^

clean :
	$(RM) $(OBJ_EXAM)

fclean : clean
	$(RM) $(NAME)

re: fclean clean

.PHONY: fclean clean name re all