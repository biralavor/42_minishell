/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17.check_redirects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:52:43 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/01 13:58:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redirect(int lst_type)
{
	if (lst_type == REDIR_IN || lst_type == REDIR_HDOC
		|| lst_type == REDIR_OUT || lst_type == REDIR_OUTAPP)
		return (true);
	return (false);
}

bool	check_redirects(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if (is_redirect(temp->type))
			return (true);
		temp = temp->next;
	}
	return (false);
}

void	define_archive_token(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if ((is_redirect(temp->type))
			&& (temp->next && (temp->next->type == WORD
					|| temp->next->type == DOUBLE_QUOTES
					|| temp->next->type == SINGLE_QUOTES)))
			temp->next->type = ARCHIVE;
		temp = temp->next;
	}
}

void	organize_redirects(t_token_list **lst)
{
	int				dst_idx;
	int				src_idx;
	t_token_list	*temp;
	t_token_list	*src_node;
	t_token_list	*dst_node;

	dst_idx = 0;
	src_idx = -1;
	temp = *lst;
	src_node = NULL;
	dst_node = NULL;
	while (temp)
	{
		src_idx = find_src_idx(*lst);
		if (src_idx != -1)
		{
			dst_idx = find_dst_idx(*lst);
			src_node = find_src_node(*lst, src_idx);
			dst_node = find_dst_node(*lst, dst_idx);
			if (src_node && dst_node && src_node != dst_node)
				move(lst, src_node, dst_node);
			assign_lst_idx(*lst);
		}
		temp = temp->next;
	}
}

void	move(t_token_list **lst, t_token_list *src, t_token_list *dst)
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
			*lst = src;
		src->prev = dst->prev;
		src->next = dst;
		dst->prev = src;
	}
}
