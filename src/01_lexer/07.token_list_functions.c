/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.token_list_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:52:55 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/10 17:54:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	create_token_list(char *str, t_token_list **lst)
{
	int	idx;

	idx = 0;
	if (str)
	{
		get_state(idx, str, lst);
		assign_lst_idx(*lst);
	}
	if (lst)
	{
		token_list_holder(lst, true, false);
		return (true);
	}
	else
		return (false);
}

t_token_list	*token_list_holder(t_token_list **lst, bool save, bool clear)
{
	static t_token_list	*token_list_holder = NULL;

	if (save)
		token_list_holder = *lst;
	else if (clear)
		free_token_list(&token_list_holder);
	else if (!save && !clear)
		return (token_list_holder);
	return (NULL);
}

void	create_new_node(t_token_list **root, t_token_list *token)
{
	t_token_list	*curr;

	token->next = NULL;
	if (*root == NULL)
	{
		*root = token;
		token->prev = NULL;
	}
	else
	{
		curr = *root;
		while (curr->next)
			curr = curr->next;
		curr->next = token;
		token->prev = curr;
	}
}
