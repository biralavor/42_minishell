/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:19:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/17 11:48:46 by umeneses         ###   ########.fr       */
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