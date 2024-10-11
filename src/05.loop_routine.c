/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.loop_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/11 00:39:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_initial_errors(char *str)
{
	if (!(check_closed_quotes(str))
		|| !(check_closed_parenthesis(str)))
		return (false);
	else
		return (true);
}

bool	heredoc_detector(t_token_list *lst)
{
	t_token_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->type == REDIR_HDOC)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	heredoc_routine(t_token_list *lst)
{
	t_token_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->type == REDIR_HDOC)
		{
			manage_heredoc(tmp);
			if (g_sigmonitor == SIGUSR1
				&& !child_process_is_running(false, true))
			{
				token_list_holder(&lst, true, false);
				return (false);
			}
		}
		tmp = tmp->next;
	}
	return (true);
}

void	loop_routine(char *str)
{
	int				flag;
	t_token_list	*lst;
	t_tree			*token_tree;

	flag = 0;
	lst = NULL;
	token_tree = NULL;
	if (str[0] == '#' || str[0] == '\0')
		return ;
	if (str && !check_initial_errors(str))
	{
		error_manager_lexer(INITIAL_ERROR);
		return ;
	}
	if (str && !create_token_list(str, &lst))
		error_manager_lexer(LIST_NOT_CREATED);
	if (lst && syntax_analysis(lst))
	{
		if (!heredoc_routine(lst))
			return ;
		token_tree = initiate_tree(token_list_holder(NULL, false, false));
		tree_holder(token_tree, false);
		tree_execution(token_tree, &flag);
		free_token_tree(token_tree);
	}
}
