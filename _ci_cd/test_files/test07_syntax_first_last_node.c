/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test07_syntax_first_last_node.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:01:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/08 12:05:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_syntax_first_node_PIPE_simple_space)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "| Mussum|Ipsum";
	xpect_syntax_validation = 201; // begining with PIPE, OR or AND
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_PIPE_space_after)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "|			                          Mussum|Ipsum";
	xpect_syntax_validation = 201; // begining with PIPE, OR or AND
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_PIPE_space_before)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "			                          |Mussum|Ipsum";
	xpect_syntax_validation = 201; // begining with PIPE, OR or AND
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_OR_simple_space)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "|| Mussum|Ipsum";
	xpect_syntax_validation = 201; // begining with PIPE, OR or AND
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_OR_space_after)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "||			                          Mussum|Ipsum";
	xpect_syntax_validation = 201; // begining with PIPE, OR or AND
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_OR_space_before)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "			                          ||Mussum|Ipsum";
	xpect_syntax_validation = 201; // begining with PIPE, OR or AND
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_AND_simple_space)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "&& Mussum|Ipsum";
	xpect_syntax_validation = 201; // begining with PIPE, OR or AND
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_AND_space_after)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "&&			                          Mussum|Ipsum";
	xpect_syntax_validation = 201; // begining with PIPE, OR or AND
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_AND_space_before)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "			                          &&Mussum|Ipsum";
	xpect_syntax_validation = 201; // begining with PIPE, OR or AND
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}


MU_TEST(testing_syntax_first_node_REDIRECT_INPUT_simple_space)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "> Mussum|Ipsum";
	xpect_syntax_validation = 301; // begining with redirect input
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_REDIRECT_INPUT_space_after)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = ">			                          Mussum|Ipsum";
	xpect_syntax_validation = 301; // begining with redirect input
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_REDIRECT_INPUT_space_before)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "			                          >Mussum|Ipsum";
	xpect_syntax_validation = 301; // begining with redirect input
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}



MU_TEST(testing_syntax_first_node_CLOSE_PARENTHESIS_simple_space)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = ") Mussum|Ipsum";
	xpect_syntax_validation = 402;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_CLOSE_PARENTHESIS_space_after)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = ")			                          Mussum|Ipsum";
	xpect_syntax_validation = 402;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_CLOSE_PARENTHESIS_space_before)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "			                          )Mussum|Ipsum";
	xpect_syntax_validation = 402;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = syntax_validations(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST_SUITE(test07___syntax_first_node_PIPE_errors_suite)
{
	MU_RUN_TEST(testing_syntax_first_node_PIPE_simple_space);
	MU_RUN_TEST(testing_syntax_first_node_PIPE_space_after);
	MU_RUN_TEST(testing_syntax_first_node_PIPE_space_before);
}

MU_TEST_SUITE(test07___syntax_first_node_OR_errors_suite)
{
	MU_RUN_TEST(testing_syntax_first_node_OR_simple_space);
	MU_RUN_TEST(testing_syntax_first_node_OR_space_after);
	MU_RUN_TEST(testing_syntax_first_node_OR_space_before);
}

MU_TEST_SUITE(test07___syntax_first_node_AND_errors_suite)
{
	MU_RUN_TEST(testing_syntax_first_node_AND_simple_space);
	MU_RUN_TEST(testing_syntax_first_node_AND_space_after);
	MU_RUN_TEST(testing_syntax_first_node_AND_space_before);
}

MU_TEST_SUITE(test07___syntax_first_node_REDIRECT_INPUT_errors_suite)
{
	MU_RUN_TEST(testing_syntax_first_node_REDIRECT_INPUT_simple_space);
	MU_RUN_TEST(testing_syntax_first_node_REDIRECT_INPUT_space_after);
	MU_RUN_TEST(testing_syntax_first_node_REDIRECT_INPUT_space_before);
}

MU_TEST_SUITE(test07___syntax_first_node_CLOSE_PARENTHESIS_errors_suite)
{
	MU_RUN_TEST(testing_syntax_first_node_CLOSE_PARENTHESIS_simple_space);
	MU_RUN_TEST(testing_syntax_first_node_CLOSE_PARENTHESIS_space_after);
	MU_RUN_TEST(testing_syntax_first_node_CLOSE_PARENTHESIS_space_before);
}