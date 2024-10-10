/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/09 18:15:20 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <termios.h>
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

# define PATH_MAX 4096

# include "../libs/libft/includes/libft.h"
# include "lexer.h"
# include "parser.h"
# include "error_manager.h"
# include "environment.h"
# include "execution.h"
# include "builtins.h"
# include "expansion.h"

/*INITIAL FUNCTIONS*/
/**
 * @brief     -> main function that calls for lexer, parser and executor.
 * @param str -> User input in command line.
*/
void	loop_routine(char *str);

extern volatile sig_atomic_t	g_sigmonitor;

void	signals_init(bool interactive);
// void	signals_manager(int sig_nbr);
void	interrupt_signal_runner(int sig);
// void	quit_signal_blocker(void);

void	tty_proprieties_manager(bool update);

bool	is_after_loop(bool update);

void	control_d_handler(char *input);
bool	addto_history_detector(const char *input);

bool	is_interactive(void);
void	sigquit_activated(void);

#endif
