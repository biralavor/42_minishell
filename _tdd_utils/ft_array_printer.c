/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:14:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 12:26:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_array_printer(char **array)
{
	int	idx;

	idx = 0;
	fprintf(stderr, YELLOW"Printing Commands Array:\n");
	while (array[idx])
	{
		fprintf(stderr, CYAN"[%d] = %s\n", idx, array[idx]);
		idx++;
	}
	fprintf(stderr, "end_of_array_printing__________________________");
	fprintf(stderr, "here_is_the_command_result:\n"RESET);
}
