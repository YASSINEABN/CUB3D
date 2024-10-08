
CC := cc

CFLAGS = -Wall -Wextra -Werror

NAME := cub3D

SRC = main.c helper_functions/helper_functions.c  helper_functions/quee_functions_helper.c  helper_functions/helper_functions1.c  helper_functions/helper_functions2.c  helper_functions/helper_Textures.c  helper_functions/helper_functions3.c  helper_functions/helper_functions4.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) libft/libft.a

clean:
	rm -rf $(OBJ) 

fclean:	
	rm -rf $(NAME) $(OBJ) 

re: fclean all