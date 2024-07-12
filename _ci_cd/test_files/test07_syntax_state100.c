/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test07_syntax_state100.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:01:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/12 17:28:43 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_syntax_state100_single_quote_working_simple_space_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\' Mussum|\' Ipsum";
	xpect_syntax_validation = 100; // begining with single quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = false;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_single_quote_working_space_after_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\'   			   			Mussum|\'     Ipsum";
	xpect_syntax_validation = 100; // begining with single quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = false;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_single_quote_working_space_before_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "		    					\' Mussum|		\'Ipsum";
	xpect_syntax_validation = 100; // begining with single quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = false;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_single_quote_broken_simple_space_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\' Mussum| Ipsum";
	xpect_syntax_validation = 101; // begining with single quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_single_quote_broken_space_after_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\'   			   			Mussum|     Ipsum";
	xpect_syntax_validation = 101; // begining with single quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_single_quote_broken_space_before_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "		    					\' Mussum|		Ipsum";
	xpect_syntax_validation = 101; // begining with single quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_single_quote_working_simple_space_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\' Mussum| Ipsum\'";
	xpect_syntax_validation = 100; // ending with single quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_single_quote_working_space_after_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\'   			   			Mussum|     Ipsum\'";
	xpect_syntax_validation = 100; // ending with single quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_single_quote_working_space_before_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "		    					\' Mussum|		Ipsum\'";
	xpect_syntax_validation = 100; // ending with single quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_single_quote_broken_simple_space_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = " Mussum| Ipsum \' ";
	xpect_syntax_validation = 101; // ending with single quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_single_quote_broken_space_after_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "Mussum|     Ipsum\'   			   			";
	xpect_syntax_validation = 101; // ending with single quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_single_quote_broken_space_before_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = " Mussum|		Ipsum		    					\'";
	xpect_syntax_validation = 101; // ending with single quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_double_quote_working_simple_space_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	userinput = "\" Mussum|\" Ipsum";
	xpect_syntax_validation = 100; // begining with double quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_double_quote_working_space_after_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\"   			   			Mussum|\"     Ipsum";
	xpect_syntax_validation = 100; // begining with double quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_double_quote_working_space_before_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "		    					\" Mussum|		\"Ipsum";
	xpect_syntax_validation = 100; // begining with double quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}















MU_TEST(testing_syntax_state101_double_quote_broken_simple_space_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\" Mussum| Ipsum";
	xpect_syntax_validation = 101; // begining with double quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_double_quote_broken_space_after_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\"   			   			Mussum|     Ipsum";
	xpect_syntax_validation = 101; // begining with double quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_double_quote_broken_space_before_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "		    					\" Mussum|		Ipsum";
	xpect_syntax_validation = 101; // begining with double quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}


MU_TEST(testing_syntax_state100_double_quote_working_simple_space_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "\" Mussum| Ipsum \"";
	xpect_syntax_validation = 100; // ending with double quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_double_quote_working_space_after_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "Mussum|\"     Ipsum\"   			   			";
	xpect_syntax_validation = 100; // ending with double quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state100_double_quote_working_space_before_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = " Mussum|		\"Ipsum		    					\"";
	xpect_syntax_validation = 100; // ending with double quote - working
	expect_check_initial_errors = true;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_double_quote_broken_simple_space_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = " Mussum| Ipsum \"";
	xpect_syntax_validation = 101; // ending with double quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_double_quote_broken_space_after_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "Mussum|     Ipsum\"   			   			";
	xpect_syntax_validation = 101; // ending with double quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state101_double_quote_broken_space_before_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				expect_check_initial_errors;
	int				actual_check_initial_errors;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = " Mussum|		Ipsum		    					\"";
	xpect_syntax_validation = 101; // ending with double quote - broken
	expect_check_initial_errors = false;
	actual_check_initial_errors = check_initial_errors(userinput);
	if (actual_check_initial_errors == true)
	{
		idx = 0;
		lst = NULL;
		get_state(idx, userinput, &lst);
		actual_syntax_validation = syntax_validations(lst);
	}
	else
		actual_syntax_validation = 101;

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(expect_check_initial_errors, actual_check_initial_errors);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}


MU_TEST_SUITE(test07___syntax_state100_single_quote_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state100_single_quote_working_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state100_single_quote_working_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state100_single_quote_working_space_before_first_node);
	MU_RUN_TEST(testing_syntax_state101_single_quote_broken_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state101_single_quote_broken_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state101_single_quote_broken_space_before_first_node);
}

MU_TEST_SUITE(test07___syntax_state100_single_quote_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state100_single_quote_working_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state100_single_quote_working_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state100_single_quote_working_space_before_last_node);
	MU_RUN_TEST(testing_syntax_state101_single_quote_broken_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state101_single_quote_broken_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state101_single_quote_broken_space_before_last_node);
}

MU_TEST_SUITE(test07___syntax_state100_double_quote_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state100_double_quote_working_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state100_double_quote_working_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state100_double_quote_working_space_before_first_node);
	MU_RUN_TEST(testing_syntax_state101_double_quote_broken_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state101_double_quote_broken_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state101_double_quote_broken_space_before_first_node);
}

MU_TEST_SUITE(test07___syntax_state100_double_quote_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state100_double_quote_working_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state100_double_quote_working_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state100_double_quote_working_space_before_last_node);
	MU_RUN_TEST(testing_syntax_state101_double_quote_broken_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state101_double_quote_broken_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state101_double_quote_broken_space_before_last_node);
}
