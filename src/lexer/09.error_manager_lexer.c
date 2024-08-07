/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.error_manager_lexer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:01:38 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/16 12:22:44 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

void	error_manager_lexer(int error_id)
{
	if (error_id == INITIAL_ERROR)
		initial_error();
	else if (error_id == LIST_NOT_CREATED)
		list_not_created();
}

void	initial_error(void)
{
	ft_putendl_fd("Quoting or parenthesis error", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	lexer_error(void)
{
	ft_putendl_fd("lexer error", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	list_not_created(void)
{
	ft_putendl_fd("Failed to create token linked list", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
