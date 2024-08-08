/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:38:48 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/08 15:09:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

void	ft_env_printer(t_env_entry	*env_table)
{
	int			idx;
	t_env_entry	*aux;

	idx = 0;
	aux = env_table;
	fprintf(stderr, "\033[0;33m\n");
	fprintf(stderr, "Printing environment variables:\n");
	fprintf(stderr, "_________________________________________________________\n");
	fprintf(stderr, "[idx]->%3d	E.N.V.I.R.O.N.M.E.N.T. variables\n", aux->size);
	fprintf(stderr, "\033[0;32m\n");
	while (aux->prev)
		aux = aux->prev;
	while (aux)
	{
		fprintf(stderr, "[%3d] ", idx);
		fprintf(stderr, "%s=", aux->key);
		fprintf(stderr, "%s", aux->value);
		fprintf(stderr, "\n");
		if (aux->next == NULL)
			break ;
		aux = aux->next;
		idx++;
	}
}
