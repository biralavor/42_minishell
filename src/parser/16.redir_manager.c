/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16.redir_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:52:43 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/04 10:44:56 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			&& (temp->next && temp->next->type == WORD))
			temp->next->type = ARCHIVE;
		temp = temp->next;
	}
}

bool	check_words_after_archive(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp->next && temp->type != ARCHIVE)
	{
		temp = temp->next;
		if (temp->type == ARCHIVE)
		{
			while (temp->next)
			{
				temp = temp->next;
				if (temp->type == WORD)
					return (true);
			}
		}
	}
	return (false);
}

bool	check_another_redirect_after_archive(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	if (check_words_after_archive(lst))
	{
		while (temp->next && temp->type != ARCHIVE)
		{
			temp = temp->next;
			if (temp->type == ARCHIVE)
			{
				while (temp->next)
				{
					if (is_redirect(temp->type))
						return (true);
					temp = temp->next;
				}
			}
		}
	}
	return (false);
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
