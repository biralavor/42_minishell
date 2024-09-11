/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:02 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/11 11:23:48 by umeneses         ###   ########.fr       */
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
bool	expansion_detector_at_start(t_token_list *cmd);
bool	expansion_env_var_detector_at_start(char lexeme_char_pos);
char	*expansion_env_var_runner_at_start(char *lexeme);
bool	expansion_question_mark_detector(char lexeme_char_pos);
char	*expansion_question_mark(char *lexeme);

bool	expansion_detector_at_middle(t_token_list *cmd);
bool	expansion_env_var_detector_at_middle(t_token_list *cmd);
char	*expansion_env_var_runner_at_middle(char *lexeme);
bool	expansion_quotes_detector_at_middle(t_token_list *cmd);
char	*expansion_quotes_runner_at_middle(char *lexeme);
char	*expansion_new_lexeme_after_quotes(char *lexeme, char *new_lexeme);
bool	expansion_tilde_detector(char *lexeme);
char	*expansion_tilde_to_home(char *lexeme);

char	*copy_var_name(char *lexeme);
char	**array_lex_env_name_convention(char **array_lexeme);
char	*merging_array_lexeme(char **array_lexeme);
char	**expand_var_from_array(char **array_lexeme);
bool	env_var_name_convention_at_start(char c);
bool	env_var_name_convention_at_middle(char c);

#endif