/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.simple_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/18 15:40:11 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"

/**
 * @brief Others fast-test for check_userinput()
 * input = "&&Test";
 * input = "ls -al a* | grep me > file1";
 * input = "&&(This) < < | > || \"is\" \'a\' test&&";
 * input = "\"o\"\"i\""
 * input = "\"e\"\"c\"\"h\"\"o\"\"o\"\"i\"";
 * input = "\"e\"\"\"\"h\"\"o\"\"o\"\"i\"";
 * input = "\'e\'\'c\'\'h\'\'o\'\'o\'\'i\'";
 * input = "\'e\'\'c\'\'\'\'o\'\'o\'\'i\'";
 * input = "echo oi > tudo > bem com voce > ?"
 * input = "echo oi > tudo bem > com voce amigo querido > guardou"
 * input = "<in (cmd | && > < ) | >> | \"|><)\""
 * input = "> out"
 * input = "<<<"
 * input = "<<>><>"
 * input = "cmd<in"
 * input = "<><"
 * input = "\"a\"b\'c\'"
 * input = "\"oi"
 * input = "\'oi"
 * input = "abc \'|\' c"
 * input = "(|())"
 * input = "\"((|)\"\'(())\'"
 * input = "\"\"\'\'"
*/
int	main(void)
{
	char	*input;

	input = "ls -al a* | grep me > file1";
	printf("%s\n", input);
	check_userinput(input);
	return (0);
}
