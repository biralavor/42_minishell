/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.syntax_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:40:35 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/04 16:21:33 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

void	syntax_analysis(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		syntax_validations(temp);
		temp = temp->next;
	}
}

void	syntax_validations(t_token_list *lst)
{
	int	syntax_state;

	syntax_state = 0;
	if (lst->type == WORD)
		syntax_state = state_100(lst, syntax_state);
	if (lst->type == PIPE || lst->type == OR || lst->type == AND)
		syntax_state = state_200(lst, syntax_state);
/*	else if (lst->type == REDIRECT_INPUT)
		syntax_state = state_400(lst);
	else if (lst->type == REDIRECT_HEREDOC)
		syntax_state = state_500(lst);
	else if (lst->type == REDIRECT_OUTPUT)
		syntax_state = state_600(lst);
	else if (lst->type == REDIRECT_OUTPUT_APPEND)
		syntax_state = state_700(lst);*/
	else if (lst->type == OPEN_PARENTHESIS || lst->type == CLOSE_PARENTHESIS)
		syntax_state = state_800(lst, syntax_state);
	check_syntax_state(syntax_state, lst);
}

void	check_syntax_state(int syntax_state, t_token_list *lst)
{
	if (syntax_state == 101 || syntax_state == 801 || syntax_state == 802)
	{
		free_token_list(&lst);
		exit (EXIT_FAILURE);
	}
}
