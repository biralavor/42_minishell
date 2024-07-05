/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/05 11:34:18 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

/*SYNTAX VALIDATIONS FUNCTIONS*/

void	syntax_analysis(t_token_list *lst);

int		syntax_validations(t_token_list *lst);

void	check_syntax_state(t_token_list *lst, int syntax_state);

int	state_100(t_token_list *lst, int syntax_state);

int	state_200(t_token_list *lst, int syntax_state);

int	state_300(t_token_list *lst, int syntax_state);

int	state_400(t_token_list *lst, int syntax_state);

int	state_401(t_token_list *lst);

int	state_402(t_token_list *lst);

int	match_parenthesis(int open_par, int close_par, t_token_list *lst);

/*SYNTAX ERROR CHECKING FUNCTIONS*/

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

bool	check_backlash(char *str);

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

/*ERROR MANAGER FUNCTIONS*/

/**
 * @brief Manages errors throughout the project after token list creation.
 * @param error_id -> error number defined in enum e_error in this header.
 * @param lst -> the token list.
*/
void	error_manager_parser(int error_id, t_token_list *lst);

/**
 * @brief Manages semicolon and ampersand errors.
 * @param lst -> the token list.
*/
void	syntax_error(t_token_list *lst);

void	command_not_found(t_token_list *lst);

void	parenthesis_error(void);

void	unexpected_token_error(void);

#endif