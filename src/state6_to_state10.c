/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state6_to_state10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:19:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/20 16:07:38 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	state_6(t_token_list **lst, int idx)
{
	t_token	*and_node;

	and_node = (t_token *)ft_calloc(1, sizeof(t_token));
	and_node->type = AND;
	create_new_node(lst, and_node);
	return (idx + 2);
}

int	state_7(t_token_list **lst, char curr, char next, int idx)
{
	if (check_next_char(curr, next))
		idx = state_8(lst, idx);
	else
		idx = state_9(lst, idx);
	return (idx);
}

int	state_8(t_token_list **lst, int idx)
{
	t_token	*output_node;

	output_node = (t_token *)ft_calloc(1, sizeof(t_token));
	output_node->type = REDIRECT_OUTPUT;
	create_new_node(lst, output_node);
	return (idx + 1);
}

int	state_9(t_token_list **lst, int idx)
{
	t_token	*append_node;

	append_node = (t_token *)ft_calloc(1, sizeof(t_token));
	append_node->type = REDIRECT_OUTPUT_APPEND;
	create_new_node(lst, append_node);
	return (idx + 2);
}

int	state_10(t_token_list **lst, char curr, char next, int idx)
{
	if (check_next_char(curr, next))
		idx = state_11(lst, idx);
	else
		idx = state_12(lst, idx);
	return (idx);
}
