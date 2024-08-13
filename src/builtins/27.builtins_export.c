/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.builtins_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/10 17:37:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "executor.h"
#include "builtins.h"

/**
 * @brief:
 * @param var_key the name of the variable to export.
 * @param var_value the value to be setted in the var_key.
 * TODO: Use var_key and var_value to set the environment variable.
*/
void	builtins_runner_export(t_env_entry *env_vars)
{
	char	*var_key;
	char	*var_value;

	var_key = NULL;
	var_value = NULL;
	while (env_vars)
	{
		var_key = env_vars->key;
		var_value = env_vars->value;
		ft_printf("declare -x ");
		ft_printf("%s=", var_key);
		ft_printf("%s\n", var_value);
		env_vars = env_vars->next;
	}
}

// t_env_entry	*export_getter_var_name(t_env_entry *table)
// {
// 	t_env_entry	*temp;
// 	int				idx;
// 	char			*equal_sign;

// 	var_name = ft_strchr(temp)
// 	idx = 0;
// 	while (temp->lexeme[idx] != '\0')
// 	{
// 		var_name[idx] = temp->lexeme[idx];
// 		idx++;
// 		if (temp->lexeme[idx] == '=')
// 		{
// 			var_name[idx] = '\0';
// 			break ;
// 		}
// 	}
// 	return (var_name);
// }

// char	*export_getter_var_value(t_token_list *lst)
// {
// 	t_token_list	*temp;
// 	int				idx;
// 	int				idx_for_value;
// 	char			*var_value;

// 	temp = lst->next;
// 	var_value = (char *)ft_calloc(1, sizeof(char));
// 	idx = 0;
// 	idx_for_value = 0;
// 	while (temp->lexeme[idx] != '=')
// 		idx++;
// 	idx++;
// 	while (temp->lexeme[idx] != '\0')
// 	{
// 		var_value[idx_for_value] = temp->lexeme[idx];
// 		idx++;
// 		idx_for_value++;
// 		if (temp->lexeme[idx] == '\0')
// 		{
// 			var_value[idx_for_value] = '\0';
// 			break ;
// 		}
// 	}
// 	return (var_value);
// }
