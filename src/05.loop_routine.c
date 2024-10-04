/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.loop_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/04 09:08:57 by umeneses         ###   ########.fr       */
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
		check_heredoc(lst);
		token_tree = initiate_tree(lst);
		tree_holder(token_tree, false);
		tree_execution(token_tree, &flag);
		free_token_tree(token_tree);
	}
}
