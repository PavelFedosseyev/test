NAME = fdf
INCLUDES = -I ./includes
MINILIBX = -I ./minilibx_macos -L minilibx_macos -lmlx \
			-framework OpenGL -framework AppKit
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
SRC =	./src/fdf.c \
		./src/fillzero.c \
		./src/openfile.c \
		./src/countsizes.c \
		./src/fillar.c \
		./src/createintarr.c \
		./src/triplearr.c \
		./src/tripleiso.c \
		./src/openwindow.c \
		./src/firstandsecond.c \
		./src/drawline.c \

OBJ = $(SRC:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(MINILIBX) -o $(NAME)

clean:
	@/bin/$(RM) $(OBJ)

fclean: clean
	@/bin/$(RM) $(NAME)

re: fclean all
