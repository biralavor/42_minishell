/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/16 09:46:52 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/includes/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <errno.h>
# include <unistd.h>

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define RESET	"\033[0m"

/**
 * @brief Token structure.
 * @param type      = token type.
 * @param lexeme    = actual string saved in token WORD.
 * @param next_char = to check for spaces.
 * @param idx       = node index.
 * @param prev      = previous node in token list.
 * @param next      = next node in token list.
*/
typedef struct s_token_list
{
	int					type;
	int					idx;
	char				*lexeme;
	char				next_char;
	struct s_token_list	*prev;
	struct s_token_list	*next;
}						t_token_list;

#endif
