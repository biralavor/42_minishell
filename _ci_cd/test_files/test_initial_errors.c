/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_initial_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/29 17:26:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "parser.h"

#define FILE_INPUT_READLINE_01 "./test_files/input_readline_01.txt"

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
	actual_arr_lastcontent = argv_simulation[actual_arr_size];

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

MU_TEST(check_single_quoting_error_test)
{
	// ARRANGE -> organize the necessary data for the test
	char	*userinput_single_quotes;
	int		expected_return_single_quotes;
	int		actual_return_single_quotes;

	// ACT -> execute the function to be tested
	userinput_single_quotes = "'This' test 'tests single quotes";
	expected_return_single_quotes = false;

	actual_return_single_quotes = check_closed_single_quotes(userinput_single_quotes);

	// ASSERT -> check if the function worked as expected
	mu_assert_int_eq(expected_return_single_quotes, actual_return_single_quotes);
}

MU_TEST(check_double_quoting_error_test)
{
	// ARRANGE -> organize the necessary data for the test
	char	*userinput_double_quotes;
	int		expected_return_double_quotes;
	int		actual_return_double_quotes;

	// ACT -> execute the function to be tested
	userinput_double_quotes = "\"This test tests double quotes\"";
	expected_return_double_quotes = true;

	actual_return_double_quotes = check_closed_double_quotes(userinput_double_quotes);

	// ASSERT -> check if the function worked as expected
	mu_assert_int_eq(expected_return_double_quotes, actual_return_double_quotes);
}

MU_TEST(check_single_ampersand_error_test)
{
	// ARRANGE -> organize the necessary data for the test
	char	*userinput_single_ampersand;
	int		expected_return_single_ampersand;
	int		actual_return_single_ampersand;

	// ACT -> execute the function to be tested
	userinput_single_ampersand = "This is&&  a test &&";
	expected_return_single_ampersand = true;

	actual_return_single_ampersand = check_double_ampersand(userinput_single_ampersand);

	// ASSERT -> check if the function worked as expected
	mu_assert_int_eq(expected_return_single_ampersand, actual_return_single_ampersand);
}

MU_TEST(check_initial_errors_test)
{
	// ARRANGE -> organize the necessary data for the test
	char	*userinput;
	int		expected_return;
	int		actual_return;

	// ACT -> execute the function to be tested
	userinput = "'This' \"is\"  a test &&";
	expected_return = true;

	actual_return = check_initial_errors(userinput);

	// ASSERT -> check if the function worked as expected
	mu_assert_int_eq(expected_return, actual_return	);
}

MU_TEST(check_pipe_simulation_test)
{
	// ARRANGE -> organize the necessary data for the test
	char	*argv_simulation;
	char	*userinput;
	int		expected_arr_size;
	char	*expected_arr_content;
	int		actual_arr_size;
	char	*actual_arr_content;

	// ACT -> execute the function to be tested
	userinput = "|";
	argv_simulation = ft_strdup(userinput);
	expected_arr_size = 1;
	expected_arr_content = "|";

	actual_arr_size = ft_strlen(argv_simulation);
	actual_arr_content = argv_simulation;

	// ASSERT -> check if the function worked as expected
	mu_assert_int_eq(expected_arr_size, actual_arr_size);
	mu_assert_string_eq(expected_arr_content, actual_arr_content);
}

MU_TEST_SUITE(check_initial_errors_suite)
{
	MU_RUN_TEST(argv_simulation_test);
	MU_RUN_TEST(input_readline_01_txt_test);
	MU_RUN_TEST(check_single_quoting_error_test);
	MU_RUN_TEST(check_double_quoting_error_test);
	MU_RUN_TEST(check_single_ampersand_error_test);
	MU_RUN_TEST(check_initial_errors_test);
}

MU_TEST_SUITE(token_simulation_errors_suite)
{
	MU_RUN_TEST(check_pipe_simulation_test);
}
