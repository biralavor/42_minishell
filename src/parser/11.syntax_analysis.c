/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.syntax_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:40:35 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/05 11:34:46 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

void	syntax_analysis(t_token_list *lst)
{
	int				syntax_state;
	t_token_list	*temp;

	syntax_state = 0;
	temp = lst;
	while (temp)
	{
		syntax_state = syntax_validations(temp);
		check_syntax_state(lst, syntax_state);
		temp = temp->next;
	}
}

int	syntax_validations(t_token_list *lst)
{
	int	syntax_state;

	syntax_state = 0;
	if (lst->type == WORD)
		syntax_state = state_100(lst, syntax_state);
	else if (lst->type == PIPE || lst->type == OR || lst->type == AND)
		syntax_state = state_200(lst, syntax_state);
	else if (lst->type == REDIRECT_INPUT || lst->type == REDIRECT_HEREDOC
		|| lst->type == REDIRECT_OUTPUT
		|| lst->type == REDIRECT_OUTPUT_APPEND)
		syntax_state = state_300(lst, syntax_state);
	else if (lst->type == OPEN_PARENTHESIS || lst->type == CLOSE_PARENTHESIS)
		syntax_state = state_400(lst, syntax_state);
	return (syntax_state);
}

void	check_syntax_state(t_token_list *lst, int syntax_state)
{
	if (syntax_state == 101 || syntax_state == 201 || syntax_state == 301
		|| syntax_state == 401 || syntax_state == 402)
	{
		free_token_list(&lst);
		exit (EXIT_FAILURE);
	}
}
