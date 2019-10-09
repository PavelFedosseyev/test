NAME = fdf.out
INCLUDES = -I ./includes
MINILIBX = -I ./minilibx_macos -L minilibx_macos -lmlx \
			-framework OpenGL -framework AppKit
LIBFT = libft/libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g 
SRC =	./src/fdf.c \
		./src/intarr.c \
		./src/tripleiso.c \
		./src/closewindow.c \
		./src/firstandsecond.c \
		./src/drawline.c \

OBJ = $(SRC:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) $(MINILIBX) -o $(NAME)

clean:
	@/bin/$(RM) $(OBJ)
	@make -C libft clean

fclean: clean
	@/bin/$(RM) $(NAME)
	@make -C libft fclean

re: fclean all
