/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:14:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/10 13:25:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_array_printer(char **array)
{
	int	idx;

	idx = 0;
	fprintf(stderr, YELLOW"Printing Array Content:\n");
	while (array[idx])
	{
		fprintf(stderr, CYAN"[ %p ] ", *array);
		fprintf(stderr, YELLOW"%2d ", idx);
		fprintf(stderr, RESET" = ");
		fprintf(stderr, BLUE"%s\n", array[idx]);
		idx++;
	}
	fprintf(stderr, YELLOW"End of Array Printing________________________");
	fprintf(stderr, "Here is the your command result:\n"RESET);
}
