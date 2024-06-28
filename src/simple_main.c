/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/28 14:22:36 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

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

	input = "(This)&&&& \"\" \'&\'< < | > || \"is\" \'a\' test&&";
	printf("%s\n", input);
	check_userinput(input);
	return (0);
}
