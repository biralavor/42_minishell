/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   29.manage_single_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:43:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 12:39:39 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_single_command(t_tree *tree)
{
	if (tree->command)
		expansion_manager(tree->command);
	if (!tree->command->lexeme && !tree->command->next)
		return ;
	else if (tree->command && builtins_detector(tree->command))
		builtins_manager(tree->command);
	else if (tree->command
		&& builtins_detector_with_possible_args(tree->command))
		builtins_with_possible_args_manager(tree->command);
	else
		preprocessing_for_command_runner(tree->command);
}

void	preprocessing_for_command_runner(t_token_list *command)
{
	char		**cmd;

	cmd = NULL;
	cmd = convert_tokens_to_array(command);
	if (!cmd)
		exit_status_holder(EXIT_FAILURE, true);
	command_runner(cmd);
	if (exit_status_holder(0, false) == 177
		|| exit_status_holder(0, false) == 126
		|| exit_status_holder(0, false) == 127)
	{
		free_array(cmd);
		return ;
	}
	if (cmd)
		free_array(cmd);
}

char	**convert_tokens_to_array(t_token_list *lst)
{
	int				size;
	int				idx;
	char			**cmd;
	t_token_list	*tmp;

	idx = 0;
	tmp = lst;
	size = ft_lst_size(lst);
	cmd = (char **)ft_calloc(1, sizeof(char *) * (size + 1));
	while (tmp)
	{
		if (tmp->lexeme)
			cmd[idx] = ft_strdup(tmp->lexeme);
		tmp = tmp->next;
		idx++;
	}
	return (cmd);
}
