/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins_pwd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 14:53:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "builtins.h"

void	builtins_runner_pwd(t_token_list *lst)
{
	t_token_list	*temp;
	char			*actual_path;

	temp = lst;
	actual_path = NULL;
	if (temp && temp->type == WORD)
	{
		actual_path = getcwd(actual_path, 100);
		ft_putstr_fd(actual_path, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}
