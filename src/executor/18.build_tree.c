/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18.build_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:55:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/05 14:39:31 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "error_manager.h"

void	build_tree(t_token_list *lst)
{
	t_token_list	*temp;
	t_tree			*exec_tree;

	temp = lst;
	exec_tree = NULL;
	while (temp)
		temp = temp->next;
	while(temp)
	{
		search_logical_operator(temp);
		temp = temp->prev;
	}
}

void	search_logical_operator(t_token_list *lst)
{

}