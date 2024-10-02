/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   40.builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/02 10:51:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_echo(t_token_list *lst, bool arg_option)
{
	short int	space;

	lst = lst->next;
	space = 0;
	if (NULL == lst || (lst && lst->lexeme == NULL))
	{
		write(STDOUT_FILENO, "\n", 1);
		return ;
	}
	lst = checking_cmd_arg_options(&lst, "-n");
	while (lst)
	{
		if (space)
			ft_putstr_fd(" ", STDOUT_FILENO);
		else
			space++;
		if (lst->lexeme != NULL)
			ft_putstr_fd(lst->lexeme, STDOUT_FILENO);
		if (NULL == lst->next)
			break ;
		lst = lst->next;
	}
	arg_option = arg_option_holder(false, true);
	if (!arg_option)
		write(STDOUT_FILENO, "\n", 1);
	arg_option_holder(false, false);
	exit_status_holder(EXIT_SUCCESS, true);
}
