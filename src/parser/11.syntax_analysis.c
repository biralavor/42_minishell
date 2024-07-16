/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.syntax_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:40:35 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/16 10:05:52 by tmalheir         ###   ########.fr       */
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
	temp = lst;
	if (check_redirects(lst))
		define_archive_token(lst);
	if (check_words_after_archive(lst))
		organize_redirects(&lst);
	temp = lst;
	while (temp)
	{
		ft_printf("%s\n", temp->lexeme); // APAGAR
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
	else if (lst->type == REDIR_IN || lst->type == REDIR_HDOC
		|| lst->type == REDIR_OUT || lst->type == REDIR_OUTAPP)
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
