/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 16:55:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "builtins.h"

/**
 * @brief:
 * @param var_name the name of the variable to export.
 * @param var_value the value to be setted in the var_name.
 * TODO: Use var_name and var_value to set the environment variable.
*/
void	builtins_runner_export(t_token_list *lst)
{
	t_token_list	*temp;
	char			*var_name;
	char			*var_value;

	temp = lst;
	var_name = NULL;
	var_value = NULL;
	if (NULL != temp->next->lexeme)
	{
		var_name = export_getter_var_name(temp);
		var_value = export_getter_var_value(temp);
		ft_printf("var_name: %s\n", var_name);
		ft_printf("var_value: %s\n", var_value);
	}
	free(var_name);
	free(var_value);
}

char	*export_getter_var_name(t_token_list *lst)
{
	t_token_list	*temp;
	int				idx;
	char			*var_name;

	temp = lst->next;
	var_name = (char *)ft_calloc(1, sizeof(char));
	idx = 0;
	while (temp->lexeme[idx] != '\0')
	{
		var_name[idx] = temp->lexeme[idx];
		idx++;
		if (temp->lexeme[idx] == '=')
		{
			var_name[idx] = '\0';
			break ;
		}
	}
	return (var_name);
}

char	*export_getter_var_value(t_token_list *lst)
{
	t_token_list	*temp;
	int				idx;
	int				idx_for_value;
	char			*var_value;

	temp = lst->next;
	var_value = (char *)ft_calloc(1, sizeof(char));
	idx = 0;
	idx_for_value = 0;
	while (temp->lexeme[idx] != '=')
		idx++;
	idx++;
	while (temp->lexeme[idx] != '\0')
	{
		var_value[idx_for_value] = temp->lexeme[idx];
		idx++;
		idx_for_value++;
		if (temp->lexeme[idx] == '\0')
		{
			var_value[idx_for_value] = '\0';
			break ;
		}
	}
	return (var_value);
}
