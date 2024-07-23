/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.token_list_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:52:55 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/23 11:14:12 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "error_manager.h"

/**
 * @brief: TODO: remove lst_printer function before submiting.
*/
bool	create_token_list(char *str, t_token_list **lst)
{
	int	idx;

	idx = 0;
	get_state(idx, str, lst);
	ft_lst_printer(*lst);
	assign_lst_idx(*lst);
	if (lst)
		return (true);
	else
		return (false);
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

void	assign_lst_idx(t_token_list *lst)
{
	int				idx;
	t_token_list	*temp;

	idx = 0;
	temp = lst;
	while (temp->next)
	{
		temp->idx = idx;
		idx++;
		temp = temp->next;
	}
}

int	ft_lst_size(t_token_list *lst)
{
	int				size;
	t_token_list	*tmp;

	tmp = lst;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	free_token_list(t_token_list **lst)
{
	t_token_list	*curr;
	t_token_list	*temp;

	curr = *lst;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		if (temp->lexeme)
			free(temp->lexeme);
		free(temp);
	}
}
