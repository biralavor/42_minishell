/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:17:27 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/16 13:08:46 by tmalheir         ###   ########.fr       */
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
 * @brief Checks for double quoting errors.
 * @param *str -> User input in command line.
*/
bool	check_closed_double_quotes(char *str);

/**
 * @brief Checks for single quoting errors.
 * @param *str -> User input in command line.
*/
bool	check_closed_single_quotes(char *str);

/**
 * @brief Checks for open parenthesis.
 * @param *str -> User input in command line.
*/
bool	check_closed_parenthesis(char *str);

/**
 * @brief Checks if the number of open and close parenthesis token is equal.
 * @param *str -> User input in command line.
 * @param open -> the number of open parenthesis token.
 * @param close -> the number of close parenthesis token.
*/
bool	match_parenthesis(int open, int close);

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

#endif
