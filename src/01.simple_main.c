/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.simple_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/20 14:21:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(int ac, char **av, char **envp)
{
	int		exit_code;
	char	*input;

	if (ac > 1 && av)
	{
		ft_printf(RED"Error: minishell does not accept arguments.\n");
		ft_printf(CYAN"It's a kind of magic, but not that much!\n"RESET);
		exit (EXIT_FAILURE);
	}
	exit_code = exit_status_holder(33, true, false);
	environment_init(envp);
	// INIT_SIGNALS
	// get_tty_proprieties
	
	while (true)
	{
		// set_tty_proprieties
		// sigquit_case() -> Ctrl+/
		input = readline(GREEN"<<< Born Again (mini) SHell >>>$ "RESET);
		if (ft_strncmp(input, "exit", 4) == 0)
			break ;
		loop_routine(input);
		wait(NULL);
		exit_code = exit_status_holder(0, false, true);
	}
	// {
	// 	input = "fg";
	// 	printf("%s\n", input);
	// 	loop_routine(input);
	// }
	exit(exit_code);
	free(input);
	return (0);
}
