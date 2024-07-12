/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test09_syntax_state300.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:01:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/12 15:32:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"


MU_TEST(testing_syntax_state300_REDIRECT_INPUT_simple_space_first_node)
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
	userinput = "< Mussum|Ipsum";
	xpect_syntax_validation = 300; // begining with redirect input
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

MU_TEST(testing_syntax_state300_REDIRECT_INPUT_space_after_first_node)
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
	userinput = "<			                          Mussum|Ipsum";
	xpect_syntax_validation = 300; // begining with redirect input
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

MU_TEST(testing_syntax_state300_REDIRECT_INPUT_space_before_first_node)
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
	userinput = "			                          <Mussum|Ipsum";
	xpect_syntax_validation = 300; // begining with redirect input
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

MU_TEST(testing_syntax_state300_REDIRECT_INPUT_simple_space_last_node)
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
	userinput = "Mussum|Ipsum<";
	xpect_syntax_validation = 301; // ending with redirect input
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

MU_TEST(testing_syntax_state300_REDIRECT_INPUT_space_after_last_node)
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
	userinput = "Mussum|Ipsum<			                          ";
	xpect_syntax_validation = 301; // ending with redirect input
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

MU_TEST(testing_syntax_state300_REDIRECT_INPUT_space_before_last_node)
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
	userinput = "Mussum|Ipsum			                          <";
	xpect_syntax_validation = 301; // ending with redirect input
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_simple_space_first_node)
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
	xpect_syntax_validation = 300; // begining with redirect output
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_space_after_first_node)
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
	xpect_syntax_validation = 300; // begining with redirect output
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_space_before_first_node)
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
	xpect_syntax_validation = 300; // begining with redirect output
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_simple_space_last_node)
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
	userinput = "Mussum|Ipsum >";
	xpect_syntax_validation = 301; // ending with redirect output
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_space_after_last_node)
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
	userinput = "Mussum|Ipsum>			                          ";
	xpect_syntax_validation = 301; // ending with redirect output
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_space_before_last_node)
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
	userinput = "Mussum|Ipsum			                          >";
	xpect_syntax_validation = 301; // ending with redirect output
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_simple_space_first_node)
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
	userinput = ">> Mussum|Ipsum";
	xpect_syntax_validation = 300; // begining with redirect output append
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_space_after_first_node)
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
	userinput = ">>			                          Mussum|Ipsum";
	xpect_syntax_validation = 300; // begining with redirect output append
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_space_before_first_node)
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
	userinput = "			                          >>Mussum|Ipsum";
	xpect_syntax_validation = 300; // begining with redirect output append
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_simple_space_last_node)
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
	userinput = "Mussum|Ipsum>>";
	xpect_syntax_validation = 301; // ending with redirect output append
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_space_after_last_node)
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
	userinput = "Mussum|Ipsum>>			                          ";
	xpect_syntax_validation = 301; // ending with redirect output append
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

MU_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_space_before_last_node)
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
	userinput = "Mussum|Ipsum			                          >>";
	xpect_syntax_validation = 301; // ending with redirect output append
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

MU_TEST(testing_syntax_state300_REDIRECT_HEREDOC_simple_space_first_node)
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
	userinput = "<< Mussum|Ipsum";
	xpect_syntax_validation = 300; // begining with redirect heredoc
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

MU_TEST(testing_syntax_state300_REDIRECT_HEREDOC_space_after_first_node)
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
	userinput = "<<			                          Mussum|Ipsum";
	xpect_syntax_validation = 300; // begining with redirect heredoc
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

MU_TEST(testing_syntax_state300_REDIRECT_HEREDOC_space_before_first_node)
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
	userinput = "			                          <<Mussum|Ipsum";
	xpect_syntax_validation = 300; // begining with redirect heredoc
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

MU_TEST(testing_syntax_state300_REDIRECT_HEREDOC_simple_space_last_node)
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
	userinput = "Mussum|Ipsum<<";
	xpect_syntax_validation = 301; // ending with redirect heredoc
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

