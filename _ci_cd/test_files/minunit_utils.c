/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:19:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/24 15:21:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"

/* munUnit helper functions
*  To count the array size inside the minunit tester
*/
int	ft_minunit_array_counter(char **array)
{
	int	arr_size;

	arr_size = 0;
	while (array[arr_size] != NULL)
	{
		arr_size++;
		if (array[arr_size] == NULL)
		{
			arr_size--;
			break ;
		}
	}
	return (arr_size);
}

/* munUnit helper functions
*  To clear the array inside the minunit tester
*/
void	ft_array_clear(char **array, int arr_size)
{
	while (arr_size >= 0)
	{
		free(array[arr_size]);
		arr_size--;
	}
	free(array);
}

/* minUnit helper functions
*  To printf the array inside the minunit tester
*/
void	ft_array_printer(char **array_lexeme, int *array_type, int arr_size)
{
	int	index;

	index = arr_size;
	ft_printf("\nPrinting the List:\n");
	while (index >= 0)
	{
		printf("[%2d]\tlexeme = %s\ttype = %d\n", index, (array_lexeme[index]), array_type[index]);
		index--;
	}
}

char	*get_token_string(enum e_token token)
{
	switch (token)
	{
		case WORD: return "WORD";
		case PIPE: return "PIPE";
		case REDIRECT_INPUT: return "REDIRECT_INPUT";
		case REDIRECT_HEREDOC: return "REDIRECT_HEREDOC";
		case REDIRECT_OUTPUT: return "REDIRECT_OUTPUT";
		case REDIRECT_OUTPUT_APPEND: return "REDIRECT_OUTPUT_APPEND";
		case OR: return "OR";
		case AND: return "AND";
		case OPEN_PARENTHESIS: return "OPEN_PARENTHESIS";
		case CLOSE_PARENTHESIS: return "CLOSE_PARENTHESIS";
		default: return "UNKNOWN";
	}
}
