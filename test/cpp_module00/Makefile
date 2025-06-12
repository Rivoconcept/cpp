EXAM = main.cpp Warlock.cpp

SRC_EXAM = $(addprefix ./, $(EXAM))

OBJ_EXAM = $(SRC_EXAM:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98
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
