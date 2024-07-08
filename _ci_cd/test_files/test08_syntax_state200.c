/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test08_syntax_state200.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:01:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/08 19:37:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_syntax_state200_PIPE_simple_space_first_node)
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

MU_TEST(testing_syntax_state200_PIPE_space_after_first_node)
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

MU_TEST(testing_syntax_state200_PIPE_space_before_first_node)
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

MU_TEST(testing_syntax_state200_PIPE_simple_space_last_node)
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
	userinput = "Mussum|Ipsum |";
	xpect_syntax_validation = 201; // ending with PIPE, OR or AND
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

MU_TEST(testing_syntax_state200_PIPE_space_after_last_node)
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
	userinput = "Mussum|Ipsum|			                          ";
	xpect_syntax_validation = 201; // ending with PIPE, OR or AND
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

MU_TEST(testing_syntax_state200_PIPE_space_before_last_node)
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
	userinput = "Mussum|Ipsum			                          |";
	xpect_syntax_validation = 201; // ending with PIPE, OR or AND
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

MU_TEST(testing_syntax_state200_OR_simple_space_first_node)
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

MU_TEST(testing_syntax_state200_OR_space_after_first_node)
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

MU_TEST(testing_syntax_state200_OR_space_before_first_node)
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

MU_TEST(testing_syntax_state200_OR_simple_space_last_node)
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
	userinput = " Mussum|Ipsum||";
	xpect_syntax_validation = 201; // ending with PIPE, OR or AND
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

MU_TEST(testing_syntax_state200_OR_space_after_last_node)
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
	userinput = "Mussum|Ipsum||			                          ";
	xpect_syntax_validation = 201; // ending with PIPE, OR or AND
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

MU_TEST(testing_syntax_state200_OR_space_before_last_node)
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
	userinput = "Mussum|Ipsum			                          ||";
	xpect_syntax_validation = 201; // ending with PIPE, OR or AND
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

MU_TEST(testing_syntax_state200_AND_simple_space_first_node)
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

MU_TEST(testing_syntax_state200_AND_space_after_first_node)
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

MU_TEST(testing_syntax_state200_AND_space_before_first_node)
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

MU_TEST(testing_syntax_state200_AND_simple_space_last_node)
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
	userinput = "Mussum|Ipsum&&";
	xpect_syntax_validation = 201; // ending with PIPE, OR or AND
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

MU_TEST(testing_syntax_state200_AND_space_after_last_node)
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
	userinput = "Mussum|Ipsum&&			                          ";
	xpect_syntax_validation = 201; // ending with PIPE, OR or AND
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

MU_TEST(testing_syntax_state200_AND_space_before_last_node)
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
	userinput = "Mussum|Ipsum			                          &&";
	xpect_syntax_validation = 201; // ending with PIPE, OR or AND
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

MU_TEST(testing_syntax_state200_cadet_PIPE_PIPE)
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
	userinput = "|	|";
	xpect_syntax_validation = 201; // cadet test
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

MU_TEST(testing_syntax_state200_cadet_PIPE_dolar_sign)
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
	userinput = "|	$";
	xpect_syntax_validation = 201; // cadet test
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

MU_TEST(testing_syntax_state200_cadet_PIPE_redirect_output)
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
	userinput = "| >";
	xpect_syntax_validation = 201; // cadet test
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

MU_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_REDIRECT_INPUT_PIPE)
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
	userinput = "echo hi | < |";
	xpect_syntax_validation = 201; // cadet test
	xpect_lst_size = 5;
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

MU_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_PIPE)
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
	userinput = "echo hi |  |";
	xpect_syntax_validation = 201; // cadet test
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

MU_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_double_quotes)
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
	userinput = "echo hi |	\"|\"";
	xpect_syntax_validation = 201; // cadet test
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





MU_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_REDIRECT_OUTPUT_ls)
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
	userinput = "echo hi | >";
	xpect_syntax_validation = 201; // cadet test
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

MU_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_REDIRECT_OUTPUT_plus_APPEND)
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
	userinput = "echo hi | > >>";
	xpect_syntax_validation = 201; // cadet test
	xpect_lst_size = 5;
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

MU_TEST_SUITE(test08___syntax_state200_PIPE_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state200_PIPE_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state200_PIPE_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state200_PIPE_space_before_first_node);
}

MU_TEST_SUITE(test08___syntax_state200_PIPE_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state200_PIPE_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state200_PIPE_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state200_PIPE_space_before_last_node);
}

MU_TEST_SUITE(test08___syntax_state200_OR_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state200_OR_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state200_OR_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state200_OR_space_before_first_node);
}

MU_TEST_SUITE(test08___syntax_state200_OR_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state200_OR_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state200_OR_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state200_OR_space_before_last_node);
}

MU_TEST_SUITE(test08___syntax_state200_AND_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state200_AND_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state200_AND_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state200_AND_space_before_first_node);
}

MU_TEST_SUITE(test08___syntax_state200_AND_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state200_AND_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state200_AND_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state200_AND_space_before_last_node);
}

MU_TEST_SUITE(test08___syntax_state200_cadet_PIPE_errors_suite)
{
	MU_RUN_TEST(testing_syntax_state200_cadet_PIPE_PIPE);
	MU_RUN_TEST(testing_syntax_state200_cadet_PIPE_dolar_sign);
	MU_RUN_TEST(testing_syntax_state200_cadet_PIPE_redirect_output);
	MU_RUN_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_REDIRECT_INPUT_PIPE);
	MU_RUN_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_PIPE);
	MU_RUN_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_double_quotes);
}

MU_TEST_SUITE(test08___syntax_state200_cadet_MIXED_PIPE_errors_suite)
{
	MU_RUN_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_REDIRECT_OUTPUT_ls);
	MU_RUN_TEST(testing_syntax_state200_cadet_echo_hi_PIPE_REDIRECT_OUTPUT_plus_APPEND);
}
