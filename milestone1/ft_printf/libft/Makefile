# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/30 17:25:12 by jcolque           #+#    #+#              #
#    Updated: 2026/06/09 17:06:53 by jcolque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
# COMPILER AND FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

# SOURCES

SRC = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy \
      ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp \
      ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split \
      ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
      ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

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
	@printf "\r$(BLUE)[$(GREEN)" ; \
	for i in $$(seq 1 $(FILLED)); do printf "█"; done ; \
	printf "$(GRAY)" ; \
	for i in $$(seq 1 $(EMPTY)); do printf "░"; done ; \
	printf "$(BLUE)] $(YELLOW)%d%% $(RESET)$(BLUE)compiling $(RESET)$<   \033[K" $(PERCENT)
endef
# RULES

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n\n"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) created successfully.$(RESET)"
	@echo

%.o: %.c $(HEADER) Makefile
	$(call progress)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -n "$(wildcard *.o)" ]; then \
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
