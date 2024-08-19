/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.builtins_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 11:30:47 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	checking_cmd_arg_options(char *lexeme, char *arg)
{
	if (ft_strncmp(lexeme, arg, 2) == 0)
	{
		arg_detector = true;
		return (true);
	}
	return (false);
}
