/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   37.builtin_detectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:09:05 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/23 09:03:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	builtins_detector(t_token_list *cmd)
{
	while (cmd)
	{
		if ((ft_strncmp(cmd->lexeme, "echo", ft_strlen(cmd->lexeme)) == 0)
			|| (ft_strncmp(cmd->lexeme, "cd", ft_strlen(cmd->lexeme)) == 0)
			|| (ft_strncmp(cmd->lexeme, "pwd", ft_strlen(cmd->lexeme)) == 0))
			return (true);
		cmd = cmd->next;
	}
	return (false);
}

bool	builtins_detector_with_possible_args(t_token_list *lst)
{
	t_token_list	*cmd;

	cmd = lst;
	while (cmd && cmd->type == WORD)
	{
		if ((ft_strncmp(cmd->lexeme, "export", ft_strlen(cmd->lexeme)) == 0)
			|| (ft_strncmp(cmd->lexeme, "unset", ft_strlen(cmd->lexeme)) == 0)
			|| (ft_strncmp(cmd->lexeme, "env", ft_strlen(cmd->lexeme)) == 0)
			|| (ft_strncmp(cmd->lexeme, "exit", ft_strlen(cmd->lexeme)) == 0))
			return (true);
		cmd = cmd->next;
	}
	return (false);
}
