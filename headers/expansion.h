/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:02 by umeneses          #+#    #+#             */
/*   Updated: 2026/02/18 19:01:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

typedef struct s_new_lex
{
	char				*lex;
	int					idx;
	struct s_new_lex	*next;
	struct s_new_lex	*prev;
}						t_new_lex;

void	expansion_manager(t_token_list *cmd);
int		next_char_counter(t_token_list *cmd);
bool	quotes_detector(t_token_list *cmd);
bool	expansion_parent_dir_detector(char *lex);
char	*expansion_parent_dir_runner(char *lex);
bool	expansion_tilde_detector(char *lexeme);
char	*expansion_tilde_to_home(char *lexeme);
bool	expansion_dollar_sign_detector(t_token_list *cmd);
char	*expansion_env_var_manager(char *lexeme, int type);
char	*expansion_env_var_runner(char **arr_lex, char *lexeme, int idx);
bool	env_var_key_rules_at_start(char c);
bool	env_var_key_rules_at_middle(char c);
char	**array_lex_env_key_rules_manager(char **arr_lex, int arr_len);
char	**apply_rules_on_lex(char **arr_lex, char *lexeme, size_t pos);
char	**expand_var_from_array(char **array_lexeme);
char	**send_approved_var(char **new_arr, char *lexeme);
char	*merging_array_lexeme(char **array_lexeme);
char	**free_runner_for_env_rules_manager(char **arr_lex, char **new_arr);
bool	single_quote_detector(char *lexeme);
char	*single_quote_remover(char *lexeme);
bool	double_quote_detector(char *lexeme);
char	*double_quote_remover(char *lex);
bool	expansion_question_mark_detector(char *lexeme);
char	*expansion_question_mark(char *lexeme);

#endif
