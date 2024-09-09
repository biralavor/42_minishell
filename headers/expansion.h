/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:02 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 10:04:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

void	expansion_manager(t_token_list *cmd);
bool	expansion_detector_at_start(t_token_list *cmd);
bool	expansion_detector_at_middle(t_token_list *cmd);
bool	expansion_env_variable_detector(char lexeme_char_pos);
char	*expansion_env_variable_runner_at_start(char *lexeme);
bool	expansion_question_mark_detector(char lexeme_char_pos);
char	*expansion_question_mark(char *lexeme);

#endif