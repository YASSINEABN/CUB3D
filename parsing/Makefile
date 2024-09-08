
CC := cc

NAME := cub3D

SRC = main.c helper_functions.c quee_functions.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) libft/libft.a

clean:
	rm -rf $(OBJ) 

fclean:	
	rm -rf $(NAME) $(OBJ) 

re: fclean all