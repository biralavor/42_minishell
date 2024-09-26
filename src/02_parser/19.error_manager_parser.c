/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19.error_manager_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/26 09:26:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_manager_parser(int error_id, char *lex, int syntax_state)
{
	if (error_id == UNEXPECTED_TOKEN)
	{
		if (!lex && syntax_state == 201)
			lex = "|";
		else if (!lex && syntax_state == 301)
			lex = "newline";
		unexpected_token_error(lex);
	}
	else if (error_id == SYNTAX_ERROR)
		syntax_error();
	else if (error_id == COMMAND_NOT_FOUND)
		command_not_found();
}

void	unexpected_token_error(char *lex)
{
	ft_putstr_fd(" syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(lex, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

void	syntax_error(void)
{
	ft_putendl_fd("syntax error.\n", STDERR_FILENO);
	ft_putendl_fd("'\\', '&' or ';' detected\n", STDERR_FILENO);
}

void	command_not_found(void)
{
	ft_putendl_fd("Command not found.\n", STDERR_FILENO);
}
