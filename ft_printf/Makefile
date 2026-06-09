# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/09 15:01:59 by jcolque           #+#    #+#              #
#    Updated: 2026/06/09 17:10:03 by jcolque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = libftprintf.a

HEADER = ft_printf.h

# Directory | 

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

# Compile and flags

CC	  = cc
CFLAGS	  = -Wall -Wextra -Werror
AR	  = ar rcs

PRINTF_SRC  = ft_printf #ft_printf_utils ft_printf_hex ft_printf_ptr ft_printf_nbr
PRINTF_SRCS = $(addsuffix .c, $(PRINTF_SRC))
PRINTF_OBJS = $(addsuffix .o, $(PRINTF_SRC))


# Styles

RED     = $(shell printf "\33[31m")
GREEN   = $(shell printf "\33[32m")
YELLOW  = $(shell printf "\33[33m")
BLUE    = $(shell printf "\33[34m")
PURPLE  = $(shell printf "\33[35m")
GRAY    = $(shell printf "\33[90m")
RESET   = $(shell printf "\33[0m")

# Progress Bar

TOTAL	= $(words $(PRINTF_OBJS))
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
# Rule

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF_OBJS)
	@printf "\n\n"
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(PRINTF_OBJS)
	@echo "$(GREEN)✓ $(NAME) created successfully.$(RESET)"
	@echo

# Compile libft
$(LIBFT):
	+@make -C $(LIBFT_DIR)

# Compilación de cada fuente de ft_printf
%.o: %.c $(HEADER) Makefile
	$(call progress)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo ""

# Clean
clean:
	@rm -f $(PRINTF_OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)✗ Objects removed.$(RESET)"

fclean:
	@rm -f $(NAME) $(PRINTF_OBJS)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)✗ Objects and $(NAME) removed.$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
