
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror# -lm -I include -I $(MINILIBX)

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

SRC_DIR = ./src
SRC = main.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(SRCS:.c=.o)

RM = rm -f
CP = cp
AR = ar rcs

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBFT_DIR)
			@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
			$(CC) $(CFLAGS) -Imlx -c -o $@ $<

clean:
			@$(MAKE) clean -C $(LIBFT_DIR)
			@$(RM) $(OBJ)

fclean: clean
			@$(MAKE) fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re: fclean all