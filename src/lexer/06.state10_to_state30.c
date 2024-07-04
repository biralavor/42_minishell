/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.state10_to_state30.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:17:28 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:06 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

int	state_10(t_token_list **lst, int idx, char next)
{
	t_token_list	*open_parenthesis_node;

	open_parenthesis_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	open_parenthesis_node->type = OPEN_PARENTHESIS;
	open_parenthesis_node->next_char = next;
	create_new_node(lst, open_parenthesis_node);
	return (idx + 1);
}

int	state_20(t_token_list **lst, int idx, char next)
{
	t_token_list	*close_parenthesis_node;

	close_parenthesis_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	close_parenthesis_node->type = CLOSE_PARENTHESIS;
	close_parenthesis_node->next_char = next;
	create_new_node(lst, close_parenthesis_node);
	return (idx + 1);
}

int	state_30(t_token_list **lst, char curr, char next, int idx)
{
	if (check_next_char(curr, next))
		idx = state_31(lst, idx, next);
	else
		idx = state_32(lst, idx, next);
	return (idx);
}

int	state_31(t_token_list **lst, int idx, char next)
{
	t_token_list	*pipe_node;

	pipe_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	pipe_node->type = PIPE;
	pipe_node->next_char = next;
	create_new_node(lst, pipe_node);
	return (idx + 1);
}

int	state_32(t_token_list **lst, int idx, char next)
{
	t_token_list	*or_node;

	or_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	or_node->type = OR;
	or_node->next_char = next;
	create_new_node(lst, or_node);
	return (idx + 2);
}
