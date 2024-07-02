/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/01 22:34:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

void	error_manager_parser(int error_id, t_token_list *lst)
{
	if (error_id == UNEXPECTED_TOKEN)
		unexpected_token_error(lst);
	else if (error_id == SYNTAX_ERROR)
		syntax_error(lst);
	else if (error_id == COMMAND_NOT_FOUND)
		command_not_found(lst);
	else if (error_id == PARENTHESIS_ERROR)
		parenthesis_error(lst);
}

void	unexpected_token_error(t_token_list *lst)
{
	if (lst->type == 1)
		ft_printf("syntax error near unexpected token '|' \n");
	else if (lst->type == 6)
		ft_printf("syntax error near unexpected token '||' \n");
	else if (lst->type == 7)
		ft_printf("syntax error near unexpected token '&&' \n");
	else if (lst->type == 9)
		ft_printf("syntax error near unexpected token ')' \n");
	free_token_list(&lst);
	exit (EXIT_FAILURE);
}

void	syntax_error(t_token_list *lst)
{
	ft_printf("syntax error.\n");
	free_token_list(&lst);
	exit (EXIT_FAILURE);
}

void	command_not_found(t_token_list *lst)
{
	ft_printf("Command '' not found.\n");
	free_token_list(&lst);
	exit (EXIT_FAILURE);
}

void	parenthesis_error(t_token_list *lst)
{
	char			*unexpected_token;
	t_token_list	*temp;

	unexpected_token = NULL;
	temp = lst;
	while (temp)
	{
		if (temp->type == OPEN_PARENTHESIS && temp->next->type == WORD)
		{
			unexpected_token = ft_strdup(temp->next->lexeme);
			break ;
		}
		else if (temp->type == OPEN_PARENTHESIS && temp->next->type != WORD)
		{
			unexpected_token = check_next_token(temp->next->type);
			break ;
		}
		temp = temp->next;
	}
	ft_printf("syntax error near unexpected token %s\n", unexpected_token);
	free(unexpected_token);
	free_token_list(&lst);
	exit (EXIT_FAILURE);
}
