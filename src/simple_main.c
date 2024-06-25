/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/25 11:30:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Check user input
 * Other input examples:
 * "&&Test"
 * "ls -al a* | grep me > file1"
 * "&&(This) < < | > || \"is\" \'a\' test&&"
*/
int	main(void)
{
	char	*input;

	input = "&&(This) < < | > || \"is\" \'a\' test&&";
	printf("%s\n", input);
	check_userinput(input);
	return (0);
}
