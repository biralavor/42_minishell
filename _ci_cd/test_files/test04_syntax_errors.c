/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test04_syntax_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:01:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/02 14:09:08 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_syntax_first_node_pipe_simple_space)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	t_token_list	*lst;

	//ACT
	userinput = "| Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_pipe_space_after)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	t_token_list	*lst;

	//ACT
	userinput = "|			                          Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_pipe_space_before)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	int				xpect_syntax_validation;
	int				actual_syntax_validation;
	t_token_list	*lst;

	//ACT
	userinput = "			                          |Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_node(lst);

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
	t_token_list	*lst;

	//ACT
	userinput = "|| Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_node(lst);

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
	t_token_list	*lst;

	//ACT
	userinput = "||			                          Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_node(lst);

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
	t_token_list	*lst;

	//ACT
	userinput = "			                          ||Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_node(lst);

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
	t_token_list	*lst;

	//ACT
	userinput = "&& Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_node(lst);

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
	t_token_list	*lst;

	//ACT
	userinput = "&&			                          Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_node(lst);

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
	t_token_list	*lst;

	//ACT
	userinput = "			                          &&Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST_SUITE(testing_syntax_errors_suite)
{
	MU_RUN_TEST(testing_syntax_first_node_pipe_simple_space);
	MU_RUN_TEST(testing_syntax_first_node_pipe_space_after);
	MU_RUN_TEST(testing_syntax_first_node_pipe_space_before);
	MU_RUN_TEST(testing_syntax_first_node_OR_simple_space);
	MU_RUN_TEST(testing_syntax_first_node_OR_space_after);
	MU_RUN_TEST(testing_syntax_first_node_OR_space_before);
	MU_RUN_TEST(testing_syntax_first_node_AND_simple_space);
	MU_RUN_TEST(testing_syntax_first_node_AND_space_after);
	MU_RUN_TEST(testing_syntax_first_node_AND_space_before);
}