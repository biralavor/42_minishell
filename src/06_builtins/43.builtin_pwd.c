/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   43.builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/11 02:43:20 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_pwd(t_token_list *lst)
{
	t_token_list	*cmd;
	char			*actual_path;

	cmd = lst;
	actual_path = NULL;
	if (cmd && cmd->type == WORD)
	{
		actual_path = getcwd(actual_path, 100);
		ft_putstr_fd(actual_path, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	free(actual_path);
}
