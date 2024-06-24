/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/24 13:08:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_INPUT_READLINE_01 "./test_files/input_readline_01.txt"
// #include "./minunit_utils.c"
#include "../../src/check_userinput.c"
#include "../../src/check_initial_errors.c"
#include "../../src/create_token_list.c"
#include "../../src/get_state.c"
#include "../../src/lexer_utils.c"
#include "../../src/state1_to_state5.c"
#include "../../src/state6_to_state10.c"
#include "../../src/state11_to_state15.c"

int		ft_minunit_array_counter(char **array);
void	ft_array_clear(char **array, int arr_size);
void	ft_array_printer(char **array_lexeme, int *array_type, int arr_size);
int		ft_lst_size(t_token_list *list);
char	*get_token_string(enum e_token token);

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

MU_TEST(check_double_quoting_error_test)
{
	// ARRANGE -> organize the necessary data for the test
	char	*userinput_double_quotes;
	int		expected_return_double_quotes;
	int		actual_return_double_quotes;

	// ACT -> execute the function to be tested
	userinput_double_quotes = "\"This test tests double quotes\"";
	expected_return_double_quotes = 0;

	actual_return_double_quotes = check_double_quotes(userinput_double_quotes);

	// ASSERT -> check if the function worked as expected
	mu_assert_int_eq(expected_return_double_quotes, actual_return_double_quotes);
}

MU_TEST(check_single_quoting_error_test)
{
	// ARRANGE -> organize the necessary data for the test
	char	*userinput_single_quotes;
	int		expected_return_single_quotes;
	int		actual_return_single_quotes;

	// ACT -> execute the function to be tested
	userinput_single_quotes = "'This' test 'tests single quotes";
	expected_return_single_quotes = 1;

	actual_return_single_quotes = check_single_quotes(userinput_single_quotes);

	// ASSERT -> check if the function worked as expected
	mu_assert_int_eq(expected_return_single_quotes, actual_return_single_quotes);
}

MU_TEST(check_single_ampersand_error_test)
{
	// ARRANGE -> organize the necessary data for the test
	char	*userinput_single_ampersand;
	int		expected_return_single_ampersand;
	int		actual_return_single_ampersand;

	// ACT -> execute the function to be tested
	userinput_single_ampersand = "This is&&  a test &&";
	expected_return_single_ampersand = 0;

	actual_return_single_ampersand = check_single_ampersand(userinput_single_ampersand);

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
	expected_return = 0;

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

MU_TEST(check_userinput_token_empty)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node_01_lexeme;
	char			*xpect_node_01_type;
	char			*actual_node_01_lexeme;
	char			*actual_node_01_type;
	t_token_list	*lst;

	//ACT
	userinput = "";

	xpect_node_01_type = NULL;
	xpect_node_01_lexeme = NULL;
	xpect_lst_size = 0;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	if (lst == NULL)
	{
		actual_lst_size = 0;
		actual_node_01_lexeme = NULL;
		actual_node_01_type = NULL;
	}
	else
	{
		actual_lst_size = ft_lst_size(lst);
		actual_node_01_lexeme = lst->lexeme;
		actual_node_01_type = get_token_string(lst->type);
	}
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node_01_lexeme, actual_node_01_lexeme);
	mu_assert_string_eq(xpect_node_01_type, actual_node_01_type);
}

