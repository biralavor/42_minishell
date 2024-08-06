/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test10_syntax_state400.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:31:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/18 14:44:03 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"


MU_TEST(testing_syntax_state400_SUBSHELL_first_node)
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
	userinput = "(Não sou faixa preta) cumpadi sou preto inteiris";
	xpect_syntax_validation = 400; // begining with redirect input
	xpect_lst_size = 5;
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

MU_TEST(testing_syntax_state400_SUBSHELL_middle_node)
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
	userinput = "Não sou faixa preta (cumpadi) sou preto inteiris";
	xpect_syntax_validation = 400; // begining with redirect input
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

MU_TEST(testing_syntax_state400_SUBSHELL_last_node)
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
	userinput = "Não sou faixa preta cumpadi sou (preto inteiris)";
	xpect_syntax_validation = 400; // begining with redirect input
	xpect_lst_size = 7;
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

MU_TEST_SUITE(test10___syntax_state400_SUBSHELL_suite)
{
	MU_RUN_TEST(testing_syntax_state400_SUBSHELL_first_node);
	MU_RUN_TEST(testing_syntax_state400_SUBSHELL_middle_node);
	MU_RUN_TEST(testing_syntax_state400_SUBSHELL_last_node);
}
