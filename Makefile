# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:     #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 11:46:52 by umeneses          #+#    #+#              #
#    Updated: 2024/08/07 16:50:46 by umeneses         ###   ########.fr        #
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

SRC_D					= ./src/
BONUS_D					= ./bonus/
BUILD_D					= ./build/
LIBS_D					= ./libs/
LIBFT_D					= $(LIBS_D)libft/
HEADERS_ADDED			= $(LIBFT_D)includes/
HEADERS_ADDED			+= $(FT_PRINTF)includes/
HEADERS_ADDED			+= $(BONUS_D)headers/
HEADERS					= ./headers/ $(HEADERS_ADDED)

TDD_UTILS_D				= ./_tdd_utils/
# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

LIBFT					= $(addprefix $(LIBFT_D), libft.a)
LIBS					= $(LIBFT)

NAME					= minishell

SRC_FILES				= 01.main.c
SRC_FILES				+= 02.signals.c
SRC_FILES				+= 03.env_init.c
SRC_FILES				+= 04.env_init_utils.c
SRC_FILES				+= 05.loop_routine.c
SRC_FILES				+= tty_proprieties.c
SRC_FILES				+= ./01_lexer/06.check_initial_errors.c
SRC_FILES				+= ./01_lexer/07.token_list_functions.c
SRC_FILES				+= ./01_lexer/08.get_state.c
SRC_FILES				+= ./01_lexer/09.state10_to_state30.c
SRC_FILES				+= ./01_lexer/10.state40_to_state60.c
SRC_FILES				+= ./01_lexer/11.state61_to_state90.c
SRC_FILES				+= ./01_lexer/12.error_manager_lexer.c
SRC_FILES				+= ./01_lexer/13.lexer_utils.c
SRC_FILES				+= ./01_lexer/lexer_utils_2.c
SRC_FILES				+= ./02_parser/14.syntax_analysis.c
SRC_FILES				+= ./02_parser/15.state100.c
SRC_FILES				+= ./02_parser/16.state200_to_state300.c
SRC_FILES				+= ./02_parser/17.check_redirects.c
SRC_FILES				+= ./02_parser/18.check_redirects_utils.c
SRC_FILES				+= ./02_parser/19.error_manager_parser.c
SRC_FILES				+= ./02_parser/20.manage_heredoc.c
SRC_FILES				+= ./02_parser/heredoc_expansions.c
SRC_FILES				+= ./02_parser/heredoc_fds.c
SRC_FILES				+= ./03_binary_tree/21.building_tree.c
SRC_FILES				+= ./03_binary_tree/22.building_tree_utils.c
SRC_FILES				+= ./04_tree_execution/23.tree_execution.c
SRC_FILES				+= ./04_tree_execution/24.tree_execution_utils.c
SRC_FILES				+= ./04_tree_execution/25.manage_or_and.c
SRC_FILES				+= ./04_tree_execution/26.manage_pipe.c
SRC_FILES				+= ./04_tree_execution/manage_pipe_utils.c
SRC_FILES				+= ./04_tree_execution/27.manage_redirects.c
SRC_FILES				+= ./04_tree_execution/manage_redirects_utils.c
SRC_FILES				+= ./04_tree_execution/28.manage_subshell.c
SRC_FILES				+= ./04_tree_execution/29.manage_single_cmd.c
SRC_FILES				+= ./05_expansions/30.expansion_manager.c
SRC_FILES				+= ./05_expansions/31.expansion_detectors.c
SRC_FILES				+= ./05_expansions/32.expansion_quotes.c
SRC_FILES				+= ./05_expansions/33.expansion_tilde.c
SRC_FILES				+= ./05_expansions/34.expansion_env_var.c
SRC_FILES				+= ./05_expansions/35.expansion_env_var_utils.c
SRC_FILES				+= ./05_expansions/expansion_env_var_utils_2.c
SRC_FILES				+= ./05_expansions/36.expansion_question.c
SRC_FILES				+= ./05_expansions/expansion_parent_dir.c
SRC_FILES				+= ./06_builtins/37.builtin_detectors.c
SRC_FILES				+= ./06_builtins/38.builtin_manager.c
SRC_FILES				+= ./06_builtins/39.builtin_utils.c
SRC_FILES				+= ./06_builtins/40.builtin_echo.c
SRC_FILES				+= ./06_builtins/41.builtin_cd.c
SRC_FILES				+= ./06_builtins/42.builtin_cd_utils.c
SRC_FILES				+= ./06_builtins/43.builtin_pwd.c
SRC_FILES				+= ./06_builtins/44.builtin_export.c
SRC_FILES				+= ./06_builtins/45.builtin_export_utils.c
SRC_FILES				+= ./06_builtins/46.builtin_unset.c
SRC_FILES				+= ./06_builtins/47.builtin_env.c
SRC_FILES				+= ./06_builtins/48.builtin_exit.c
SRC_FILES				+= ./06_builtins/49.builtin_exit_utils.c
SRC_FILES				+= ./07_command_execution/50.command_runner.c
SRC_FILES				+= ./07_command_execution/51.command_runner_utils.c
SRC_FILES				+= ./07_command_execution/execve_error_manager.c

SRC_FILES_ALL			= $(addprefix $(SRC_D), $(SRC_FILES))

TDD_FILES				= ft_lst_printer.c
TDD_FILES				+= get_token_string.c
TDD_FILES				+= ft_tree_printer.c
TDD_FILES				+= ft_env_printer.c
TDD_FILES				+= ft_array_printer.c
TDD_FILES_ALL			= $(addprefix $(TDD_UTILS_D), $(TDD_FILES))
TDD_OBJS_FILES			= $(addprefix $(BUILD_D), $(TDD_FILES_ALL:%.c=%.o))

