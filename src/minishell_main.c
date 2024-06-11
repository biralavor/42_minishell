#include "minishell.h"

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline(GREEN"Minishell: "RESET);
		printf("%s\n", input);
		free (input);
	}
	return (0);
}