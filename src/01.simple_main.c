/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.simple_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/27 11:58:42 by tmalheir         ###   ########.fr       */
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
	char		*input;
	t_env_entry *env_table;

	if (ac > 1 && av)
	{
		ft_printf(RED"Error: minishell does not accept arguments.\n");
		ft_printf(CYAN"It's a kind of magic, but not that much!\n"RESET);
		exit (EXIT_FAILURE);
	}
	env_table = NULL;
	environment_init(envp, env_table);
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
	}
	// {
	// 	input = "fg";
	// 	printf("%s\n", input);
	// 	loop_routine(input);
	// }
	free(input);
	return (0);
}
