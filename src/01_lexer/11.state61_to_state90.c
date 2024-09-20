/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.state61_to_state90.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:35:11 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/20 10:14:23 by umeneses         ###   ########.fr       */
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
	char			*double_quotes;
	t_token_list	*double_quotes_node;
	bool			quote_detected;

	quote_detected = false;
	start = (size_t)idx;
	double_quotes_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	while (str[idx])
	{
		if ((str[idx - 1] && str[idx - 1] == ' ' && str[idx] == '"') || idx == 0)
		{
			ft_memmove(&str[idx], &str[idx + 1], ft_strlen(&str[idx + 1]) + 1);
			quote_detected = true;
		}
		else if (quote_detected && str[idx] == '"' && str[idx + 1] == '\0')
		{
			ft_memmove(&str[idx], &str[idx + 1], ft_strlen(&str[idx + 1]) + 1);
			quote_detected = false;
		}
		idx++;
	}
	end = (size_t)idx;
	double_quotes = ft_strdup((const char *)str + start);
	double_quotes_node->lexeme = double_quotes;
	double_quotes_node->type = DOUBLE_QUOTES;
	double_quotes_node->next_char = str[end + 1];
	create_new_node(lst, double_quotes_node);
	return (end + 1);
}

int	state_80(t_token_list **lst, char *str, int idx)
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
	single_quotes_node->type = SINGLE_QUOTES;
	single_quotes_node->next_char = str[end + 1];
	create_new_node(lst, single_quotes_node);
	return (end + 1);
}

int	state_90(t_token_list **lst, char *str, int idx)
{
	size_t			start;
	size_t			end;
	char			*just_str;
	t_token_list	*just_str_node;

	if (is_blank(str[idx]))
		return (idx + 1);
	start = (size_t)idx;
	idx++;
	just_str_node = (t_token_list *)ft_calloc(1, sizeof(t_token_list));
	while ((str[idx] != '(') && (str[idx] != ')') && (str[idx] != '|')
		&& (str[idx] != '&') && (str[idx] != '>') && (str[idx] != '<')
		&& (str[idx] != '"') && (str[idx] != '\'') && !(is_blank(str[idx]))
		&& (str[idx]))
		idx++;
	end = (size_t)(idx - 1);
	just_str = ft_substr((const char *)str, start, ((end - start) + 1));
	just_str_node->lexeme = just_str;
	just_str_node->type = WORD;
	just_str_node->next_char = str[end + 1];
	create_new_node(lst, just_str_node);
	return (end + 1);
}
