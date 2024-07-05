/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test04_syntax_first_last_node.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:01:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/05 17:09:58 by umeneses         ###   ########.fr       */
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
	actual_syntax_validation = check_first_and_last_node(lst);

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
	actual_syntax_validation = check_first_and_last_node(lst);

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
	actual_syntax_validation = check_first_and_last_node(lst);

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
	actual_syntax_validation = check_first_and_last_node(lst);

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
	actual_syntax_validation = check_first_and_last_node(lst);

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
	actual_syntax_validation = check_first_and_last_node(lst);

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
	actual_syntax_validation = check_first_and_last_node(lst);

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
	actual_syntax_validation = check_first_and_last_node(lst);

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
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_close_parentis_simple_space)
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
	userinput = ") Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_close_parentis_space_after)
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
	userinput = ")			                          Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_first_node_close_parentis_space_before)
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
	userinput = "			                          )Mussum|Ipsum";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_pipe_simple_space)
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
	userinput = "Mussum|Ipsum |";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_pipe_space_after)
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
	userinput = "Mussum|Ipsum|			                          ";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_pipe_space_before)
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
	userinput = "Mussum|Ipsum			                          |";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_OR_simple_space)
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
	userinput = "Mussum|Ipsum|| ";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_OR_space_after)
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
	userinput = "Mussum|Ipsum||			                          ";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_OR_space_before)
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
	userinput = "Mussum|Ipsum			                          ||";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_AND_simple_space)
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
	userinput = "Mussum|Ipsum&& ";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_AND_space_after)
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
	userinput = "Mussum|Ipsum&&			                          ";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_AND_space_before)
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
	userinput = "Mussum|Ipsum			                          &&";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_close_parentis_simple_space)
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
	userinput = "Mussum|Ipsum) ";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_close_parentis_space_after)
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
	userinput = "Mussum|Ipsum)			                          ";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_last_node_close_parentis_space_before)
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
	userinput = "Mussum|Ipsum			                          )";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_pipe_pipe)
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
	userinput = "|	|";
	xpect_syntax_validation = false;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_pipe_dollar_sign)
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
	userinput = "|	$";
	xpect_syntax_validation = false;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_pipe_redirect_output)
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
	userinput = "| >";
	xpect_syntax_validation = false;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_redirect_output)
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
	userinput = ">";
	xpect_syntax_validation = false;
	xpect_lst_size = 1;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_redirect_output_append)
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
	userinput = ">>";
	xpect_syntax_validation = false;
	xpect_lst_size = 1;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_redirect_input)
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
	userinput = "<";
	xpect_syntax_validation = false;
	xpect_lst_size = 1;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_redirect_heredoc)
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
	userinput = "<<";
	xpect_syntax_validation = false;
	xpect_lst_size = 1;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_echo_hi_redirect_input)
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
	userinput = "echo hi <";
	xpect_syntax_validation = false;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_cat_redirect_input_ls)
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
	userinput = "cat	 	<| ls";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_echo_hi_pipe_redirect_output)
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
	userinput = "echo hi | >";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_echo_hi_pipe_redirect_output_output_append)
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
	userinput = "echo hi | > >>";
	xpect_syntax_validation = false;
	xpect_lst_size = 5;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_echo_hi_pipe_redirect_input_pipe)
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
	userinput = "echo hi | < |";
	xpect_syntax_validation = false;
	xpect_lst_size = 5;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_echo_hi_pipe_pipe)
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
	userinput = "echo hi |	|";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_echo_hi_pipe_double_quotes)
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
	userinput = "echo hi |	\"|\"";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_first_and_last_node(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST_SUITE(testing_syntax_first_node_errors_suite)
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
	MU_RUN_TEST(testing_syntax_first_node_close_parentis_simple_space);
	MU_RUN_TEST(testing_syntax_first_node_close_parentis_space_after);
	MU_RUN_TEST(testing_syntax_first_node_close_parentis_space_before);
}

MU_TEST_SUITE(testing_syntax_last_node_errors_suite)
{
	MU_RUN_TEST(testing_syntax_last_node_pipe_simple_space);
	MU_RUN_TEST(testing_syntax_last_node_pipe_space_after);
	MU_RUN_TEST(testing_syntax_last_node_pipe_space_before);
	MU_RUN_TEST(testing_syntax_last_node_OR_simple_space);
	MU_RUN_TEST(testing_syntax_last_node_OR_space_after);
	MU_RUN_TEST(testing_syntax_last_node_OR_space_before);
	MU_RUN_TEST(testing_syntax_last_node_AND_simple_space);
	MU_RUN_TEST(testing_syntax_last_node_AND_space_after);
	MU_RUN_TEST(testing_syntax_last_node_AND_space_before);
	MU_RUN_TEST(testing_syntax_last_node_close_parentis_simple_space);
	MU_RUN_TEST(testing_syntax_last_node_close_parentis_space_after);
	MU_RUN_TEST(testing_syntax_last_node_close_parentis_space_before);
}

MU_TEST_SUITE(testing_syntax_few_nodes_pipe_errors_suite)
{
	MU_RUN_TEST(testing_syntax_pipe_pipe);
	MU_RUN_TEST(testing_syntax_pipe_dollar_sign);
	MU_RUN_TEST(testing_syntax_pipe_redirect_output);
}

MU_TEST_SUITE(testing_syntax_few_nodes_redirect_errors_suite)
{
	MU_RUN_TEST(testing_syntax_redirect_output);
	MU_RUN_TEST(testing_syntax_redirect_output_append);
	MU_RUN_TEST(testing_syntax_redirect_input);
	MU_RUN_TEST(testing_syntax_redirect_heredoc);
	MU_RUN_TEST(testing_syntax_echo_hi_redirect_input);
	MU_RUN_TEST(testing_syntax_cat_redirect_input_ls);
}

MU_TEST_SUITE(testing_syntax_few_nodes_mix_errors_suite)
{
	MU_RUN_TEST(testing_syntax_echo_hi_pipe_redirect_output);
	MU_RUN_TEST(testing_syntax_echo_hi_pipe_redirect_output_output_append);
	MU_RUN_TEST(testing_syntax_echo_hi_pipe_redirect_input_pipe);
	MU_RUN_TEST(testing_syntax_echo_hi_pipe_pipe);
	MU_RUN_TEST(testing_syntax_echo_hi_pipe_double_quotes);
}
