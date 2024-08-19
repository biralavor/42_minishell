/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   31.builtins_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 12:11:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	arg_option_holder(bool update, bool call_status)
{
	static bool	arg_option_detection;

	if (update && call_status)
		arg_option_detection = true;
	if (!update && !call_status)
		arg_option_detection = false;
	return (arg_option_detection);
}

bool	checking_cmd_arg_options(char *lexeme, char *arg)
{
	if (ft_strncmp(lexeme, arg, 2) == 0)
	{
		arg_option_holder(true, true);
		return (true);
	}
	return (false);
}
