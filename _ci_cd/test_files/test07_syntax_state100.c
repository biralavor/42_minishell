/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test07_syntax_state100.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:30:19 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/18 12:37:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_syntax_state100_WORD_working)
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
	userinput = "Mussum Ipsum, cacilds vidis litro abertis";
	xpect_syntax_validation = 100; // only WORDs
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

MU_TEST(testing_syntax_state100_WORD_broken_backslash)
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
	userinput = "Não sou faixa preta cumpadi\\ sou preto inteiris";
	xpect_syntax_validation = 101; // detects backslash error
	xpect_lst_size = 8;
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

MU_TEST(testing_syntax_state100_WORD_broken_ampersand)
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
	userinput = "Diuretics paradis num copo& é motivis de denguis";
	xpect_syntax_validation = 101; // detects ampersand error
	xpect_lst_size = 9;
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

MU_TEST(testing_syntax_state100_WORD_broken_semicolon)
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
	userinput = "Tá deprimidis; eu conheço uma cachacis";
	xpect_syntax_validation = 101; // detects semicolon error
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

MU_TEST_SUITE(test07___syntax_state100_WORDS_errors_first_node_suite)
{
	MU_RUN_TEST(testing_syntax_state100_WORD_working);
	MU_RUN_TEST(testing_syntax_state100_WORD_broken_backslash);
	MU_RUN_TEST(testing_syntax_state100_WORD_broken_ampersand);
	MU_RUN_TEST(testing_syntax_state100_WORD_broken_semicolon);
}