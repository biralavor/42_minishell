/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:35:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/15 11:00:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

void	ft_lst_printer(t_token_list *lst)
{
	int				idx;
	int				lst_size;
	t_token_list	*aux;

	aux = lst;
	idx = 0;
	lst_size = ft_lst_size(aux);
	fprintf(stderr, "\nTotal lst size: %d\n", lst_size);
	fprintf(stderr, "\033[0;33mPrinting the List Now \033[0m \n");
	fprintf(stderr, "|-------|-------------------------|-------------------------|-----------------|-----------------|\n");
	fprintf(stderr, "| index |      token  lexeme      |       token  type       |     previous    |       next      |\n");
	fprintf(stderr, "|-------|-------------------------|-------------------------|-----------------|-----------------|\n");
	while (aux)
	{
		fprintf(stderr, "| \033[0;31m%5d\033[0m | \033[0;32m%23s\033[0m | \033[0;36m%23s\033[0m | %15p | %15p |\n", idx, aux->lexeme, get_token_string(aux->type), aux->prev, aux->next);
		aux = aux->next;
		idx++;
	}
	fprintf(stderr, "|-------|-------------------------|-------------------------|-----------------|-----------------|\n\n");
	fflush(stderr);
}
