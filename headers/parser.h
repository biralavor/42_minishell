/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/28 14:12:52 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "lexer.h"

/*SYNTAX ERROR CHECKING FUNCTIONS*/

/**
 * @brief Calls for initial syntax error checking functions.
 * @param *lst -> the token list.
*/
bool	check_initial_syntax_errors(t_token_list *lst);

/**
 * @brief Check syntax error in the first token.
 * @param *lst -> the token list.
*/
bool	check_first_node_errors(t_token_list *lst);

/**
 * @brief Check for single ampersand, semicolon and empty quotes.
 * @param *str -> User input in command line.
*/
bool	check_lexeme_errors(char *str);

/**
 * @brief Check for single ampersand error.
 * @param *str -> User input in command line.
*/
bool	check_double_ampersand(char *str);

/**
 * @brief Check for semicolon.
 * @param *str -> User input in command line.
*/
bool	check_semicolon(char *str);

bool	check_empty_quotes(char *str);

bool	check_closed_parenthesis(t_token_list *lst);

/**
 * @brief Print a message error in case of error in parser.
*/
bool	parser_error(void);


#endif