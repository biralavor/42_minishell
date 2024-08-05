/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21.environ_detector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:40:05 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/05 16:40:52 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "error_manager.h"

bool variable_detector(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while(temp)
	[
		if (temp->lexeme[0] == '$')
			return (true);
		temp = temp->next;
	]
	return (false);
}

bool environ_detector(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while(temp)
	[
		if (variable_detector(lst) && temp->lexeme[1] == '?')
			return (true);
		temp = temp->next;
	]
	return (false);
}
