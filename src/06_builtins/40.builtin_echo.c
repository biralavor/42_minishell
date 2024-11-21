/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   40.builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/11 02:42:16 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_tokens(t_token_list *lst, short int *space)
{
	while (lst)
	{
		if (*space)
			ft_putstr_fd(" ", STDOUT_FILENO);
		else
			(*space)++;
		if (lst->lexeme != NULL)
			ft_putstr_fd(lst->lexeme, STDOUT_FILENO);
		if (NULL == lst->next)
			break ;
		lst = lst->next;
	}
}

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
	print_tokens(lst, &space);
	arg_option = arg_option_holder(false, true);
	if (!arg_option)
		write(STDOUT_FILENO, "\n", 1);
	arg_option_holder(false, false);
}
