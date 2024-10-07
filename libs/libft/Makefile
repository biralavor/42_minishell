
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

NAME			= libft.a

FILES			= ft_array_len.c
FILES			+= ft_atoi.c
FILES			+= ft_bzero.c
FILES			+= ft_calloc.c
FILES			+= ft_isascii.c
FILES			+= ft_isalnum.c
FILES			+= ft_isalpha.c
FILES			+= ft_isdigit.c
FILES			+= ft_isprint.c
FILES			+= ft_itoa.c
FILES			+= ft_memchr.c
FILES			+= ft_memcmp.c
FILES			+= ft_memcpy.c
FILES			+= ft_memmove.c
FILES			+= ft_memset.c
FILES			+= ft_putendl_fd.c
FILES			+= ft_split.c
FILES			+= ft_strchr.c
FILES			+= ft_strlcat.c
FILES			+= ft_strncmp.c
FILES			+= ft_strcmp.c
FILES			+= ft_strdup.c
FILES			+= ft_striteri.c
FILES			+= ft_strjoin.c
FILES			+= ft_strmapi.c
FILES			+= ft_strnstr.c
FILES			+= ft_strlcpy.c
FILES			+= ft_strlen.c
FILES			+= ft_strrchr.c
FILES			+= ft_strtrim.c
FILES			+= ft_substr.c
FILES			+= ft_toupper.c
FILES			+= ft_tolower.c
FILES			+= ft_printf.c
FILES			+= ft_putchar_fd.c
FILES			+= ft_puthexa_low_fd.c
FILES			+= ft_puthexa_up_fd.c
FILES			+= ft_putnbr_fd.c
FILES			+= ft_putnbr_unsg_fd.c
FILES			+= ft_putptr_fd.c
FILES			+= ft_putstr_fd.c
FILES			+= ft_merge_strings.c

SRC_FILES		= $(addprefix $(SRC_D), $(FILES))

OBJS			= $(addprefix $(BUILD_D), $(FILES:%.c=%.o))

#!----------------------------------------------------------------------------#
#                             COMMANDS                                        #
#!----------------------------------------------------------------------------#

MKDIR			= mkdir -p
RM				= rm -rf
SLEEP			= sleep 0.1
CC				= cc
AR				= ar rcs

#!----------------------------------------------------------------------------#
#                                  FLAGS                                      #
#!----------------------------------------------------------------------------#

CFLAGS 			= -Wall -Wextra -Werror $(DFLAGS)
CPPFLAGS		= $(addprefix -I, $(HEADERS_D)) -MMD -MP
DFLAGS			= -g3

#!----------------------------------------------------------------------------#
#                             COMPILATION                                     #
#!----------------------------------------------------------------------------#

COMPILE_OBJS	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_LIB		= $(AR) $@ $^

#!----------------------------------------------------------------------------#
#                              TARGETS                                        #
#!----------------------------------------------------------------------------#

all:				$(NAME)

$(NAME):			$(OBJS)
					@$(COMPILE_LIB)
					@printf "$(GREEN)"
					@echo "--------------------------------------------------------------------"
					@echo "		$(NAME) READY!"
					@echo "--------------------------------------------------------------------"
					@printf "$(RESET)"
					
$(BUILD_D)%.o:		$(SRC_D)%.c
					@printf "$(YELLOW)"
					@$(MKDIR) $(dir $@)
					@$(COMPILE_OBJS)
					@echo "$(NAME)		compiling -> $(GREEN)$(notdir $<)"
					@printf "$(RESET)"

-include $(OBJS:.o=.d)

clean:
					@printf "$(RED)"
					@echo ">>> Cleaning objects from: $(PURPLE) $(NAME)"
					@$(RM) $(OBJS)
					@$(RM) $(BUILD_D)
					@printf "$(RESET)"

fclean:				clean
					@printf "$(RED)"
					@echo ">>> Cleaning executables from: $(PURPLE) $(NAME)"
					@$(RM) $(NAME)
					@printf "$(RESET)"

re:					fclean all

.PHONY:				all clean fclean re
