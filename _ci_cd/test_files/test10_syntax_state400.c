/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test10_syntax_state400.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:01:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/12 15:44:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"
#include <stdio.h>

MU_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_simple_space_first_node)
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
	xpect_syntax_validation = 802; // begining with close parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_space_after_first_node)
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
	xpect_syntax_validation = 802; // begining with close parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_space_before_first_node)
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
	xpect_syntax_validation = 802; // begining with close parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_simple_space_last_node)
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
	userinput = "Mussum|Ipsum)";
	xpect_syntax_validation = 802; // ending with close parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_space_after_last_node)
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
	userinput = "Mussum|Ipsum)			                          ";
	xpect_syntax_validation = 802; // ending with close parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_space_before_last_node)
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
	userinput = "Mussum|Ipsum			                          )";
	xpect_syntax_validation = 802; // ending with close parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_OPEN_PARENTHESIS_simple_space_first_node)
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
	userinput = "( Mussum|Ipsum";
	xpect_syntax_validation = 802; // begining with OPEN parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_OPEN_PARENTHESIS_space_after_first_node)
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
	userinput = "(			                          Mussum|Ipsum";
	xpect_syntax_validation = 802; // begining with OPEN parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_OPEN_PARENTHESIS_space_before_first_node)
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
	userinput = "			                          (Mussum|Ipsum";
	xpect_syntax_validation = 802; // begining with OPEN parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_OPEN_PARENTHESIS_simple_space_last_node)
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
	userinput = "Mussum|Ipsum(";
	xpect_syntax_validation = 802; // ending with OPEN parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_OPEN_PARENTHESIS_space_after_last_node)
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
	userinput = "Mussum|Ipsum(			                          ";
	xpect_syntax_validation = 802; // ending with OPEN parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_OPEN_PARENTHESIS_space_before_last_node)
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
	userinput = "Mussum|Ipsum			                          (";
	xpect_syntax_validation = 802; // ending with OPEN parenthesis
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_OPEN_PARENTHESIS_odd_counter_first_node)
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
	userinput = "( Mussum|(Ipsum)";
	xpect_syntax_validation = 802; // begining with OPEN parenthesis, odd counter
	xpect_lst_size = 6;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_odd_counter_first_node)
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
	userinput = "( Mussum)|Ipsum)";
	xpect_syntax_validation = 802; // begining with CLOSE parenthesis, odd counter
	xpect_lst_size = 6;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	while (lst)
	{
		actual_syntax_validation = syntax_validations(lst);
		lst = lst->next;
		if (actual_syntax_validation == xpect_syntax_validation)
			break ;
	}

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST_SUITE(test10___syntax_state400_CLOSE_PARENTHESIS_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_space_before_first_node);
}

MU_TEST_SUITE(test10___syntax_state400_CLOSE_PARENTHESIS_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_space_before_last_node);
}

MU_TEST_SUITE(test10___syntax_state400_OPEN_PARENTHESIS_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state400_OPEN_PARENTHESIS_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state400_OPEN_PARENTHESIS_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state400_OPEN_PARENTHESIS_space_before_first_node);
}

MU_TEST_SUITE(test10___syntax_state400_OPEN_PARENTHESIS_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state400_OPEN_PARENTHESIS_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state400_OPEN_PARENTHESIS_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state400_OPEN_PARENTHESIS_space_before_last_node);
}

MU_TEST_SUITE(test10___syntax_state400_MIXED_PARENTHESIS_odd_counter_errors_suite)
{
	MU_RUN_TEST(testing_syntax_state400_OPEN_PARENTHESIS_odd_counter_first_node);
	MU_RUN_TEST(testing_syntax_state400_CLOSE_PARENTHESIS_odd_counter_first_node);

}