MU_TEST(check_userinput_token_01_pipe_at_begin)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node1_lexeme;
	char			*xpect_node1_type;
	char			*xpect_node2_lexeme;
	char			*xpect_node2_type;
	char			*xpect_node3_lexeme;
	char			*xpect_node3_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	t_token_list	*lst;

	//ACT
	userinput = "|Mussum Ipsum";

	xpect_node1_type = get_token_string(PIPE);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_pipe_at_middle)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node1_lexeme;
	char			*xpect_node1_type;
	char			*xpect_node2_lexeme;
	char			*xpect_node2_type;
	char			*xpect_node3_lexeme;
	char			*xpect_node3_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	t_token_list	*lst;

	//ACT
	userinput = "Mussum|Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(PIPE);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_pipe_at_end)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node1_lexeme;
	char			*xpect_node1_type;
	char			*xpect_node2_lexeme;
	char			*xpect_node2_type;
	char			*xpect_node3_lexeme;
	char			*xpect_node3_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	t_token_list	*lst;

	//ACT
	userinput = "Mussum Ipsum|";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(PIPE);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_05)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node_01_lexeme;
	char			*xpect_node_01_type;
	char			*xpect_node_02_lexeme;
	char			*xpect_node_02_type;
	char			*xpect_node_03_lexeme;
	char			*xpect_node_03_type;
	char			*xpect_node_04_lexeme;
	char			*xpect_node_04_type;
	char			*xpect_node_05_lexeme;
	char			*xpect_node_05_type;
	char			*actual_node_01_lexeme;
	char			*actual_node_01_type;
	char			*actual_node_02_lexeme;
	char			*actual_node_02_type;
	char			*actual_node_03_lexeme;
	char			*actual_node_03_type;
	char			*actual_node_04_lexeme;
	char			*actual_node_04_type;
	char			*actual_node_05_lexeme;
	char			*actual_node_05_type;
	t_token_list	*lst;

	//ACT
	userinput = ">t2 ls | \"'hello world'\"";

	xpect_node_01_type = get_token_string(REDIRECT_OUTPUT);
	xpect_node_01_lexeme = NULL;
	xpect_node_02_type = get_token_string(WORD);
	xpect_node_02_lexeme = "t2";
	xpect_node_03_type = get_token_string(WORD);
	xpect_node_03_lexeme = "ls";
	xpect_node_04_type = get_token_string(PIPE);
	xpect_node_04_lexeme = NULL;
	xpect_node_05_type = get_token_string(WORD);
	xpect_node_05_lexeme = "\"'hello world'\"";
	xpect_lst_size = 5;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	
	actual_lst_size = ft_lst_size(lst);
	actual_node_01_lexeme = lst->lexeme;
	actual_node_01_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_02_lexeme = lst->lexeme;
	actual_node_02_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_03_lexeme = lst->lexeme;
	actual_node_03_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_04_lexeme = lst->lexeme;
	actual_node_04_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_05_lexeme = lst->lexeme;
	actual_node_05_type = get_token_string(lst->type);

	//ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node_01_lexeme, actual_node_01_lexeme);
	mu_assert_string_eq(xpect_node_01_type, actual_node_01_type);
	mu_assert_string_eq(xpect_node_02_lexeme, actual_node_02_lexeme);
	mu_assert_string_eq(xpect_node_02_type, actual_node_02_type);
	mu_assert_string_eq(xpect_node_03_lexeme, actual_node_03_lexeme);
	mu_assert_string_eq(xpect_node_03_type, actual_node_03_type);
	mu_assert_string_eq(xpect_node_04_lexeme, actual_node_04_lexeme);
	mu_assert_string_eq(xpect_node_04_type, actual_node_04_type);
	mu_assert_string_eq(xpect_node_05_lexeme, actual_node_05_lexeme);
	mu_assert_string_eq(xpect_node_05_type, actual_node_05_type);
}

