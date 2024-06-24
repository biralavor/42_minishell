/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state11_to_state15.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:35:11 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/24 10:32:55 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	state_11(t_token_list **lst, int idx)
{
	t_token_list	*input_node;

	input_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	input_node->type = REDIRECT_INPUT;
	input_node->next = NULL;
	create_new_node(lst, input_node);
	return (idx + 1);
}

int	state_12(t_token_list **lst, int idx)
{
	t_token_list	*heredoc_node;

	heredoc_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	heredoc_node->type = REDIRECT_HEREDOC;
	heredoc_node->next = NULL;
	create_new_node(lst, heredoc_node);
	return (idx + 2);
}

int	state_13(t_token_list **lst, char *str, int idx)
{
	size_t			start;
	size_t			end;
	char			*double_quotes;
	t_token_list	*double_quotes_node;

	start = (size_t)idx;
	idx++;
	double_quotes_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	while (str[idx] != '"')
		idx++;
	end = (size_t)idx;
	double_quotes = ft_substr((char const *)str, start, ((end - start) + 1));
	double_quotes_node->lexeme = double_quotes;
	double_quotes_node->type = WORD;
	double_quotes_node->next = NULL;
	create_new_node(lst, double_quotes_node);
	return (end + 1);
}

int	state_14(t_token_list **lst, char *str, int idx)
{
	size_t			start;
	size_t			end;
	char			*single_quotes;
	t_token_list	*single_quotes_node;

	start = (size_t)idx;
	idx++;
	single_quotes_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	while (str[idx] != '\'')
		idx++;
	end = (size_t)idx;
	single_quotes = ft_substr((char const *)str, start, ((end - start) + 1));
	single_quotes_node->lexeme = single_quotes;
	single_quotes_node->type = WORD;
	single_quotes_node->next = NULL;
	create_new_node(lst, single_quotes_node);
	return (end + 1);
}

int	state_15(t_token_list **lst, char *str, int idx)
{
	size_t			start;
	size_t			end;
	char			*just_str;
	t_token_list	*just_str_node;

	if (str[idx] == ' ')
		return (idx + 1);
	start = (size_t)idx;
	idx++;
	just_str_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	while ((str[idx] != '(') && (str[idx] != ')') && (str[idx] != '|')
		&& (str[idx] != '&') && (str[idx] != '>') && (str[idx] != '<')
		&& (str[idx] != '"') && (str[idx] != '\'') && (str[idx] != ' ')
		&& (str[idx]))
			idx++;
	end = (size_t)(idx - 1);
	just_str = ft_substr((char const *)str, start, ((end - start) + 1));
	just_str_node->lexeme = just_str;
	just_str_node->type = WORD;
	just_str_node->next = NULL;
	create_new_node(lst, just_str_node);
	return (end + 1);
}
