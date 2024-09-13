/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.manage_single_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:43:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/12 18:54:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_single_command(t_tree *tree)
{
	static int	exit_status;
	char		**cmd;

	cmd = NULL;
	expansion_manager(tree->command);
	if (builtins_detector(tree->command))
		builtins_manager(tree->command);
	else if (builtins_detector_with_possible_args(tree->command))
		builtins_with_possible_args_manager(tree->command);
	else
	{
		cmd = convert_tokens_to_array(tree->command);
		if (!cmd)
		{
			exit_status = 1; // trocar por exit_holder
			return (exit_status);
		}
		exit_status = command_runner(cmd); // trocar por exit_holder
	}
	// verify if !cmd[0]
	// verify exit_status_holder()
	// verify SIGINT
	return (exit_status);
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
		cmd[idx] = ft_strdup(tmp->lexeme);
		tmp = tmp->next;
		idx++;
	}
	return (cmd);
}
