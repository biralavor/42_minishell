/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.state40_to_state60.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:19:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/12 17:04:27 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

int	state_40(t_token_list **lst, int idx, char next)
{
	t_token_list	*and_node;

	and_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	and_node->type = AND;
	and_node->next_char = next;
	create_new_node(lst, and_node);
	return (idx + 2);
}

int	state_50(t_token_list **lst, char curr, char next, int idx)
{
	if (check_next_char(curr, next))
		idx = state_51(lst, idx, next);
	else
		idx = state_52(lst, idx, next);
	return (idx);
}

int	state_51(t_token_list **lst, int idx, char next)
{
	t_token_list	*output_node;

	output_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	output_node->type = REDIR_OUT;
	output_node->next_char = next;
	create_new_node(lst, output_node);
	return (idx + 1);
}

int	state_52(t_token_list **lst, int idx, char next)
{
	t_token_list	*append_node;

	append_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	append_node->type = REDIR_OUTAPP;
	append_node->next_char = next;
	create_new_node(lst, append_node);
	return (idx + 2);
}

int	state_60(t_token_list **lst, char curr, char next, int idx)
{
	if (check_next_char(curr, next))
		idx = state_61(lst, idx, next);
	else
		idx = state_62(lst, idx, next);
	return (idx);
}
