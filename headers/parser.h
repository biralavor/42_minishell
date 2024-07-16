/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/16 10:06:01 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*SYNTAX VALIDATIONS FUNCTIONS*/

/**
 * @brief Checks each node of the token list calling for syntax_validation.
 * @param *lst -> The token list.
*/
void			syntax_analysis(t_token_list *lst);

/**
 * @brief Checks for any grammar errors.
 * @param *lst -> The token list.
*/
int				syntax_validations(t_token_list *lst);

int				check_redirects(t_token_list *lst);

/**
 * @brief Checks if there are any redirects and changes next token type.
 * @param *lst -> The token list.
*/
void			define_archive_token(t_token_list *lst);

int				check_words_after_archive(t_token_list *lst);

void			organize_redirects(t_token_list **lst);

int				find_src_idx(t_token_list *lst);

int				find_dst_idx(t_token_list *lst);

t_token_list	*find_src_node(t_token_list *lst, int src_idx);

t_token_list	*find_dst_node(t_token_list *lst, int dst_idx);

void			move(t_token_list *lst, t_token_list *src, t_token_list *dst);

/**
 * @brief Checks the grammar rules associated with the respective token.
 * @param *lst -> The token list.
 * @param syntax_state -> a number that indicates if there is a grammar error.
*/
void			check_syntax_state(t_token_list *lst, int syntax_state);

int				state_100(t_token_list *lst, int syntax_state);
int				state_200(t_token_list *lst, int syntax_state);
int				state_300(t_token_list *lst, int syntax_state);
int				state_400(t_token_list *lst, int syntax_state);
int				state_401(t_token_list *lst);
int				state_402(t_token_list *lst);

/**
 * @brief Checks if the number of open and close parenthesis token is equal.
 * @param open_par -> the number of open parenthesis token.
 * @param close_par -> the number of close parenthesis token.
 * @param *lst -> The token list.
*/
int				match_parenthesis(int open, int close, t_token_list *lst);

/*SYNTAX ERROR CHECKING FUNCTIONS*/

/**
 * @brief Check for single ampersand, semicolon and backlash.
 * @param *lst -> the token list.
*/
bool			check_lexeme(t_token_list *lst);

/**
 * @brief Auxiliar function to check for single &, semicolon and backlash.
 * @param *str -> User input in command line.
*/
bool			check_lexeme_errors(char *str);

/**
 * @brief Check for backlash.
 * @param *str -> User input in command line.
*/
bool			check_backlash(char *str);

/**
 * @brief Check for single ampersand error.
 * @param *str -> User input in command line.
*/
bool			check_double_ampersand(char *str);

/**
 * @brief Check for semicolon.
 * @param *str -> User input in command line.
*/
bool			check_semicolon(char *str);

/**
 * @brief Check for not closed quotes.
 * @param *lst -> the token list.
*/
bool			check_quotes(t_token_list *lst);

/**
 * @brief Check for empty quotes.
 * @param *str -> User input in command line.
*/
bool			check_empty_quotes(char *str);

/*ERROR MANAGER FUNCTIONS*/

/**
 * @brief Manages errors throughout the project after token list creation.
 * @param error_id -> error number defined in enum e_error in this header.
 * @param lst -> the token list.
*/
void			error_manager_parser(int error_id, t_token_list *lst);

void			syntax_error(t_token_list *lst);
void			command_not_found(t_token_list *lst);
void			parenthesis_error(void);
void			unexpected_token_error(void);

#endif