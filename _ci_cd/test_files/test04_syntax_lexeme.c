/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test04_syntax_lexeme.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:01:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/02 17:36:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_syntax_lexeme_odd_double_odd_single_quotes)
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
	userinput = "Mussum Ipsum, \"cacilds \'vidis litro abertis";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_lexeme(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_lexeme_even_double_odd_single_quotes)
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
	userinput = "Mussum Ipsum, \"cacilds\" \'vidis litro abertis";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_lexeme(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_lexeme_odd_double_even_single_quotes)
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
	userinput = "Mussum Ipsum, \"cacilds \'vidis\' litro abertis";
	xpect_syntax_validation = false;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_lexeme(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST(testing_syntax_lexeme_even_double_even_single_quotes)
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
	userinput = "Mussum Ipsum, \"cacilds\" \'vidis\' litro abertis";
	xpect_syntax_validation = true;
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_syntax_validation = check_lexeme(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_syntax_validation, actual_syntax_validation);
}

MU_TEST_SUITE(testing_syntax_lemexe_errors_suite)
{
	MU_RUN_TEST(testing_syntax_lexeme_odd_double_odd_single_quotes);
	MU_RUN_TEST(testing_syntax_lexeme_even_double_odd_single_quotes);
	MU_RUN_TEST(testing_syntax_lexeme_odd_double_even_single_quotes);
	MU_RUN_TEST(testing_syntax_lexeme_even_double_even_single_quotes);

}