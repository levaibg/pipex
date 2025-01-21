NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra  -pthread -Werror -g  #-fsanitize=address 

SRC =  	main.c\
		pipex.c\
		pipex_utils.c\
		splitting.c\
		split.c\
		utils2.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re