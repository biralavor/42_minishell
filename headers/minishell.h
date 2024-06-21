/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/21 15:04:16 by tmalheir         ###   ########.fr       */
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

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define BLUE    "\x1b[34m"
# define RESET   "\x1b[0m"

typedef struct s_token_list
{
	int					type;
	char				*lexeme;
	struct s_token_list	*prev;
	struct s_token_list	*next;
}						t_token_list;

enum e_token
{
	WORD,
	PIPE,
	REDIRECT_INPUT,
	REDIRECT_HEREDOC,
	REDIRECT_OUTPUT,
	REDIRECT_OUTPUT_APPEND,
	OR,
	AND,
	OPEN_PARENTHESIS,
	CLOSE_PARENTHESIS
};

/*INITIAL FUNCTIONS*/

void	check_userinput(char *str);

/*ERROR CHECKING FUNCTIONS*/

/**
 * @brief Calls for initial error checking functions.
 * @param *str -> User input in command line.
*/
int		check_initial_errors(char *str);

/**
 * @brief Check for double quoting errors: (1) means error.
 * @param *str -> User input in command line.
*/
int		check_double_quotes(char *str);

/**
 * @brief Check for single quoting errors: (1) means error.
 * @param *str -> User input in command line.
*/
int		check_single_quotes(char *str);

/**
 * @brief Check for single ampersand error: (1) means error.
 * @param *str -> User input in command line.
*/
int		check_single_ampersand(char *str);

/*TOKEN LIST CREATION FUNCTIONS*/

/**
 * @brief Create token list by calling the get_state function.
 * @param *str -> User input in command line.
*/
void	create_token_list(char *str);

/**
 * @brief Create each token according to the present state.
 * @param **root -> The token list.
 * @param token -> Each of the tokens to be created.
*/
void	create_new_node(t_token_list **root, t_token_list *token);

/*STATE FUNCTIONS*/

/**
 * @brief Find out the state of each token.
 * @param *str -> User input in command line.
 * @param **root -> The token list.
*/
void	get_state(int idx, char *str, t_token_list **lst);

int		state_1(t_token_list **lst, int idx);
int		state_2(t_token_list **lst, int idx);
int		state_3(t_token_list **lst, char curr, char next, int idx);
int		state_4(t_token_list **lst, int idx);
int		state_5(t_token_list **lst, int idx);
int		state_6(t_token_list **lst, int idx);
int		state_7(t_token_list **lst, char curr, char next, int idx);
int		state_8(t_token_list **lst, int idx);
int		state_9(t_token_list **lst, int idx);
int		state_10(t_token_list **lst, char curr, char next, int idx);
int		state_11(t_token_list **lst, int idx);
int		state_12(t_token_list **lst, int idx);
int		state_13(t_token_list **lst, char *str, int idx);
int		state_14(t_token_list **lst, char *str, int idx);
int		state_15(t_token_list **lst, char *str, int idx);

/*UTILS*/

/**
 * @brief Compare the current character to the next.
*/
int		check_next_char(char curr, char next);

/**
 * @brief Print a message error in case of error in get_state.
*/
void	lexer_error(void);

/**
 * @brief Free the used memory to create the token list.
*/
void	free_token_list(t_token_list **lst);

/**
 * @brief APAGAR ESTA FUNÇÃO NO FINAL DO PROJETO.
*/
void	ft_lst_printf_content(char *str, t_token_list *lst);

#endif