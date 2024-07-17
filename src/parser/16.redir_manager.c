/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17.redir_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:52:43 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/16 10:05:44 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

int	check_redirects(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if ((temp->type == REDIR_IN || temp->type == REDIR_HDOC
				|| temp->type == REDIR_OUT || temp->type == REDIR_OUTAPP))
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	define_archive_token(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if ((temp->type == REDIR_IN || temp->type == REDIR_HDOC
				|| temp->type == REDIR_OUT || temp->type == REDIR_OUTAPP)
			&& (temp->next && temp->next->type == WORD))
			temp->next->type = ARCHIVE;
		temp = temp->next;
	}
}

int	check_words_after_archive(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if ((temp->type == REDIR_IN || temp->type == REDIR_HDOC
				|| temp->type == REDIR_OUT || temp->type == REDIR_OUTAPP))
		{
			if ((temp->next && temp->next->next)
				&& (temp->next->type == ARCHIVE
					&& temp->next->next->type == WORD))
				return (1);
		}
		temp = temp->next;
	}
	return (0);
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
				move(*lst, src_node, dst_node);
			assign_lst_idx(*lst);
		}
		temp = temp->next;
	}
}
