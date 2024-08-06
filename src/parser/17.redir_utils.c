/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17.redir_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:54:01 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/06 09:59:00 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

int	find_src_idx(t_token_list *lst)
{
	int				src_idx;
	t_token_list	*temp;

	src_idx = -1;
	temp = lst;
	while (temp)
	{
		if ((temp->type == REDIR_IN || temp->type == REDIR_HDOC
				|| temp->type == REDIR_OUT || temp->type == REDIR_OUTAPP))
		{
			if ((temp->next && temp->next->next)
				&& (temp->next->type == ARCHIVE
					&& temp->next->next->type == WORD))
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
		if ((temp->type == REDIR_IN || temp->type == REDIR_HDOC
				|| temp->type == REDIR_OUT || temp->type == REDIR_OUTAPP))
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

void	move(t_token_list *lst, t_token_list *src, t_token_list *dst)
{
	if (lst)
	{
		if (src->next)
		{
			if (src->next->prev)
				src->next->prev = src->prev;
		}
		if (src->next)
			src->prev->next = src->next;
		else
			src->prev->next = NULL;
		if (dst->prev)
			dst->prev->next = src;
		else
			lst = src;
		src->prev = dst->prev;
		src->next = dst;
		dst->prev = src;
	}
}
