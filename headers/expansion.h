/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:02 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/28 15:20:52 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

void	expansion_manager(t_token_list *cmd);
bool	expansion_detector(t_token_list *cmd);
bool	expansion_env_variable_detector(char *lexeme);
char	*expansion_env_variable_runner(char *lexeme);

#endif