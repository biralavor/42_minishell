/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/24 11:59:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;

	input = "&&Test";
	// input = "ls -al a* | grep me > file1";
	// input = "&&(This) < < | > || \"is\" \'a\' test&&";
	printf("%s\n", input);
	check_userinput(input);
	return (0);
}
