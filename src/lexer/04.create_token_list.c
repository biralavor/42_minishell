/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.create_token_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/07/16 09:35:42 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "lexer.h"

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
