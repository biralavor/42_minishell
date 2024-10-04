/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30.expansion_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/04 14:16:02 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*quote_detector(t_token_list *lst, char *lexeme, int *flag)
{
	int		idx;

	idx = 0;
	while (lexeme[idx])
	{
		if (lexeme[idx] == '\'')
		{
			*flag = 1;
			return (lst->lexeme = single_quote_remover(lst->lexeme));
		}
		else if (lexeme[idx] == '"')
			return (lst->lexeme = double_quote_remover(lst->lexeme));
		idx++;
	}
	return (lst->lexeme);
}

void	expansion_manager(t_token_list *cmd)
{
	int				flag;
	t_token_list	*tmp;

	flag = 0;
	tmp = cmd;
	while (tmp != NULL)
	{
		tmp->lexeme = quote_detector(tmp, tmp->lexeme, &flag);
		if (!flag)
		{
			if (expansion_tilde_detector(tmp->lexeme))
				tmp->lexeme = expansion_tilde_to_home(tmp->lexeme);
			if (expansion_dollar_sign_detector(tmp))
			{
				if (expansion_question_mark_detector(tmp->lexeme))
					tmp->lexeme = expansion_question_mark(tmp->lexeme);
				if (expansion_dollar_sign_detector(tmp))
					tmp->lexeme = expansion_env_var_runner(tmp->lexeme,
							tmp->type);
			}
		}
		tmp = tmp->next;
	}
}

int	next_char_counter(t_token_list *cmd)
{
	t_token_list	*tmp;
	int				idx;

	tmp = cmd;
	idx = 0;
	while (tmp)
	{
		if (tmp->next_char == '\0')
			break ;
		if (tmp->next_char != ' ')
			idx++;
		tmp = tmp->next;
	}
	return (idx);
}
