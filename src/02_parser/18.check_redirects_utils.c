/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18.check_redirects_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:54:01 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/27 10:19:32 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_src_idx(t_token_list *lst)
{
	int				src_idx;
	t_token_list	*temp;

	src_idx = -1;
	temp = lst;
	while (temp)
	{
		if (is_redirect(temp->type))
		{
			if ((temp->next && temp->next->next)
				&& (temp->next->type == ARCHIVE)
					&& (temp->next->next->type == WORD
					|| temp->next->next->type == DOUBLE_QUOTES
					|| temp->next->next->type == SINGLE_QUOTES))
			{
				src_idx = temp->next->next->idx;
				break ;
			}
		}
		temp = temp->next;
	}
	return (src_idx);
}

int	find_dst_idx(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if (is_redirect(temp->type))
			break ;
		temp = temp->next;
	}
	return (temp->idx);
}

t_token_list	*find_src_node(t_token_list *lst, int src_idx)
{
	t_token_list	*temp;

	temp = lst;
	while (temp && temp->idx < src_idx)
		temp = temp->next;
	return (temp);
}

t_token_list	*find_dst_node(t_token_list *lst, int dst_idx)
{
	t_token_list	*temp;

	temp = lst;
	while (temp && temp->idx < dst_idx)
		temp = temp->next;
	return (temp);
}
