/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:17:27 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/08 22:33:28 by umeneses         ###   ########.fr       */
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
 * @param str -> User input in command line.
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
void	error_manager_parser(int error_id, t_token_list *lst,
			int syntax_state);

char	*get_metachar_type_as_str(int type);

/**
 * @brief Prints an unexpected token error message.
 * @param lst -> the token list.
*/
void	unexpected_token_error(char *lex);

/**
 * @brief Prints a syntax error message.
 * @param lst -> the token list.
*/
void	syntax_error(void);

#endif
