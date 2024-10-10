/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   37.builtin_detectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:09:05 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 12:40:20 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	builtins_detector(t_token_list *cmd)
{
	while (cmd)
	{
		if (!cmd->lexeme && cmd->next && cmd->next->type == WORD)
			cmd = cmd->next;
		if (cmd->lexeme && ((ft_strcmp(cmd->lexeme, "echo") == 0)
			|| (ft_strcmp(cmd->lexeme, "cd") == 0)
			|| (ft_strcmp(cmd->lexeme, "pwd") == 0)))
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
		if (!cmd->lexeme && cmd->next && cmd->next->type == WORD)
			cmd = cmd->next;
		if ((ft_strcmp(cmd->lexeme, "export") == 0)
			|| (ft_strcmp(cmd->lexeme, "unset") == 0)
			|| (ft_strcmp(cmd->lexeme, "env") == 0)
			|| (ft_strcmp(cmd->lexeme, "exit") == 0))
			return (true);
		cmd = cmd->next;
	}
	return (false);
}
