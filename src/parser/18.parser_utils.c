/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18.parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:54:01 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/12 18:58:22 by tmalheir         ###   ########.fr       */
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
			&& temp->next->type == WORD)
			temp->next->type = ARCHIVE;
		temp = temp->next;
	}
}

int	check_words_after_redir(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if ((temp->type == REDIR_IN || temp->type == REDIR_HDOC
				|| temp->type == REDIR_OUT || temp->type == REDIR_OUTAPP))
		{
			if (temp->next->type == ARCHIVE && temp->next->next->type == WORD)
				return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void	organize_redirects(t_token_list **lst)
{
	int				target_pos;
	int				original_pos;
	t_token_list	*temp;

	target_pos = 0;
	original_pos = 0;
	temp = *lst;
	while (temp)
	{
		if (temp->type == REDIR_IN || temp->type == REDIR_HDOC
				|| temp->type == REDIR_OUT || temp->type == REDIR_OUTAPP)
				target_pos = update_target_pos(*lst);
		if (target_pos != 0 && temp->idx >= original_pos && temp->type == WORD)
		{
			if (temp->prev->type == ARCHIVE || temp->prev->type == WORD)
			{
				original_pos = temp->idx;
				move_node(*lst, target_pos, original_pos);
			}
		}
		temp = temp->next;
	}
}

int	update_target_pos(t_token_list *lst)
{
	int				target_pos;
	t_token_list	*temp;

	target_pos = 0;
	temp = lst;
	while (temp)
	{
		if (temp->type == REDIR_IN || temp->type == REDIR_HDOC
				|| temp->type == REDIR_OUT || temp->type == REDIR_OUTAPP)
		{
			target_pos = temp->idx;
			break ;
		}
		temp = temp->next;
	}
	return (target_pos);
}

void	move_node(t_token_list *lst, int target_pos, int original_pos)
{
	t_token_list	*temp;
	t_token_list	*from_node;
	t_token_list	*to_node;

	from_node = NULL;
	to_node = NULL;
	temp = lst;
	while (temp && temp->idx < original_pos)
		temp = temp->next;
	from_node = temp;
	from_node->prev->next = from_node->next;
	temp = lst;
	while (temp && temp->idx < target_pos)
		temp = temp->next;
	to_node = temp;
	if (to_node->prev)
		to_node->prev->next = from_node;
	from_node->prev = to_node->prev;
	from_node->next = to_node;
	to_node->prev = from_node;
	assign_lst_idx(lst);
}
