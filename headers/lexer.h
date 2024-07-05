/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:32:19 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/05 12:24:17 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

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

/*QUOTING ERROR CHECKING FUNCTIONS*/

/**
 * @brief Calls for initial error checking functions.
 * @param *str -> User input in command line.
*/
bool	check_initial_errors(char *str);

/**
 * @brief Checks for double quoting errors.
 * @param *str -> User input in command line.
*/
bool	check_closed_double_quotes(char *str);

/**
 * @brief Checks for single quoting errors.
 * @param *str -> User input in command line.
*/
bool	check_closed_single_quotes(char *str);

/*TOKEN LIST CREATION FUNCTIONS*/

/**
 * @brief Creates token list by calling the get_state function.
 * @param *str -> User input in command line.
*/
bool	create_token_list(char *str, t_token_list **lst);

/**
 * @brief Creates each token according to the present state.
 * @param **root -> The token list.
 * @param token -> Each of the tokens to be created.
*/
void	create_new_node(t_token_list **root, t_token_list *token);

/*STATE FUNCTIONS*/

/**
 * @brief Finds out the state of each token.
 * @param *str -> User input in command line.
 * @param **root -> The token list.
*/
void	get_state(int idx, char *str, t_token_list **lst);

int		state_10(t_token_list **lst, int idx, char next);
int		state_20(t_token_list **lst, int idx, char next);
int		state_30(t_token_list **lst, char curr, char next, int idx);
int		state_31(t_token_list **lst, int idx, char next);
int		state_32(t_token_list **lst, int idx, char next);
int		state_40(t_token_list **lst, int idx, char next);
int		state_50(t_token_list **lst, char curr, char next, int idx);
int		state_51(t_token_list **lst, int idx, char next);
int		state_52(t_token_list **lst, int idx, char next);
int		state_60(t_token_list **lst, char curr, char next, int idx);
int		state_61(t_token_list **lst, int idx, char next);
int		state_62(t_token_list **lst, int idx, char next);
int		state_70(t_token_list **lst, char *str, int idx);
int		state_80(t_token_list **lst, char *str, int idx);
int		state_90(t_token_list **lst, char *str, int idx);

/*UTILS*/

/**
 * @brief Compares the current character to the next.
*/
int		check_next_char(char curr, char next);

/**
 * @brief Verifies if the character is space.
*/
int		is_space(char c);
int		is_space(char c);

/**
 * @brief Frees the used memory to create the token list.
*/
void	free_token_list(t_token_list **lst);

/**
 * @brief Gets the size of the token list.
*/
int		ft_lst_size(t_token_list *lst);

/**
 * @brief TODO: APAGAR ESTA FUNÇÃO NO FINAL DO PROJETO.
*/
void	ft_lst_printf_content(char *str, t_token_list *lst);

/*ERROR MANAGER FUNCTIONS*/

/**
 * @brief Manages errors throughout the project before token list creation.
 * @param error_id -> error number defined in enum e_error in this header.
*/
void	error_manager_lexer(int error_id);

/**
 * @brief Indicates error in initial lexer quoting verifications.
*/
void	lexer_error(void);

/**
 * @brief Indicates error in token list creation.
*/
void	list_not_created(void);

#endif