OBJS_FILES				= $(addprefix $(BUILD_D), $(SRC_FILES_ALL:%.c=%.o))
OBJS_ALL				= $(TDD_OBJS_FILES) $(OBJS_FILES)

# **************************** #
#			BONUS			   #
# **************************** #

NAME_BONUS				= minishell_bonus

SRC_FILES_BONUS			= $(SRC_FILES_ALL)

SRC_BONUS_ALL			= $(addprefix $(SRC_BONUS_D), $(SRC_FILES_BONUS))

OBJS_FILES_BONUS		= $(addprefix $(BUILD_D), $(SRC_BONUS_ALL:%.c=%.o))
OBJS_ALL_BONUS			= $(OBJS_FILES_BONUS)

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								DEFINES										   #
# **************************************************************************** #

define	project_title
		@printf "$(CYAN)"
		@echo "                                                                    "
		@echo "#########################    WELCOME TO    #########################"
		@echo "                                                                    "
		@echo "                     _       _     _          _ _                   "
		@echo "                    (_)     (_)   | |        | | |                  "
		@echo "           _ __ ___  _ _ __  _ ___| |__   ___| | |                  "
		@echo "          | '_   _ \| | '_ \| / __| '_ \ / _ \ | |                  "
		@echo "          | | | | | | | | | | \__ \ | | |  __/ | |                  "
		@echo "          |_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|                  "
		@echo "                                                                    "
		@echo "                                                                    "
		@echo "####################################################################"
		@echo "                                                                    "
		@printf "$(RESET)"
endef

define	project_title_bonus
		@printf "$(CYAN)"
		@echo "                                                                    "
		@echo "#########################    WELCOME TO    #########################"
		@echo "                                                                    "
		@echo "                     _       _     _          _ _                   "
		@echo "                    (_)     (_)   | |        | | |                  "
		@echo "           _ __ ___  _ _ __  _ ___| |__   ___| | |                  "
		@echo "          | '_   _ \| | '_ \| / __| '_ \ / _ \ | |                  "
		@echo "          | | | | | | | | | | \__ \ | | |  __/ | |                  "
		@echo "          |_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|                  "
		@echo "                                                                    "
		@echo "                                                                    "
		@echo "#########################       BONUS      #########################"
		@echo "                                                                    "
		@printf "$(RESET)"
endef

define					instructions
						@echo "TODO: add instructions here"

endef

define					instructions_bonus
						@echo "TODO: add bonus instructions here"
endef

ifdef					WITH_BONUS
	NAME				= $(NAME_BONUS)
	OBJS_FILES			= $(OBJS_FILES_BONUS)
	OBJS_ALL			= $(OBJS_ALL_BONUS)
	project_title		= $(project_title_bonus)
	instructions		= $(instructions_bonus)
endif

define					bonus
						$(MAKE) WITH_BONUS=TRUE --no-print-directory
endef

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR		= tmalheir && umeneses
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
CPPFLAGS	= $(addprefix -I, $(HEADERS)) -MMD -MP
LDFLAGS		= $(addprefix -L, $(dir $(LIBS)))
LDLIBS		= -lft -ldl -lreadline
COMP_OBJS	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE	= $(CC) $(CFLAGS) $(LDFLAGS) $(OBJS_ALL) $(LDLIBS) -o $(NAME)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all: 				libft_lib $(NAME)

$(BUILD_D)%.o:		%.c
					@$(MKDIR) $(dir $@)
					@$(COMP_OBJS)
					@printf "$(CYAN)"
					@echo "$(NAME)	compiling -> $(GREEN)$(notdir $<)"
					@printf "$(RESET)"

$(NAME):			$(OBJS_ALL)
					@$(COMP_EXE)
					@printf "$(GREEN)"
					@echo "--------------------------------------------------------------------"
					@echo "		$(NAME) READY!"
					@echo "--------------------------------------------------------------------"
					$(call project_title)
					@printf "$(YELLOW)"
					$(call instructions)
					@printf "$(RESET)"

libft_lib:
					@printf "$(YELLOW)"
					@echo ">>> Checking LIBFT"
					@printf "$(CYAN)"
					@$(MAKE) -C $(LIBFT_D) --no-print-directory
					@printf "$(YELLOW)"
					@printf "$(RESET)"

bonus:
					$(call bonus)

clean:
					@printf "$(RED)"
					@echo ">>> Cleaning objects from: $(PURPLE) $(NAME)"
					@$(RM) $(OBJS)
					@$(RM) $(BUILD_D)
					@$(MAKE) -C $(LIBFT_D) fclean --no-print-directory
					@printf "$(RESET)"

fclean:				clean
					@printf "$(RED)"
					@echo ">>> Cleaning executables from: $(PURPLE) $(NAME)"
					@$(RM) $(NAME)
					@$(RM) $(NAME_BONUS)
					@printf "$(RESET)"

re:					fclean all

min:				re
					./$(NAME)

go:					all
					./$(NAME)

gdb:				all
					gdb --tui -ex 'b main' -ex 'set detach-on-fork off' -ex 'info inferiors' -ex 'run > /dev/null 2>&1' ./$(NAME)

val:				all
					valgrind --leak-check=full --track-origins=yes --trace-children-skip='*/bin/*,*/sbin/*,/usr/bin/*' --trace-children=yes --track-fds=yes --show-reachable=yes --suppressions=readline.sup ./$(NAME)

.PHONY:				all clean fclean re bonus min val gdb