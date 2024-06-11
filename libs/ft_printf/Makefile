#!----------------------------------------------------------------------------#
#                              COLORS                                         #
#!----------------------------------------------------------------------------#

CYAN			= \033[0;36m
GREEN			= \033[0;32m
PURPLE			= \033[0;35m
RED				= \033[31m
WHITE			= \033[37m
YELLOW			= \033[33m
RESET			= \033[0m

#!----------------------------------------------------------------------------#
#                                PATH                                         #
#!----------------------------------------------------------------------------#

SRC_D 			= ./src/
HEADERS_D		= ./includes/
BUILD_D			= ./build/

#!----------------------------------------------------------------------------#
#                                FILES                                        #
#!----------------------------------------------------------------------------#

NAME			= ft_printf.a

FILES			= ft_printf.c
FILES			+= ft_putchar_fd.c
FILES			+= ft_putnbr_fd.c
FILES			+= ft_putnbr_unsg_fd.c
FILES			+= ft_putstr_fd.c
FILES			+= ft_puthexa_low_fd.c
FILES			+= ft_puthexa_up_fd.c
FILES			+= ft_putptr_fd.c

SRC_FILES		= $(addprefix $(SRC_D), $(FILES))

OBJS			= $(addprefix $(BUILD_D), $(SRC_FILES:%.c=%.o))

#!----------------------------------------------------------------------------#
#                             COMMANDS                                        #
#!----------------------------------------------------------------------------#

MKDIR			= mkdir -p
RM				= rm -rf
SLEEP			= sleep 0.1
CC				= cc
AR				= ar -rcs

#!----------------------------------------------------------------------------#
#                                  FLAGS                                      #
#!----------------------------------------------------------------------------#

CFLAGS 			= -Wall -Wextra -Werror $(DFLAGS)
CPPFLAGS		= $(addprefix -I , $(HEADERS_D)) -MMD -MP
DFLAGS			= -g3

#!----------------------------------------------------------------------------#
#                             COMPILATION                                     #
#!----------------------------------------------------------------------------#

COMP_OBJS		= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_LIB		= @$(AR) $(NAME) $(OBJS)

#!----------------------------------------------------------------------------#
#                              TARGETS                                        #
#!----------------------------------------------------------------------------#

all:				$(NAME)

$(BUILD_D)%.o:		%.c
					@printf "$(YELLOW)"
					@$(MKDIR) $(dir $@)
					@$(COMPILE_OBJS)

					@echo "Compiling FT_PRINTF: $(notdir $<)"

$(NAME):			$(OBJS)
					@$(COMPILE_LIB)
					@printf "$(GREEN)"
					@echo "FT_PRINTF Ready!"
					@printf "$(RESET)"

clean:
					@printf "$(RED)"
					@echo ">>> Cleaning objects..."
					@printf "$(PURPLE)"
					$(RM) $(OBJS)
					$(RM) $(BUILD_D)
					@printf "$(RESET)"

fclean:				clean
					@printf "$(RED)"
					@echo ">>> Cleaning executables..."
					@printf "$(PURPLE)"
					$(RM) $(NAME)
					@printf "$(RESET)"

re:					fclean all

.PHONY:				all clean fclean re $(NAME)

