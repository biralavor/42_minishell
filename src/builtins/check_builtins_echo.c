/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins_echo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 16:43:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "builtins.h"

void	builtins_runner_echo(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	if (NULL == temp->next)
		write(1, "\n", 1);
	else
	{
		if (check_command_args(lst, 'n'))
			temp = temp->next->next;
		while (temp->type == WORD)
		{
			ft_putstr_fd(temp->lexeme, STDOUT_FILENO);
			if (NULL == temp->next)
				break ;
			else
				ft_putstr_fd(" ", STDOUT_FILENO);
			temp = temp->next;
		}
		if (!check_command_args(lst, 'n'))
			write(1, "\n", 1);
	}
}

bool	check_command_args(t_token_list *lst, char arg)
{
	t_token_list	*temp;

	temp = lst;
	if (temp->next->lexeme[0] == '-')
	{
		if (temp->next->lexeme[1] == arg)
			return (true);
	}
	return (false);
}
