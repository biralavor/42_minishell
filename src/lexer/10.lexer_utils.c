/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/12 15:19:09 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

int	check_next_char(char curr, char next)
{
	if (curr == next)
		return (0);
	else
		return (1);
}

int	is_blank(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\v'))
		return (1);
	else
		return (0);
}

int	ft_lst_size(t_token_list *lst)
{
	int				size;
	t_token_list	*tmp;

	tmp = lst;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	free_token_list(t_token_list **lst)
{
	t_token_list	*curr;
	t_token_list	*temp;

	curr = *lst;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		if (temp->lexeme)
			free(temp->lexeme);
		free(temp);
	}
}

void	assign_lst_idx(t_token_list *lst)
{
	int				idx;
	t_token_list	*temp;

	idx = 0;
	temp = lst;
	while (temp->next)
	{
		temp->idx = idx;
		idx++;
		temp = temp->next;
	}
}
