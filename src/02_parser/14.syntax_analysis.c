/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14.syntax_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:40:35 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/23 11:16:46 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	syntax_analysis(t_token_list *lst)
{
	int				syntax_state;
	t_token_list	*temp;

	syntax_state = 0;
	temp = lst;
	while (temp)
	{
		syntax_state = syntax_validations(temp);
		if (!check_syntax_state(lst, syntax_state))
			return (false);
		temp = temp->next;
	}
	temp = lst;
	if (check_redirects(lst))
		define_archive_token(lst);
	organize_redirects(&lst);
	return (true);
}

int	syntax_validations(t_token_list *lst)
{
	int	syntax_state;

	syntax_state = 0;
	if (lst->type == WORD)
		syntax_state = state_100(lst, syntax_state);
	else if (lst->type == PIPE || lst->type == OR || lst->type == AND)
		syntax_state = state_200(lst, syntax_state);
	else if (is_redirect(lst->type))
		syntax_state = state_300(lst, syntax_state);
	else if (lst->type == SUBSHELL)
		syntax_state = 400;
	return (syntax_state);
}

bool	check_syntax_state(t_token_list *lst, int syntax_state)
{
	if (syntax_state == 101 || syntax_state == 201 || syntax_state == 301)
	{
		free_token_list(&lst);
		return (false);
	}
	return (true);
}
