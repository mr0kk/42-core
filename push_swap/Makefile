CC = gcc
CFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -g -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft

LIBFT_LIB = -L$(LIBFT_DIR) -lft

NAME = push_swap
SRCS = $(SRC_DIR)/main.c \
			$(SRC_DIR)/validate_input.c \
			$(SRC_DIR)/read_input.c \
			$(SRC_DIR)/swap.c \
			$(SRC_DIR)/push.c \
			$(SRC_DIR)/rotate.c \
			$(SRC_DIR)/r_rotate.c \
			$(SRC_DIR)/sorting.c \
			$(SRC_DIR)/stack_utils.c \
			$(SRC_DIR)/sort_utils.c \
			$(SRC_DIR)/turk_utils.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/turk.c \
			$(SRC_DIR)/printing_stack.c 
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:  $(LIBFT_DIR)/libft.a $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
