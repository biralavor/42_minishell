/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/24 12:01:54 by umeneses         ###   ########.fr       */
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

void	free_token_list(t_token_list **lst)
{
	t_token_list	*curr;
	t_token_list	*temp;

	curr = *lst;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		if (temp->lexeme)
			free(temp->lexeme);
		free(temp);
	}
}

int	ft_lst_size(t_token_list *lst)
{
	int				size;
	t_token_list	*tmp;

	tmp = lst;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

/**
 * @brief TODO: This function should be deleted when the project is finished.
*/
void	ft_lst_printf_content(char *str, t_token_list *lst)
{
	t_token_list	*tmp;
	int				index;
	char			*word_from_lexeme;
	int				lst_size;
	char			*type_as_str;

	tmp = lst;
	lst_size = ft_lst_size(lst);
	index = 0;
	printf("\nPrinting the List:\n");
	while (tmp || index <= lst_size)
	{
		if (tmp->type == 0)
		{
			type_as_str = "WORD";
			printf(RED"str [%2d] = [", index);
			word_from_lexeme = ft_strdup(tmp->lexeme);
			printf("%s", word_from_lexeme);
			printf("]");
			printf(RESET "\t\t");
			printf(BLUE"type = %s", type_as_str);
			printf(RESET "\t\t\t\t");
			printf(GREEN"lexeme = %s\n", tmp->lexeme);
			printf(RESET);
			index = index + ft_strlen(tmp->lexeme);
		}
		else if (tmp->type == 6)
		{
			type_as_str = "OR";
			printf(RED"str [%2d] = [", index);
			printf("%c%c]\t", str[index], str[index + 1]);
			printf(RESET "\t\t");
			printf(BLUE"type = %s", type_as_str);
			printf(RESET "\t\t\t\t");
			printf(GREEN"lexeme = %s\n", tmp->lexeme);
			printf(RESET);
			index++;
		}
		else if (tmp->type == 7)
		{
			type_as_str = "AND";
			printf(RED"str [%2d] = [", index);
			printf("%c%c]\t", str[index], str[index + 1]);
			printf(RESET "\t\t");
			printf(BLUE"type = %s", type_as_str);
			printf(RESET "\t\t\t\t");
			printf(GREEN"lexeme = %s\n", tmp->lexeme);
			printf(RESET);
			index++;
		}
		else
		{
			if (tmp->type == 1)
				type_as_str = "PIPE";
			else if (tmp->type == 2)
				type_as_str = "REDIRECT_INPUT";
			else if (tmp->type == 3)
			{
				type_as_str = "REDIRECT_HEREDOC";
				index++;
			}
			else if (tmp->type == 4)
				type_as_str = "REDIRECT_OUTPUT";
			else if (tmp->type == 5)
			{
				type_as_str = "REDIRECT_OUTPUT_APPEND";
				index++;
			}		
			else if (tmp->type == 8)
				type_as_str = "OPEN_()";
			else if (tmp->type == 9)
				type_as_str = "CLOSE_()";
			printf(RED"str [%2d] = [%c]", index, str[index]);
			printf(RESET "\t\t\t");
			printf(BLUE"type = %s", type_as_str);
			printf(RESET "\t\t\t");
			printf(GREEN"lexeme = %s\n", tmp->lexeme);
			printf(RESET);
		}
		tmp = tmp->next;
		index++;
	}
	printf("Total lst size = %d\n", ft_lst_size(lst));
}
