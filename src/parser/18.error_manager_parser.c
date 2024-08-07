/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18.error_manager_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/18 12:38:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

void	error_manager_parser(int error_id, t_token_list *lst)
{
	if (error_id == UNEXPECTED_TOKEN)
		unexpected_token_error();
	else if (error_id == SYNTAX_ERROR)
		syntax_error(lst);
	else if (error_id == COMMAND_NOT_FOUND)
		command_not_found(lst);
}

void	unexpected_token_error(void)
{
	ft_putendl_fd("syntax error near unexpected token", STDERR_FILENO);
}

void	syntax_error(t_token_list *lst)
{
	ft_putendl_fd("syntax error.\n", STDERR_FILENO);
	ft_putendl_fd("'\\', '&' or ';' detected\n", STDERR_FILENO);
	free_token_list(&lst);
}

void	command_not_found(t_token_list *lst)
{
	ft_printf("Command not found.\n");
	free_token_list(&lst);
	exit (EXIT_FAILURE);
}
