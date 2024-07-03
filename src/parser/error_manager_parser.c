/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/02 14:50:38 by tmalheir         ###   ########.fr       */
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
	ft_printf("syntax error near unexpected token\n");
	free_token_list(&lst);
	exit (EXIT_FAILURE);
}

void	syntax_error(t_token_list *lst)
{
	ft_printf("Syntax error\n");
	free_token_list(&lst);
	exit (EXIT_FAILURE);
}

void	command_not_found(t_token_list *lst)
{
	ft_printf("Command not found.\n");
	free_token_list(&lst);
	exit (EXIT_FAILURE);
}

void	parenthesis_error(t_token_list *lst)
{
	ft_printf("Unmatched open parenthesis");
	free_token_list(&lst);
	exit (EXIT_FAILURE);
}
