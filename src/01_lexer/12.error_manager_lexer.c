/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.error_manager_lexer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:01:38 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/20 19:18:34 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	exit_status_holder(1, true);
	return ;
}

void	lexer_error(void)
{
	ft_putendl_fd("lexer error", STDERR_FILENO);
	exit_status_holder(1, true);
	return ;
}

void	list_not_created(void)
{
	ft_putendl_fd("Failed to create token linked list", STDERR_FILENO);
	exit_status_holder(1, true);
	return ;
}
