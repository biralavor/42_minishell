/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   39.builtin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/24 08:59:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	arg_option_holder(bool update, bool call_status)
{
	static bool	arg_option_detection;

	if (update)
		arg_option_detection = true;
	if (!update && !call_status)
		arg_option_detection = false;
	return (arg_option_detection);
}

t_token_list	*checking_cmd_arg_options(t_token_list **cmd, char *arg)
{
	t_token_list	*tmp;

	tmp = *cmd;
	if (tmp->lexeme && ft_strncmp(tmp->lexeme, arg,
			ft_strlen(tmp->lexeme)) == 0)
	{
		arg_option_holder(true, false);
		while (tmp && tmp->lexeme && ft_strncmp(tmp->lexeme, arg,
				ft_strlen(tmp->lexeme)) == 0)
			tmp = tmp->next;
		return (tmp);
	}
	return (tmp);
}
