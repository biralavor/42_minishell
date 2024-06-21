/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:18 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/21 10:41:15 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_token_list(char *str)
{
	int				idx;
	t_token_list	*lst;

	idx = 0;
	lst = NULL;
	get_state(idx, str, &lst);
	// Apagar esta função quando o projeto estiver finalizado.
	ft_lst_printf_content(str, lst);
}

void	create_new_node(t_token_list **root, t_token *token)
{
	t_token_list	*new_node;
	t_token_list	*curr;

	new_node = (t_token_list *)malloc(sizeof(t_token_list));
	if (!new_node)
	{
		ft_printf("Malloc error");
		exit (EXIT_FAILURE);
	}
	new_node->token = token;
	new_node->next = NULL;
	if (*root == NULL)
		*root = new_node;
	else
	{
		curr = *root;
		while (curr->next)
			curr = curr->next;
		curr->next = new_node;
	}
}
