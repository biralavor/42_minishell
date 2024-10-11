/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   46.builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:08:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/11 02:00:53 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	last_is_equal(char *arg)
{
	int	idx;

	idx = 0;
	while (arg[idx])
		idx++;
	if (arg[idx - 1] == '=')
		return (true);
	return (false);
}

void	builtins_runner_unset(char *arg)
{
	t_env_entry	*next;
	t_env_entry	*tmp;
	char		*var_key;

	next = NULL;
	var_key = NULL;
	tmp = copy_env_table(env_holder(NULL, false, false));
	if (*arg == '$')
	{
		var_key = ft_strdup(++arg);
		arg--;
		ft_lst_remove_node(tmp, next, var_key);
		free(var_key);
	}
	else if (arg_handle_state_detector(0, arg) == 404 || last_is_equal(arg))
	{
		ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		free_env_table(&tmp);
		exit_status_holder(EXIT_FAILURE, true);
	}
	else
		ft_lst_remove_node(tmp, next, arg);
}

static void	remove_first_node(t_env_entry *tmp, t_env_entry **next)
{
	*next = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	if (tmp->value)
		free(tmp->value);
	free(tmp->key);
	free(tmp);
	(void)env_holder(*next, true, false);
}

void	ft_lst_remove_node(t_env_entry *tmp, t_env_entry *next,
	const char *var_key)
{
	next = tmp;
	while (tmp)
	{
		if (ft_strcmp(var_key, tmp->key) == 0)
		{
			if (tmp->prev == NULL)
			{
				remove_first_node(tmp, &next);
				return ;
			}
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			next = tmp->prev;
			if (tmp->value)
				free(tmp->value);
			free(tmp->key);
			free(tmp);
			tmp = goto_head_env_table(next);
			(void)env_holder(tmp, true, false);
			return ;
		}
		tmp = tmp->next;
	}
	free_env_table(&next);
}
