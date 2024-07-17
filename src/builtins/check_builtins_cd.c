/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins_cd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 16:43:02 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "builtins.h"

/**
 * @brief: TODO: Implement update_envs() after calling chdir().
*/
void	builtins_runner_cd(t_token_list *lst)
{
	t_token_list	*temp;
	int				destiny_len;
	char			*destiny_path;
	char			*actual_path;

	temp = lst;
	destiny_path = NULL;
	actual_path = NULL;
	while (temp && temp->type == WORD && temp->next && temp->next->type == WORD)
	{
		destiny_path = temp->next->lexeme;
		destiny_len = ft_strlen(destiny_path);
		if (chdir(destiny_path) != 0)
			error_cd_messenger(destiny_len, destiny_path);
		else if (destiny_path[0] == '.' && destiny_path[1] == '\0')
			write(2, "\n", 1);
		else
		{
			actual_path = getcwd(actual_path, 100);
			destiny_path = ft_strjoin(actual_path, "/");
			chdir(destiny_path);
		}
		temp = temp->next;
	}
}

void	error_cd_messenger(int destiny_len, char *destiny_path)
{
	write(2, "bash: cd: ", 11);
	write(2, destiny_path, destiny_len);
	write(2, ": No such file or directory", 28);
	write(2, "\n", 1);
}
