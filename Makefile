# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 11:46:52 by umeneses          #+#    #+#              #
#    Updated: 2024/07/12 15:53:54 by tmalheir         ###   ########.fr        #
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

SRC_FILES				= 01.simple_main.c
SRC_FILES				+= 02.check_userinput.c
SRC_FILES				+= ./lexer/03.check_initial_errors.c
SRC_FILES				+= ./lexer/04.create_token_list.c
SRC_FILES				+= ./lexer/05.get_state.c
SRC_FILES				+= ./lexer/06.state10_to_state30.c
SRC_FILES				+= ./lexer/07.state40_to_state60.c
SRC_FILES				+= ./lexer/08.state61_to_state90.c
SRC_FILES				+= ./lexer/09.error_manager_lexer.c
SRC_FILES				+= ./lexer/10.lexer_utils.c
SRC_FILES				+= ./parser/11.syntax_analysis.c
SRC_FILES				+= ./parser/12.state100.c
SRC_FILES				+= ./parser/13.utils_parsing_word.c
SRC_FILES				+= ./parser/14.state200.c
SRC_FILES				+= ./parser/15.state300.c
SRC_FILES				+= ./parser/16.state400.c
SRC_FILES				+= ./parser/17.error_manager_parser.c
SRC_FILES				+= ./parser/18.parser_utils.c
SRC_FILES				+= ./executor/19.build_tree.c
#SRC_FILES				= minishell_main.c
#SRC_FILES				+= ft_lexical_analysis.c

SRC_FILES_ALL			= $(addprefix $(SRC_D), $(SRC_FILES))

TDD_FILES				= ft_lst_print_content.c
TDD_FILES_ALL			= $(addprefix $(TDD_UTILS_D), $(TDD_FILES))
TDD_OBJS_FILES			= $(addprefix $(BUILD_D), $(TDD_FILES_ALL:%.c=%.o))

OBJS_FILES				= $(addprefix $(BUILD_D), $(SRC_FILES_ALL:%.c=%.o))
OBJS_ALL				= $(TDD_OBJS_FILES) $(OBJS_FILES)

# **************************** #
#			BONUS			   #
# **************************** #

NAME_BONUS				= minishell_bonus

SRC_FILES_BONUS			=

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

all: 				$(NAME)

$(BUILD_D)%.o:		%.c
					@$(MKDIR) $(dir $@)
					@$(COMP_OBJS)
					@printf "$(CYAN)"
					@echo "Compiling: $(notdir $<)"
					@printf "$(RESET)"

$(NAME):			libft_lib $(OBJS_ALL)
					@$(COMP_EXE)
					@printf "$(GREEN)"
					@echo "$(NAME) Ready!"
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
					@echo ">>> Cleaning objects"
					@printf "$(PURPLE)"
					$(RM) $(OBJS_ALL)
					$(RM) $(BUILD_D)
					$(MAKE) -C $(LIBFT_D) fclean
					@printf "$(RESET)"

fclean:				clean
					@printf "$(RED)"
					@echo ">>> Cleaning executables"
					@printf "$(PURPLE)"
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)
					@printf "$(RESET)"

re:					fclean all

.PHONY:				all clean fclean re bonus