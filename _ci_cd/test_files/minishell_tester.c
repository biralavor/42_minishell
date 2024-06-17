/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/17 13:26:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_INPUT_READLINE_01 "./test_files/input_readline_01.txt"
// #include "./minunit_utils.c"

int	ft_minunit_array_counter(char **array);
void	ft_array_clear(char **array, int arr_size);
void	ft_array_printer(char **array, int arr_size);

MU_TEST(argv_simulation_test)
{
	// ARRANGE -> organize the necessary data for the test
	char	**argv_simulation;
	char	*userinput;
	int		expected_arr_size;
	char	*expected_arr_lastcontent;
	int		actual_arr_size;
	char	*actual_arr_lastcontent;

	// ACT -> execute the function to be tested
	argv_simulation = NULL;
	userinput = "this is an array for testing";
	argv_simulation = ft_split(userinput, ' ');
	expected_arr_size = 5;
	expected_arr_lastcontent = "testing";

	actual_arr_size = ft_minunit_array_counter(argv_simulation);
	actual_arr_lastcontent = argv_simulation[expected_arr_size];

	// ASSERT -> check if the function worked as expected
	mu_assert_int_eq(expected_arr_size, actual_arr_size);
	mu_assert_string_eq(expected_arr_lastcontent, actual_arr_lastcontent);
}

MU_TEST(input_readline_01_txt_test)
{
	// ARRANGE
	const char	*expected_output;
	char 		*actual_output;
	char 		buffer[1024];
	size_t		expected_size;
	size_t		actual_size;
	FILE		*input_file;

	// ACT
	actual_output = NULL;
	actual_size = 0;
	input_file = fopen(FILE_INPUT_READLINE_01, "r");
	if (!input_file)
	{
		mu_fail("File open failed");
		return ;
	}
	expected_output = "this is a test";
	expected_size = ft_strlen(expected_output);
	if (fgets(buffer, sizeof(buffer), input_file) != NULL)
	{
		actual_size = ft_strlen(buffer);
		if (actual_size > 0 && buffer[actual_size - 1] == '\n')
			buffer[actual_size - 1] = '\0';
	}
	actual_output = buffer;
	fclose(input_file);

	// ASSERT
	mu_assert_string_eq(expected_output, actual_output);
	mu_assert_int_eq(expected_size, actual_size);
}

MU_TEST_SUITE(first_suite)
{
	MU_RUN_TEST(argv_simulation_test);
	MU_RUN_TEST(input_readline_01_txt_test);
}

int	main(void)
{
	MU_RUN_SUITE(first_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}



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

/* munUnit helper functions
*  To printf the array inside the minunit tester
*/
void	ft_array_printer(char **array, int arr_size)
{
	int	index;

	index = arr_size;
	while (index >= 0)
	{
		ft_printf("argv_simulation = %s\n", (array[index]));
		index--;
	}
}
