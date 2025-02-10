CUB3D = main.c
 
DIR_CUB3D = ./src/
SRC_CUB3D= $(addprefix $(DIR_CUB3D),$(CUB3D))

OBJ_CUB3D = $(SRC_CUB3D:.c=.o)

EXEC = cub3D

CFLAGS = -Wall -Wextra -Werror 
CC = gcc
RM = rm -rf
AR = ar rcs

all : $(EXEC)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_CUB3D)
	$(CC)  $(CFLAGS) -o $@ $^ 

clean :
	$(RM) $(OBJ_CUB3D)
	
fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY: all clean fclean re