/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.syntax_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:40:35 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/28 11:29:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief: TODO: remove lst_printer function before submiting.
*/
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
	temp = lst;
	if (check_redirects(lst))
		define_archive_token(lst);
	if (check_another_redirect_after_archive(lst))
		organize_redirects(&lst);
	ft_lst_printer(lst);
}

int	syntax_validations(t_token_list *lst)
{
	int	syntax_state;

	syntax_state = 0;
	if (lst->type == WORD)
		syntax_state = state_100(lst, syntax_state);
	else if (lst->type == PIPE || lst->type == OR || lst->type == AND)
		syntax_state = state_200(lst, syntax_state);
	else if (lst->type == REDIR_IN || lst->type == REDIR_HDOC
		|| lst->type == REDIR_OUT || lst->type == REDIR_OUTAPP)
		syntax_state = state_300(lst, syntax_state);
	return (syntax_state);
}

void	check_syntax_state(t_token_list *lst, int syntax_state)
{
	if (syntax_state == 101 || syntax_state == 201 || syntax_state == 301)
	{
		free_token_list(&lst);
		rl_clear_history();
		exit (EXIT_FAILURE);
	}
}
