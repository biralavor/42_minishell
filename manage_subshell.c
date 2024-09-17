#include "minishell.h"

int	manage_subshell(t_tree *tree)
{
	char	*tmp;
	char	*new_str;

	tmp = ft_strtrim(tree->command->lexeme, "(");
	new_str = ft_strtrim(tmp, ")");
	loop_routine(new_str);
	free(tmp);
	free(new_str);
	return (0);
}