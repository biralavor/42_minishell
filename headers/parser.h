/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/10 23:54:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*SYNTAX VALIDATIONS FUNCTIONS*/

/**
 * @brief Checks each node of the token list calling for syntax_validation.
 * @param lst -> The token list.
*/
bool			syntax_analysis(t_token_list *lst);

/**
 * @brief Checks for any grammar errors.
 * @param lst -> The token list.
*/
int				syntax_validations(t_token_list *lst);

/**
 * @brief Checks the grammar rules associated with the respective token.
 * @param lst          -> The token list.
 * @param syntax_state -> a number that indicates if there is a grammar error.
*/
bool			check_syntax_state(t_token_list *lst, int syntax_state);

int				state_100(t_token_list *lst, int syntax_state);
int				state_200(t_token_list *lst, int syntax_state);
int				state_300(t_token_list *lst, int syntax_state);

/*SYNTAX ERROR CHECKING FUNCTIONS*/

/**
 * @brief Auxiliar function to check for single &, semicolon and backlash.
 * @param str -> User input in command line.
*/
bool			check_lexeme_errors(char *str);

/**
 * @brief Check for backlash.
 * @param str -> User input in command line.
*/
bool			check_backlash(char *str);

/**
 * @brief Check for single ampersand error.
 * @param str -> User input in command line.
*/
bool			check_double_ampersand(char *str);

/**
 * @brief Check for semicolon.
 * @param str -> User input in command line.
*/
bool			check_semicolon(char *str);

/*CHECK_REDIRECTS*/

bool			is_redirect(int lst_type);

/**
 * @brief Checks if there are any redirect tokens.
 * @param lst -> The token list.
*/
bool			check_redirects(t_token_list *lst);

/**
 * @brief Redefines token type after any redirect from word to archive.
 * @param lst -> The token list.
*/
void			define_archive_token(t_token_list *lst);

/**
 * @brief Organize redirects in a way they behave like in Bash.
 * @param lst -> The token list.
*/
void			organize_redirects(t_token_list **lst);

/**
 * @brief Moves the source token.
 * @param lst -> The token list.
*/
void			move(t_token_list **lst, t_token_list *src, t_token_list *dst);

/*CHECK_REDIRECTS_UTILS*/

/**
 * @brief Finds the index of the token to be moved.
 * @param lst -> The token list.
*/
int				find_src_idx(t_token_list *lst);

/**
 * @brief Finds the index to where the token is to be moved to.
 * @param lst -> The token list.
*/
int				find_dst_idx(t_token_list *lst);

/**
 * @brief Returns a pointer to the token to be moved.
 * @param lst -> The token list.
*/
t_token_list	*find_src_node(t_token_list *lst, int src_idx);

/**
 * @brief Returns a pointer to the token destiny.
 * @param lst -> The token list.
*/
t_token_list	*find_dst_node(t_token_list *lst, int dst_idx);

bool			heredoc_detector(t_token_list *lst);
void			manage_heredoc(t_token_list *lst);
void			path_file(t_token_list *lst);
bool			eof_del_manager(char *delimiter, int fd);
bool			eof_ending_process(char *input, char *delimiter,
					int line, int fd);

void			heredoc_fd_reset(int *heredoc_fd);
bool			is_heredoc_running(bool update, bool caller);
void			heredoc_forcing_exit_warning(char *input, char *delimiter,
					int line, int fd);

void			dollarsign_heredoc_init(char *input, int fd);
int				dollarsign_for_heredoc_manager(char *input, int idx, int fd);
int				dollarsign_for_heredoc_runner(char *input, int idx,
					size_t start, int fd);
int				check_question_mark_for_heredoc(int idx, int fd);
bool			hd_fd_error_runner(int heredoc_fd);
bool			is_demiliter_null(char *delimiter);
bool			is_signal_sigint(int heredoc_fd);
void			heredoc_cleanup(int hd_fd, int original_stdin, char *eof_del);

#endif