MU_TEST(check_userinput_token_10)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node_01_lexeme;
	char			*xpect_node_01_type;
	char			*xpect_node_02_lexeme;
	char			*xpect_node_02_type;
	char			*xpect_node_03_lexeme;
	char			*xpect_node_03_type;
	char			*xpect_node_04_lexeme;
	char			*xpect_node_04_type;
	char			*xpect_node_05_lexeme;
	char			*xpect_node_05_type;
	char			*xpect_node_06_lexeme;
	char			*xpect_node_06_type;
	char			*xpect_node_07_lexeme;
	char			*xpect_node_07_type;
	char			*xpect_node_08_lexeme;
	char			*xpect_node_08_type;
	char			*xpect_node_09_lexeme;
	char			*xpect_node_09_type;
	char			*xpect_node_10_lexeme;
	char			*xpect_node_10_type;
	char			*actual_node_01_lexeme;
	char			*actual_node_01_type;
	char			*actual_node_02_lexeme;
	char			*actual_node_02_type;
	char			*actual_node_03_lexeme;
	char			*actual_node_03_type;
	char			*actual_node_04_lexeme;
	char			*actual_node_04_type;
	char			*actual_node_05_lexeme;
	char			*actual_node_05_type;
	char			*actual_node_06_lexeme;
	char			*actual_node_06_type;
	char			*actual_node_07_lexeme;
	char			*actual_node_07_type;
	char			*actual_node_08_lexeme;
	char			*actual_node_08_type;
	char			*actual_node_09_lexeme;
	char			*actual_node_09_type;
	char			*actual_node_10_lexeme;
	char			*actual_node_10_type;
	t_token_list	*lst;

	//ACT
	userinput = "/bin/ls | pwd | grep >> teste.txt > teste1.txt cat";

	xpect_node_01_type = get_token_string(WORD);
	xpect_node_01_lexeme = "/bin/ls";
	xpect_node_02_type = get_token_string(PIPE);
	xpect_node_02_lexeme = NULL;
	xpect_node_03_type = get_token_string(WORD);
	xpect_node_03_lexeme = "pwd";
	xpect_node_04_type = get_token_string(PIPE);
	xpect_node_04_lexeme = NULL;
	xpect_node_05_type = get_token_string(WORD);
	xpect_node_05_lexeme = "grep";
	xpect_node_06_type = get_token_string(REDIRECT_OUTPUT_APPEND);
	xpect_node_06_lexeme = NULL;
	xpect_node_07_type = get_token_string(WORD);
	xpect_node_07_lexeme = "teste.txt";
	xpect_node_08_type = get_token_string(REDIRECT_OUTPUT);
	xpect_node_08_lexeme = NULL;
	xpect_node_09_type = get_token_string(WORD);
	xpect_node_09_lexeme = "teste1.txt";
	xpect_node_10_type = get_token_string(WORD);
	xpect_node_10_lexeme = "cat";
	xpect_lst_size = 10;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	
	actual_lst_size = ft_lst_size(lst);
	actual_node_01_lexeme = lst->lexeme;
	actual_node_01_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_02_lexeme = lst->lexeme;
	actual_node_02_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_03_lexeme = lst->lexeme;
	actual_node_03_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_04_lexeme = lst->lexeme;
	actual_node_04_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_05_lexeme = lst->lexeme;
	actual_node_05_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_06_lexeme = lst->lexeme;
	actual_node_06_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_07_lexeme = lst->lexeme;
	actual_node_07_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_08_lexeme = lst->lexeme;
	actual_node_08_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_09_lexeme = lst->lexeme;
	actual_node_09_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_10_lexeme = lst->lexeme;
	actual_node_10_type = get_token_string(lst->type);
	
	//ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node_01_lexeme, actual_node_01_lexeme);
	mu_assert_string_eq(xpect_node_01_type, actual_node_01_type);
	mu_assert_string_eq(xpect_node_02_lexeme, actual_node_02_lexeme);
	mu_assert_string_eq(xpect_node_02_type, actual_node_02_type);
	mu_assert_string_eq(xpect_node_03_lexeme, actual_node_03_lexeme);
	mu_assert_string_eq(xpect_node_03_type, actual_node_03_type);
	mu_assert_string_eq(xpect_node_04_lexeme, actual_node_04_lexeme);
	mu_assert_string_eq(xpect_node_04_type, actual_node_04_type);
	mu_assert_string_eq(xpect_node_05_lexeme, actual_node_05_lexeme);
	mu_assert_string_eq(xpect_node_05_type, actual_node_05_type);
	mu_assert_string_eq(xpect_node_06_lexeme, actual_node_06_lexeme);
	mu_assert_string_eq(xpect_node_06_type, actual_node_06_type);
	mu_assert_string_eq(xpect_node_07_lexeme, actual_node_07_lexeme);
	mu_assert_string_eq(xpect_node_07_type, actual_node_07_type);
	mu_assert_string_eq(xpect_node_08_lexeme, actual_node_08_lexeme);
	mu_assert_string_eq(xpect_node_08_type, actual_node_08_type);
	mu_assert_string_eq(xpect_node_09_lexeme, actual_node_09_lexeme);
	mu_assert_string_eq(xpect_node_09_type, actual_node_09_type);
	mu_assert_string_eq(xpect_node_10_lexeme, actual_node_10_lexeme);
	mu_assert_string_eq(xpect_node_10_type, actual_node_10_type);
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

MU_TEST_SUITE(check_userinput_tokens_light_tests)
{
	MU_RUN_TEST(check_userinput_token_empty);
	MU_RUN_TEST(check_userinput_token_01_pipe_at_begin);
	MU_RUN_TEST(check_userinput_token_01_pipe_at_middle);
	MU_RUN_TEST(check_userinput_token_01_pipe_at_end);
}

MU_TEST_SUITE(check_userinput_tokens_medium_tests)
{
	MU_RUN_TEST(check_userinput_token_05);
	MU_RUN_TEST(check_userinput_token_10);
}

int	main(void)
{
	MU_RUN_SUITE(check_initial_errors_suite);
	MU_RUN_SUITE(token_simulation_errors_suite);
	MU_RUN_SUITE(check_userinput_tokens_light_tests);
	MU_RUN_SUITE(check_userinput_tokens_medium_tests);
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
		ft_printf("[%d.]\tlexeme = %s\ttype = %d\n", index, (array_lexeme[index]), array_type[index]);
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
