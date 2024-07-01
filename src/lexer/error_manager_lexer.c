/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_lexer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:01:38 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/01 16:10:07 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"

void	error_manager_lexer(int error_id)
{
	if (error_id == LEXER_ERROR)
		lexer_error();
	else if (error_id == LIST_NOT_CREATED)
		list_not_created();
}

void	lexer_error(void)
{
	ft_printf("Error in first lexer verifications");
	exit (EXIT_FAILURE);
}

void	list_not_created(void)
{
	ft_printf("Error in creating the token list");
	exit(EXIT_FAILURE);
}
