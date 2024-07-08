/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.error_manager_lexer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:01:38 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/08 20:25:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

void	error_manager_lexer(int error_id)
{
	if (error_id == LEXER_ERROR)
		lexer_error();
	else if (error_id == LIST_NOT_CREATED)
		list_not_created();
}

void	lexer_error(void)
{
	ft_putendl_fd("Unmatched open quotes", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	list_not_created(void)
{
	ft_putendl_fd("Failed to create token linked list", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
