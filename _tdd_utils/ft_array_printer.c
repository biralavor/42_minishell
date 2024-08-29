/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:14:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/29 15:39:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_array_printer(char **array)
{
	int	idx;

	idx = 0;
	ft_printf(YELLOW"Printing Commands Array:\n");
	while (array[idx])
	{
		ft_printf(CYAN"[%d] = %s\n", idx, array[idx]);
		idx++;
	}
	ft_printf("end_of_array_printing__________________________");
	ft_printf("here_is_the_command_result:\n"RESET);
}
