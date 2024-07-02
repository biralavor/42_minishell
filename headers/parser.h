/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/01 22:37:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

/*SYNTAX ERROR CHECKING FUNCTIONS*/

/**
 * @brief Calls for initial syntax error checking functions.
 * @param *lst -> the token list.
*/
bool	check_initial_syntax(t_token_list *lst);

/**
 * @brief Check syntax error in the first token.
 * @param *lst -> the token list.
*/
bool	check_first_node(t_token_list *lst);

/**
 * @brief Check for single ampersand and semicolon.
 * @param *lst -> the token list.
*/
bool	check_lexeme(t_token_list *lst);

/**
 * @brief Auxiliar function to check for single ampersand and semicolon.
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

/**
 * @brief Check for not closed quotes.
 * @param *lst -> the token list.
*/
bool	check_quotes(t_token_list *lst);

/**
 * @brief Check for empty quotes.
 * @param *str -> User input in command line.
*/
bool	check_empty_quotes(char *str);

/**
 * @brief Check for closed parenthesis.
 * @param *lst -> the token list.
*/
bool	check_closed_parenthesis(t_token_list *lst);

/**
 * @brief Manages open parenthesis error.
 * @param *lst -> the token list.
*/
void	parenthesis_error(t_token_list *lst);

/**
 * @brief Checks token after parenthesis error and displays it in a msg error.
 * @param *lst -> the token list.
*/
char	*check_next_token(int	unexpected_token);

/*ERROR MANAGER FUNCTIONS*/

/**
 * @brief Manages errors throughout the project after token list creation.
 * @param error_id -> error number defined in enum e_error in this header.
 * @param lst -> the token list.
*/
void	error_manager_parser(int error_id, t_token_list *lst);

/**
 * @brief Manages token errors in the first node.
 * @param lst -> the token list.
*/
void	unexpected_token_error(t_token_list *lst);

/**
 * @brief Manages semicolon and ampersand errors.
 * @param lst -> the token list.
*/
void	syntax_error(t_token_list *lst);

void	command_not_found(t_token_list *lst);

void	parenthesis_error(t_token_list *lst);

#endif