MU_TEST(testing_syntax_state300_REDIRECT_HEREDOC_space_after_last_node)
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
	userinput = "Mussum|Ipsum<<			                          ";
	xpect_syntax_validation = 301; // ending with redirect heredoc
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

MU_TEST(testing_syntax_state300_REDIRECT_HEREDOC_space_before_last_node)
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
	userinput = "Mussum|Ipsum			                          <<";
	xpect_syntax_validation = 301; // ending with redirect heredoc
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

MU_TEST(testing_syntax_state300_cadet_REDIRECT_OUTPUT_solo)
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
	userinput = ">";
	xpect_syntax_validation = 301; // cadet test
	xpect_lst_size = 1;
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

MU_TEST(testing_syntax_state300_cadet_REDIRECT_OUTPUT_APPEND_solo)
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
	userinput = ">>";
	xpect_syntax_validation = 301; // cadet test
	xpect_lst_size = 1;
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

MU_TEST(testing_syntax_state300_cadet_REDIRECT_INPUT_solo)
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
	userinput = "<";
	xpect_syntax_validation = 301; // cadet test
	xpect_lst_size = 1;
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

MU_TEST(testing_syntax_state300_cadet_REDIRECT_HEREDOC_solo)
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
	userinput = "<<";
	xpect_syntax_validation = 301; // cadet test
	xpect_lst_size = 1;
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

MU_TEST(testing_syntax_state300_cadet_echo_hi_REDIRECT_INPUT)
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
	userinput = "echo hi <";
	xpect_syntax_validation = 301; // cadet test
	xpect_lst_size = 3;
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

MU_TEST(testing_syntax_state300_cadet_cat_REDIRECT_INPUT_PIPE_ls)
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
	userinput = "cat	 	<| ls";
	xpect_syntax_validation = 301; // cadet test
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

MU_TEST_SUITE(test09___syntax_state300_REDIRECT_INPUT_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_INPUT_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_INPUT_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_INPUT_space_before_first_node);
}

MU_TEST_SUITE(test09___syntax_state300_REDIRECT_INPUT_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_INPUT_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_INPUT_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_INPUT_space_before_last_node);
}

MU_TEST_SUITE(test09___syntax_state300_REDIRECT_OUTPUT_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_space_before_first_node);
}

MU_TEST_SUITE(test09___syntax_state300_REDIRECT_OUTPUT_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_space_before_last_node);
}

MU_TEST_SUITE(test09___syntax_state300_REDIRECT_OUTPUT_APPEND_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_space_before_first_node);
}

MU_TEST_SUITE(test09___syntax_state300_REDIRECT_OUTPUT_APPEND_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_OUTPUT_APPEND_space_before_last_node);
}

MU_TEST_SUITE(test09___syntax_state300_REDIRECT_HEREDOC_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_HEREDOC_simple_space_first_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_HEREDOC_space_after_first_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_HEREDOC_space_before_first_node);
}

MU_TEST_SUITE(test09___syntax_state300_REDIRECT_HEREDOC_errors_last_node_suite)
{
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_HEREDOC_simple_space_last_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_HEREDOC_space_after_last_node);
	MU_RUN_TEST(testing_syntax_state300_REDIRECT_HEREDOC_space_before_last_node);
}

MU_TEST_SUITE(test09___syntax_state300_cadet_MIXED_REDIRECT_errors_suite)
{
	MU_RUN_TEST(testing_syntax_state300_cadet_REDIRECT_OUTPUT_solo);
	MU_RUN_TEST(testing_syntax_state300_cadet_REDIRECT_OUTPUT_APPEND_solo);
	MU_RUN_TEST(testing_syntax_state300_cadet_REDIRECT_INPUT_solo);
	MU_RUN_TEST(testing_syntax_state300_cadet_REDIRECT_HEREDOC_solo);
	MU_RUN_TEST(testing_syntax_state300_cadet_echo_hi_REDIRECT_INPUT);
	MU_RUN_TEST(testing_syntax_state300_cadet_cat_REDIRECT_INPUT_PIPE_ls);
}
