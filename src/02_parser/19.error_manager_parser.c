/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19.error_manager_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/23 11:23:45 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_manager_parser(int error_id)
{
	if (error_id == UNEXPECTED_TOKEN)
		unexpected_token_error();
	else if (error_id == SYNTAX_ERROR)
		syntax_error();
	else if (error_id == COMMAND_NOT_FOUND)
		command_not_found();
}

void	unexpected_token_error(void)
{
	ft_putendl_fd("syntax error near unexpected token", STDERR_FILENO);
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
