# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/18 19:24:59 by jcolque           #+#    #+#              #
#    Updated: 2026/08/10 18:12:12 by jcolque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CHECKER		= checker
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -f
HEADER		= push_swap.h
HEADER_CH	= checker.h

# Fuentes exclusivas de push_swap
PS_SRCS		= push_swap.c \
		  parser.c

# Fuentes comunes a ambos binarios
COMMON_SRCS	= node.c \
		  push.c \
		  swap.c \
		  rotate.c \
		  reverse_rotate.c \
		  index.c \
		  sort.c \
		  sort_simple.c \
		  sort_medium.c \
		  sort_complex.c \
		  metrics.c \
		  ft_printf.c \
		  gnl_utils.c

# Fuentes exclusivas del checker
CH_SRCS		= checker.c \
		  checker_utils.c \
		  gnl.c

PS_OBJS		= $(PS_SRCS:.c=.o)
COMMON_OBJS	= $(COMMON_SRCS:.c=.o)
CH_OBJS		= $(CH_SRCS:.c=.o)

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(PS_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) $(COMMON_OBJS) -o $(NAME)

$(CHECKER): $(COMMON_OBJS) $(CH_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(CH_OBJS) -o $(CHECKER)

%.o: %.c $(HEADER) $(HEADER_CH)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PS_OBJS) $(COMMON_OBJS) $(CH_OBJS)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re
