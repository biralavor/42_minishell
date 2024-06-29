/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_userinput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/28 14:11:21 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"

void	check_userinput(char *str)
{
	t_token_list	*lst;

	if (!(check_initial_errors(str)))
		lexer_error();
	lst = NULL;
	create_token_list(str, &lst);
	ft_lst_printf_content(str, lst);
	if ((!check_first_node_errors(lst)) || (!check_initial_syntax_errors(lst)))
		parser_error();
	free_token_list(&lst);
}
