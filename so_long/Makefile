# Compiler and Flags
CC = gcc
CFLAGS = -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) # -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
MLX_DIR = minilibx-linux
LIBFT_DIR = libft

# Libraries
MLX_LIB = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11
LIBFT_LIB = -L$(LIBFT_DIR) -lft

# Files
NAME = so_long
SRCS = $(SRC_DIR)/main.c  # Add other source files here
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(MLX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB) $(LIBFT_LIB)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
