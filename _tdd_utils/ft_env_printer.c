/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:38:48 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/08 11:16:23 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

void	ft_env_printer(t_env_entry	*env_table)
{
	int	idx;

	idx = 0;
	fprintf(stderr, "\033[0;33m\n");
	fprintf(stderr, "Printing environment variables:\n");
	fprintf(stderr, "_________________________________________________________\n");
	fprintf(stderr, "[idx]	E.N.V.I.R.O.N.M.E.N.T. variables (copy)\n");
	fprintf(stderr, "\033[0;32m\n");
	while (idx < env_table->size)
	{
		fprintf(stderr, "[%3d] ", idx);
		fprintf(stderr, "%s=", env_table->key);
		fprintf(stderr, "%s", env_table->value);
		fprintf(stderr, "\n");
		env_table = env_table->next;
		idx++;
	}
}
