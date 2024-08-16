/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   31.execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:43:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/16 14:55:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char **cmd)
{
	ft_array_printer(cmd);




	
	free_array(cmd);
}

/**
 * TODO: implementar função que trata expansão de variável
 */
char **convert_tokens_to_array(t_token_list *lst)
{
	int				size;
	char			**cmd;
	t_token_list	*tmp;

	cmd = NULL;
	tmp = lst;
	// expansão de variável, aqui
	size = ft_lst_size(lst);
	cmd = (char **)ft_calloc(1, sizeof(char **) * (size + 1));
	while (tmp)
	{
		cmd[tmp->idx] = ft_strdup(tmp->lexeme);
		tmp = tmp->next;
	}
	return (cmd);
}

void	tree_execution(t_tree *tree)
{
	if (tree->left)
		tree_execution(tree->left);
	else if (tree->right)
		tree_execution(tree->right);
	else if (tree->command && tree->command->lexeme)
	{
		execute(convert_tokens_to_array(tree->command));
	}
}


