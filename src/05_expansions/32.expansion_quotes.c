/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32.expansion_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:41:21 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/17 17:20:36 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expansion_quotes_manager(t_token_list *cmd)
{
	char	*new_lexeme;
	int		len;
	t_token_list *tmp;

	len = 1;
	tmp = cmd->prev;
	while (tmp->next_char)
	{
		len += ft_strlen(tmp->lexeme);
		tmp = tmp->next;
	}
	if (tmp->next_char == '\0' || tmp->next_char == ' ')
		len += ft_strlen(tmp->lexeme) - 2;
	new_lexeme = malloc(sizeof(char) * len);
	if (new_lexeme == NULL)
		exit(exit_status_holder(1, true));
	new_lexeme = expansion_inside_quotes_runner(cmd->prev, new_lexeme);
	cmd->lexeme = new_lexeme;
	return (NULL);
}

char	*expansion_inside_quotes_runner(t_token_list *cmd, char *new_lexeme)
{
	int		idx;
	int		idx_new;
	char	quote_type;

	idx = -1;
	idx_new = -1;
	quote_type = '\0';
	if (cmd->next_char)
		expansion_merging_tokens(cmd);
	while (cmd->lexeme[++idx])
	{
		if (quote_type == '\0' && (cmd->lexeme[idx] == '"' || cmd->lexeme[idx] == '\''))
		{
			quote_type = cmd->lexeme[idx];
			idx++;
		}
		if (quote_type == cmd->lexeme[idx])
		{
			quote_type = '\0';
			idx++;
		}
		new_lexeme[++idx_new] = cmd->lexeme[idx];
	}
	new_lexeme[++idx_new] = '\0';
	free(cmd->lexeme);
	return (new_lexeme);
}

void	expansion_merging_tokens(t_token_list *cmd)
{
	char		*last_lex;
	char		*merged_lex;
	t_token_list *tmp;
	t_token_list *saved_ptr;

	tmp = cmd;
	saved_ptr = cmd->prev;
	while(tmp)
	{
		if (tmp->next_char && (tmp->next->next_char == ' '
			|| tmp->next->next_char == '\0'))
			break ;
		tmp = tmp->next;
	}
	while(tmp)
	{
		if (tmp == saved_ptr)
		{
			cmd->lexeme = merged_lex;
			break ;
		}
		if (tmp->lexeme)
		{	
			if (merged_lex)
				last_lex = ft_strjoin(tmp->lexeme, merged_lex);
			else if (tmp->next->lexeme)
				last_lex = ft_strjoin(tmp->lexeme, tmp->next->lexeme);
			free(tmp->lexeme);
			free(tmp->next->lexeme);
			tmp->lexeme = NULL;
			tmp->next->lexeme = NULL;
			tmp->next_char = '\0';
			tmp = tmp->prev;
			if (tmp)
			{
				merged_lex = ft_strjoin(tmp->lexeme, last_lex);
				free(tmp->lexeme);
				tmp = tmp->prev;
			}
			free(last_lex);
		}
	}
}
