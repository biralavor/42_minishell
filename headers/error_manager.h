/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:17:27 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/16 15:54:43 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGER_H
# define ERROR_MANAGER_H

enum e_error
{
	INITIAL_ERROR,
	LEXER_ERROR,
	LIST_NOT_CREATED,
	UNEXPECTED_TOKEN,
	SYNTAX_ERROR,
	COMMAND_NOT_FOUND,
	PARENTHESIS_ERROR
};

/*INITIAL ERROR MANAGER FUNCTION*/

/**
 * @brief Calls for initial error checking functions.
 * @param *str -> User input in command line.
*/
bool	check_initial_errors(char *str);

/*LEXER ERROR MANAGER FUNCTIONS*/

/**
 * @brief Manages errors throughout the project before token list creation.
 * @param error_id -> error number defined in enum e_error in this header.
*/
void	error_manager_lexer(int error_id);

/**
 * @brief Indicates error in initial lexer quoting and parenthesis verifications.
*/
void	initial_error(void);

/**
 * @brief Indicates other lexer errors.
*/
void	lexer_error(void);

/**
 * @brief Indicates error in token list creation.
*/
void	list_not_created(void);

/*PARSER ERROR MANAGER FUNCTIONS*/

/**
 * @brief Manages errors throughout the project after token list creation.
 * @param error_id -> error number defined in enum e_error in this header.
 * @param lst -> the token list.
*/
void	error_manager_parser(int error_id, t_token_list *lst);

/**
 * @brief Prints an unexpected token error message.
 * @param lst -> the token list.
*/
void	unexpected_token_error(void);

/**
 * @brief Prints a syntax error message.
 * @param lst -> the token list.
*/
void	syntax_error(t_token_list *lst);

/**
 * @brief Prints a command not found error message.
 * @param lst -> the token list.
*/
void	command_not_found(t_token_list *lst);

#endif
