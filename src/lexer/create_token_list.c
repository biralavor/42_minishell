/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:18 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/26 13:37:36 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	create_token_list(char *str)
{
	int				idx;
	t_token_list	*lst;

	idx = 0;
	lst = NULL;
	get_state(idx, str, &lst);
	ft_lst_printf_content(str, lst);
	free_token_list(&lst);
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
