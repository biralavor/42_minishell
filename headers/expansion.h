/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:02 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/11 15:57:00 by umeneses         ###   ########.fr       */
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
// bool	expansion_detector_at_start(t_token_list *cmd);
// bool	expansion_env_var_detector_at_start(char lexeme_char_pos);
// char	*expansion_env_var_runner_at_start(char *lexeme);

bool	expansion_quotes_detector(t_token_list *cmd);
char	*expansion_quotes_runner(char *lexeme);
char	*expansion_new_lexeme_after_quotes(char *lexeme, char *new_lexeme);

bool	expansion_tilde_detector(char *lexeme);
char	*expansion_tilde_to_home(char *lexeme);

bool	expansion_dollar_sign_detector(t_token_list *cmd);
char	*expansion_env_var_runner(char *lexeme);
bool	expansion_env_var_detector(char *lexeme);
bool	env_var_key_rules_at_start(char c);
bool	env_var_key_rules_at_middle(char c);
char	**array_lex_env_key_rules_manager(char **array_lexeme);
char	**apply_rules_on_lex(char **arr_lex, char *lexeme, size_t pos);
char	*merging_array_lexeme(char **array_lexeme);
char	**expand_var_from_array(char **array_lexeme);

bool	expansion_question_mark_detector(char *lexeme);
char	*expansion_question_mark(char *lexeme);

#endif