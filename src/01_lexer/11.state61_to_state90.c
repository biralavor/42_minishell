/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.state61_to_state90.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:35:11 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/04 11:57:08 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	state_61(t_token_list **lst, int idx, char next)
{
	t_token_list	*input_node;

	input_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	input_node->type = REDIR_IN;
	input_node->next_char = next;
	create_new_node(lst, input_node);
	return (idx + 1);
}

int	state_62(t_token_list **lst, int idx, char next)
{
	t_token_list	*heredoc_node;

	heredoc_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	heredoc_node->type = REDIR_HDOC;
	heredoc_node->next_char = next;
	create_new_node(lst, heredoc_node);
	return (idx + 2);
}

int	state_70(t_token_list **lst, char *str, int idx)
{
	size_t			start;
	size_t			end;
	bool			flag;
	t_token_list	*double_q;

	start = (size_t)idx;
	flag = false;
	double_q = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	end = check_double(str, idx, flag);
	double_q->lexeme = ft_substr((char const *)str,
			start, ((end - start) + 1));
	double_q->type = DOUBLE_QUOTES;
	create_new_node(lst, double_q);
	if (!str[end])
		return (end);
	return (end + 1);
}

int	state_80(t_token_list **lst, char *str, int idx)
{
	size_t			start;
	size_t			end;
	t_token_list	*single;

	start = (size_t)idx;
	idx++;
	single = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	end = check_single(str, idx);
	single->lexeme = ft_substr((char const *)str, start, ((end - start) + 1));
	single->type = SINGLE_QUOTES;
	create_new_node(lst, single);
	return (end + 1);
}

int	state_90(t_token_list **lst, char *str, int idx)
{
	size_t			start;
	size_t			end;
	t_token_list	*just_str_node;

	if (is_blank(str[idx]))
		return (idx + 1);
	start = (size_t)idx;
	idx++;
	just_str_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	while ((str[idx] != '(') && (str[idx] != ')') && (str[idx] != '|')
		&& (str[idx] != '&') && (str[idx] != '>') && (str[idx] != '<')
		&& !(is_blank(str[idx])) && (str[idx]))
		idx++;
	end = (size_t)(idx - 1);
	just_str_node->lexeme = ft_substr((const char *)str, start,
			((end - start) + 1));
	just_str_node->type = WORD;
	create_new_node(lst, just_str_node);
	return (end + 1);
}
