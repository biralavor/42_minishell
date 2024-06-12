/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_01_suite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/12 18:25:34 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "minunit_utils.c"

MU_TEST(first_test)
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

MU_TEST(second_test)
{
	// ARRANGE -> organize the necessary data for the test


	// ACT -> execute the function to be tested


	// ASSERT -> check if the function worked as expected

}

MU_TEST_SUITE(first_suite)
{
	MU_RUN_TEST(first_test);
	MU_RUN_TEST(second_test);
}