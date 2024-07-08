/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test07_syntax_state100.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:01:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/08 16:08:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_syntax_state100_single_quote_working_simple_space)
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
	userinput = "\' Mussum|\' Ipsum";
	xpect_syntax_validation = 100; // begining with single quote - working
	xpect_lst_size = 2;
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

MU_TEST(testing_syntax_state100_single_quote_working_space_after)
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
	userinput = "\'   			   			Mussum|\'     Ipsum";
	xpect_syntax_validation = 100; // begining with single quote - working
	xpect_lst_size = 2;
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

MU_TEST(testing_syntax_state100_single_quote_working_space_before)
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
	userinput = "		    					\' Mussum|		\'Ipsum";
	xpect_syntax_validation = 100; // begining with single quote - working
	xpect_lst_size = 2;
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




MU_TEST(testing_syntax_state101_single_quote_broken_simple_space)
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
	userinput = "\' Mussum| Ipsum";
	xpect_syntax_validation = 101; // begining with single quote - broken
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

MU_TEST(testing_syntax_state101_single_quote_broken_space_after)
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
	userinput = "\'   			   			Mussum|     Ipsum";
	xpect_syntax_validation = 101; // begining with single quote - broken
	xpect_lst_size = 3;
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

// MU_TEST(testing_syntax_state101_single_quote_broken_space_before)
// {
// 	// ARRANGE
// 	char			*userinput;
// 	int				xpect_lst_size;
// 	int				actual_lst_size;
// 	int				xpect_syntax_validation;
// 	int				actual_syntax_validation;
// 	int				fd;
// 	t_token_list	*lst;

// 	//ACT
// 	fd = 0;
// 	open_redirect_stderr_to_dev_null(fd);
// 	userinput = "		    					\' Mussum|		Ipsum";
// 	xpect_syntax_validation = 101; // begining with single quote - broken
// 	xpect_lst_size = 3;
// 	lst = NULL;
// 	if (create_token_list(userinput, &lst))
// 	{
// 		actual_lst_size = ft_lst_size(lst);
// 		actual_syntax_validation = syntax_validations(lst);
// 	}
// 	else
// 	{
// 		actual_lst_size = 0;
// 		actual_syntax_validation = false;
// 	}

// 	close_redirect_stderr_to_dev_null(fd);
// 	// ASSERT
// 	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
// 	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
// }


MU_TEST_SUITE(test07___syntax_state100_single_quote_errors_suite)
{
	MU_RUN_TEST(testing_syntax_state100_single_quote_working_simple_space);
	MU_RUN_TEST(testing_syntax_state100_single_quote_working_space_after);
	MU_RUN_TEST(testing_syntax_state100_single_quote_working_space_before);
	MU_RUN_TEST(testing_syntax_state101_single_quote_broken_simple_space);
	MU_RUN_TEST(testing_syntax_state101_single_quote_broken_space_after);
	// MU_RUN_TEST(testing_syntax_state101_single_quote_broken_space_before);
}

