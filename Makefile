# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vliubko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 18:46:49 by vliubko           #+#    #+#              #
#    Updated: 2018/06/04 15:02:58 by vliubko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= 21sh

CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I includes -I libft/includes
LDFLAGS		:= -L libft/ -lft -ltermcap

LIBFT		:= libft/libft.a
HEADER		 = includes/ft_21sh.h

FILES		:= main \
               helpers \
               terminal_mode \
               signals \
               line_editing/cursor_basic_moves\
               line_editing/cursor_word_home_moves\
               line_editing/line_edit_helpers\
               line_editing/insertion_deletion\
               execution/check_bi\
               env/env_commands\
               builtins/bi_cd\
               builtins/bi_env

S_DIR 	= src
O_DIR 	= obj

SRC 	= $(addprefix $(S_DIR)/, $(addsuffix .c, $(FILES)))
OBJ 	= $(addprefix $(O_DIR)/, $(addsuffix .o, $(FILES)))

.PHONY = all clean fclean re

all: lib obj $(NAME)

$(O_DIR)/%.o: src/%.c $(HEADER)
	@echo "\033[38;5;226m"
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo ""
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

obj:
	@mkdir -p obj
	@mkdir obj/line_editing
	@mkdir obj/execution
	@mkdir obj/env
	@mkdir obj/builtins

lib:
	@make -C libft

clean:
	@rm -f $(OBJ)
	@rm -rf $(O_DIR)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "\033[31mBinary \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all
