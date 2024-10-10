/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.token_list_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:52:55 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/10 18:20:27 by umeneses         ###   ########.fr       */
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
		token_list_holder = go_to_first_node(*lst);
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

void	assign_lst_idx(t_token_list *lst)
{
	int				idx;
	t_token_list	*temp;

	idx = 0;
	temp = lst;
	while (temp)
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
	*lst = NULL;
}
