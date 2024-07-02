/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:18 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/02 07:57:08 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

bool	create_token_list(char *str, t_token_list **lst)
{
	int	idx;

	idx = 0;
	get_state(idx, str, lst);
	ft_lst_printf_content(str, *lst);
	if (lst)
		return (true);
	else
		return (false);
}

void	create_new_node(t_token_list **root, t_token_list *token)
{
	t_token_list	*curr;

	if (*root == NULL)
		*root = token;
	else
	{
		curr = *root;
		while (curr->next)
			curr = curr->next;
		curr->next = token;
	}
}
