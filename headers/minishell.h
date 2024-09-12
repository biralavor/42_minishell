/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/12 13:58:02 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define RESET	"\033[0m"

# include "../libs/libft/includes/libft.h"
# include "lexer.h"
# include "parser.h"
# include "error_manager.h"
# include "environment.h"
# include "executor.h"
# include "builtins.h"
# include "expansion.h"


/*INITIAL FUNCTIONS*/
/**
 * @brief     -> main function that calls for lexer, parser and executor.
 * @param str -> User input in command line.
*/
void	loop_routine(char *str);

#endif
