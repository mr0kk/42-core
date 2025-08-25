CC = gcc
CFLAGS = -g # -Wall -Wextra -Werror
SERVER_SRC = server.c
CLIENT_SRC = client.c

LIBFT_DIR = libft
LIBFT_ARC = $(LIBFT_DIR)/libft.a

SERVER_NAME = server
CLIENT_NAME = client

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_SRC) $(LIBFT_ARC)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRC) -L$(LIBFT_DIR) -lft

$(CLIENT_NAME): $(CLIENT_SRC) $(LIBFT_ARC)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC) -L$(LIBFT_DIR) -lft

$(LIBFT_ARC):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re