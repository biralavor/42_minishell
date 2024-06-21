/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/21 10:57:24 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_next_char(char curr, char next)
{
	if (curr == next)
		return (0);
	else
		return (1);
}

void	lexer_error(void)
{
	ft_printf("lexer error\n");
	exit(EXIT_FAILURE);
}

// APAGAR ESTA FUNÇÃO QUANDO O PROJETO ESTIVER PRONTO!
void	ft_lst_printf_content(char *str, t_token_list *lst)
{
	t_token_list	*tmp;
	int				index;
	char			*type_as_str;

	tmp = lst;
	index = 0;
	ft_printf("\nPrinting the List:\n");
	while (tmp)
	{
		if (tmp->token->type == 0)
		{
			type_as_str = "WORD";
			// index = index + ft_strlen(lst->token->lexeme);
		}
		else if (tmp->token->type == 1)
			type_as_str = "PIPE";
		else if (tmp->token->type == 2)
			type_as_str = "REDIRECT_INPUT";
		else if (tmp->token->type == 3)
		{
			type_as_str = "REDIRECT_HEREDOC";
			index++;
		}
		else if (tmp->token->type == 4)
			type_as_str = "REDIRECT_OUTPUT";
		else if (tmp->token->type == 5)
		{
			type_as_str = "REDIRECT_OUTPUT_APPEND";
			index++;
		}
		else if (tmp->token->type == 6)
		{
			type_as_str = "OR";
			index++;
		}
		else if (tmp->token->type == 7)
		{
			type_as_str = "AND";
			index++;
		}
		else if (tmp->token->type == 8)
			type_as_str = "OPEN_()";
		else if (tmp->token->type == 9)
			type_as_str = "CLOSE_()";
		printf(RED"str [%0.2d] = [%c]", index, str[index]);
		printf(BLUE"\ttype = %s", type_as_str);
		printf(GREEN"\t\t\tlexeme = %s\n", tmp->token->lexeme);
		printf(RESET);
		tmp = tmp->next;
		index++;
	}
	printf("Total str size = %zu\n", ft_strlen(str));
}

