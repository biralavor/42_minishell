/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_userinput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/27 14:45:54 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"

void	check_userinput(char *str)
{
	int				idx;
	t_token_list	*lst;

	idx = 0;
	if (!(check_initial_errors(str)))
		lexer_error();
	lst = NULL;
	create_token_list(str, &lst);
	ft_lst_printf_content(str, lst);
//	check_syntax_errors(&lst);
	free_token_list(&lst);
}
