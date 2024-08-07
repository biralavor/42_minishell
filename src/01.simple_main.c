/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.simple_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/08 15:05:23 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"

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
 * input = "> out" DOUBLE FREE!!!
 * input = "<<<"
 * input = "<<>><>"
 * input = "cmd<in"
 * input = "<><"
 * input = "\"a\"b\'c\'"
 * input = "\"oi"
 * input = "\'oi"
 * input = "abc \'|\' c"
 * input = "(|())" DOUBLE FREE!!!
 * input = "\"((|)\"\'(())\'"
 * input = "\"\"\'\'"
 */
// int	main(void)
// {
// 	char	*input;

// 	input = "(ls -l)";
// 	printf("%s\n", input);
// 	check_userinput(input);
// 	return (0);
// }

int main (int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	environment_init(envp);
	return (0);
}
