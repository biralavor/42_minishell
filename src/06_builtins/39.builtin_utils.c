/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   39.builtin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/08 20:59:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	arg_option_holder(bool update, bool call_status)
{
	static bool	arg_option_detection;

	if (update && call_status)
		arg_option_detection = true;
	else if (!update && call_status)
		return (arg_option_detection);
	else if (!update && !call_status)
		arg_option_detection = false;
	return (arg_option_detection);
}

t_token_list	*checking_cmd_arg_options(t_token_list **cmd, char *arg)
{
	t_token_list	*tmp;

	tmp = *cmd;
	if (tmp->lexeme && ft_strcmp(tmp->lexeme, arg) == 0)
	{
		arg_option_holder(true, true);
		while (tmp && tmp->lexeme && ft_strcmp(tmp->lexeme, arg) == 0)
			tmp = tmp->next;
		return (tmp);
	}
	return (tmp);
}
