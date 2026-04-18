CC = cc
CFLAGS = -pthread -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_PATH = ./include/

NAME = philo
SRCS = $(SRC_DIR)/main.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/init.c \
			$(SRC_DIR)/time_management.c \
			$(SRC_DIR)/safe_handling.c \
			$(SRC_DIR)/dinner.c \
			$(SRC_DIR)/getters_setters.c \
			$(SRC_DIR)/synchro_utils.c \
			$(SRC_DIR)/print_status.c \
			$(SRC_DIR)/monitoring.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

