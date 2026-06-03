# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/30 17:25:12 by jcolque           #+#    #+#              #
#    Updated: 2026/06/03 18:04:34 by jcolque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
# COMPILER AND FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs

# SOURCES

SRC = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy \
      ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp \
      ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strtrim


# OBJECTS

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

# STYLING

RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
YELLOW = $(shell printf "\33[33m")
BLUE   = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
GRAY   = $(shell printf "\33[90m")
RESET  = $(shell printf "\33[0m")

TOTAL = $(words $(SRCS))
CURRENT = 0

define progress
	$(eval CURRENT = $(shell echo $$(($(CURRENT) + 1))))
	$(eval PERCENT = $(shell echo $$(($(CURRENT) * 100 / $(TOTAL)))))
	$(eval FILLED  = $(shell echo $$(($(CURRENT) * 20 / $(TOTAL)))))
	$(eval EMPTY   = $(shell echo $$((20 - $(FILLED)))))
	@printf "\r$(BLUE)[$(GREEN)$(shell printf '█%.0s' $(shell seq 1 $(FILLED)))$(GRAY)$(shell printf '░%.0s' $(shell seq 1 $(EMPTY)))$(BLUE)] $(YELLOW)$(PERCENT)%% $(RESET)$(BLUE)compiling $(RESET)$<   "
endef

# RULES

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n\n"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) created successfully.$(RESET)"
	@echo

%.o: %.c $(HEADER)
	$(call progress)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if ls *.o 2>/dev/null | grep -q .; then \
		rm -f $(OBJS); \
		echo "$(RED)✗ Objects removed.$(RESET)"; \
	else \
		echo "$(YELLOW)Nothing to clean.$(RESET)"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "$(RED)✗ $(NAME) removed.$(RESET)"; \
	else \
		echo "$(YELLOW)Nothing to fclean.$(RESET)"; \
	fi

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
