/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:14:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/20 17:38:32 by umeneses         ###   ########.fr       */
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
	ft_printf(RESET"\n\n");
}
