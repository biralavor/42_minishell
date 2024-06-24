/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state1_to_state5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:17:28 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/24 10:08:54 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	state_1(t_token_list **lst, int idx)
{
	t_token_list	*open_parenthesis_node;

	open_parenthesis_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	open_parenthesis_node->type = OPEN_PARENTHESIS;
	open_parenthesis_node->next = NULL;
	create_new_node(lst, open_parenthesis_node);
	return (idx + 1);
}

int	state_2(t_token_list **lst, int idx)
{
	t_token_list	*close_parenthesis_node;

	close_parenthesis_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	close_parenthesis_node->type = CLOSE_PARENTHESIS;
	close_parenthesis_node->next = NULL;
	create_new_node(lst, close_parenthesis_node);
	return (idx + 1);
}

int	state_3(t_token_list **lst, char curr, char next, int idx)
{
	if (check_next_char(curr, next))
		idx = state_4(lst, idx);
	else
		idx = state_5(lst, idx);
	return (idx);
}

int	state_4(t_token_list **lst, int idx)
{
	t_token_list	*pipe_node;

	pipe_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	pipe_node->type = PIPE;
	pipe_node->next = NULL;
	create_new_node(lst, pipe_node);
	return (idx + 1);
}

int	state_5(t_token_list **lst, int idx)
{
	t_token_list	*or_node;

	or_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	or_node->type = OR;
	or_node->next = NULL;
	create_new_node(lst, or_node);
	return (idx + 2);
}
