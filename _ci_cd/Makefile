# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 11:46:22 by umeneses          #+#    #+#              #
#    Updated: 2024/09/20 18:48:40 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
RESET			:= \033[0m

# **************************************************************************** #
#								PATHS										   #
# **************************************************************************** #

TEST_D				= ./
BUILD_D				= ./test_build/
PROGRAM_TO_TEST_D	= ../
LIBFT_D				= $(PROGRAM_TO_TEST_D)libs/libft/
HEADERS_ADDED		= $(PROGRAM_TO_TEST_D)headers/
HEADERS				= ./headers/ $(HEADERS_ADDED)

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

PROGRAM_TO_TEST		= $(addprefix $(PROGRAM_TO_TEST_D), minishell)
LIBFT				= $(addprefix $(LIBFT_D), libft.a)
LIBS				= $(LIBFT) $(PROGRAM_TO_TEST_D)

NAME				= minishell.tests

SRC_FILES			= minishell_main_tester.c

SRC_FILES_ALL		= $(addprefix $(TEST_D), $(SRC_FILES))

OBJ_FILES			= $(addprefix $(BUILD_D), $(SRC_FILES_ALL:%.c=%.o))

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR		= umeneses
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
CPPFLAGS	= $(addprefix -I, $(HEADERS)) -MMD -MP
LDFLAGS		= $(addprefix -L, $(dir $(LIBS)))
LDLIBS		= -lft -ldl -lreadline
COMP_OBJS	= $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
COMP_EXE	= $(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# **************************************************************************** #
#								DEFINES										   #
# **************************************************************************** #

define		arguments
		"this is a test"
endef

define 		bonus
			@printf "$(YELLOW)"
			@echo ">>> Checking BONUS"
			@printf "$(CYAN)"
			@$(MAKE) -C $(PROGRAM_TO_TEST_D) bonus --no-print-directory
endef

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all: 				$(NAME)

$(BUILD_D)%.o:		%.c
					@$(MKDIR) $(dir $@)
					@$(COMP_OBJS)
					@printf "$(CYAN)"
					@echo "$(NAME) compiling -> $(GREEN)$(notdir $<)"
					@printf "$(RESET)"

$(NAME):			clean minishell $(OBJ_FILES)
					@$(COMP_EXE)
					@printf "$(PURPLE)"
#					@echo ">>> Running MINI_SHELL with default arguments:"
#					@echo "$(call arguments)"
#					@printf "$(CYAN)"
#					$(PROGRAM_TO_TEST_D)./minishell $(call arguments)
					@printf "$(GREEN)"
					@echo "$(NAME) Ready!"
					@printf "$(RESET)"
					@./$(NAME)

minishell:
					@printf "$(YELLOW)"
					@echo ">>> Checking MINI_SHELL"
					@printf "$(CYAN)"
					@$(MAKE) -C $(PROGRAM_TO_TEST_D) --no-print-directory

bonus:
					$(call bonus)

clean:
					@printf "$(RED)"
					@echo ">>> Cleaning objects from: $(PURPLE) $(NAME)"
					@$(RM) $(OBJ_FILES)
					@$(RM) $(BUILD_D)
					@printf "$(RESET)"

fclean:				clean
					@printf "$(RED)"
					@echo ">>> Cleaning executables from: $(PURPLE) $(NAME)"
					@$(RM) $(NAME)
					@$(RM) $(NAME_BONUS)
					@$(MAKE) -C $(PROGRAM_TO_TEST_D) fclean --no-print-directory
					@printf "$(RESET)"

re:					fclean all

gdb:				all
					gdb --tui -ex 'b main' -ex 'set follow-fork-mode child' -ex 'run' ./$(NAME)

.PHONY:				all clean fclean re bonus gdb