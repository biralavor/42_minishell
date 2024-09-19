/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.token_list_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:52:55 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/19 19:52:41 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	inside_quotes_detector(char *str);

bool	create_token_list(char *str, t_token_list **lst)
{
	int	idx;

	idx = 0;
	if (inside_quotes_detector(str) && check_closed_quotes(str))
		str = update_str_if_inside_quotes(str);
	get_state(idx, str, lst);
	assign_lst_idx(*lst);
	if (lst)
		return (true);
	else
		return (false);
}

char	*update_str_if_inside_quotes(char *str)
{
	int		idx;
	char	quote_type;

	idx = 0;
	quote_type = '\0';
	while(str[idx])
	{
		if (quote_type == '\0' && str[idx - 1] && str[idx - 1] != ' '
			&& (str[idx] == '"' || str[idx] == '\''))
		{
			quote_type = str[idx];
			ft_memmove(&str[idx], &str[idx + 1], ft_strlen(&str[idx + 1]) + 1);
		}
		if (quote_type == str[idx])
		{
			quote_type = '\0';
			ft_memmove(&str[idx], &str[idx + 1], ft_strlen(&str[idx + 1]) + 1);
		}
		idx++;
	}
	if (inside_quotes_detector(str) && check_closed_quotes(str))
		update_str_if_inside_quotes(str);
	return (str);
}

static bool	inside_quotes_detector(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (((str[idx - 1] && str[idx - 1] == ' ') || idx == 0)
			&&  (str[idx] == '"' || str[idx] == '\''))
			return (false);
		else if (str[idx - 1] && str[idx - 1] == '='
			&&  (str[idx] == '"' || str[idx] == '\''))
			return (false);
		else if (str[idx - 1] && str[idx - 1] == '\'' &&  str[idx] == '$')
			return (false);
		else if ((str[idx] == '"' || str[idx] == '\'') && str[idx - 1] != ' '
			&& str[idx + 1] != '$' && str[idx + 1] != '\0')
			return (true);
		idx++;
	}
	return (false);
}

void	create_new_node(t_token_list **root, t_token_list *token)
{
	t_token_list	*curr;

	token->next = NULL;
	if (*root == NULL)
	{
		*root = token;
		token->prev = NULL;
	}
	else
	{
		curr = *root;
		while (curr->next)
			curr = curr->next;
		curr->next = token;
		token->prev = curr;
	}
}

void	assign_lst_idx(t_token_list *lst)
{
	int				idx;
	t_token_list	*temp;

	idx = 0;
	temp = lst;
	while (temp)
	{
		temp->idx = idx;
		idx++;
		temp = temp->next;
	}
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
	temp = NULL;
}
