/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:19:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 19:41:36 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"

/**
* @brief: To count the array size inside the minunit tester
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

/**
* @brief: To clear the array inside the minunit tester
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

/**
* @brief: To printf the array inside the minunit tester
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

/**
 * @brief: To get the string of the enum e_token
*/
char	*get_token_string(enum e_token token)
{
	switch (token)
	{
		case WORD: return "WORD";
		case PIPE: return "PIPE";
		case REDIR_IN: return "REDIR_IN";
		case REDIR_HDOC: return "REDIR_HDOC";
		case REDIR_OUT: return "REDIR_OUT";
		case REDIR_OUTAPP: return "REDIR_OUT_APPEND";
		case OR: return "OR";
		case AND: return "AND";
		case SUBSHELL: return "SUBSHELL";
		case ARCHIVE: return "ARCHIVE";
		case DOUBLE_QUOTES: return "DOUBLE_QUOTES";
		case SINGLE_QUOTES: return "SINGLE_QUOTES";
		default: return "UNKNOWN";
	}
}

/**
 * @brief: block the stderr output from the function to be tested
 * @brief: and redirect it to /dev/null
 * @brief: to avoid cluttering the output of the test
 * @brief: open_redirect is used at the initialization of the test
 * @param: int fd - file descriptor
 */
void	open_redirect_stderr_to_dev_null(int fd)
{
	// Redirect stderr to /dev/null
    fd = open("/dev/null", O_WRONLY); // Open /dev/null for writing
    if (fd >= 0)
	{ // Check if opening was successful
        dup2(fd, STDERR_FILENO); // Redirect stderr to /dev/null
        close(fd); // Close the file descriptor
	}
}

/**
 * @brief: block the stderr output from the function to be tested
 * @brief: and redirect it to /dev/null
 * @brief: to avoid cluttering the output of the test
 * @brief: close_redirect is used at the end of the function test
 * @param: int fd - file descriptor
 */
void	close_redirect_stderr_to_dev_null(int fd)
{
	// RESET stderr to its original state
    fd = open("/dev/stderr", O_WRONLY); // Attempt to reopen stderr
    if (fd >= 0)
	{
        dup2(fd, STDERR_FILENO); // Restore stderr
        close(fd); // Close the file descriptor
    }
}