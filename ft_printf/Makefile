# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 14:57:12 by rmrok             #+#    #+#              #
#    Updated: 2025/02/09 17:46:53 by rmrok            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft

SRC = ./files

PRINTF_SRC = ft_printf.c printf_helpers.c\
				put_int.c hex_conv.c put_uint.c

OBJS = $(PRINTF_SRC:.c=.o)

RM = rm -f
CP = cp
AR = ar rcs

all: $(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			@$(CP) $(LIBFT) $(NAME)
			@$(AR) $(NAME) $(OBJS)

$(LIBFT):	$(LIBFTDIR)
			@$(MAKE) -C $(LIBFTDIR)

%.o: 		$(SRC)/%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(MAKE) clean -C $(LIBFTDIR)
			@$(RM) $(OBJS)

fclean:		clean
				@$(MAKE) fclean -C $(LIBFTDIR)
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re