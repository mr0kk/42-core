
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft

SRC = ./files

PRINTF_SRC = ft_printf.c printf_helpers.\
				hex_conv.c put_unint.c

OBJS = $(PRINTF_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

