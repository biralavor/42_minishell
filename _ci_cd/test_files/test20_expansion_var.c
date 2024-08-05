/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test20_expansion_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:09:21 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/05 16:35:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_variable_expansion_detection_simple)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_expand_detection;
	bool			actual_expand_detection;
	// char			*xpect_expand_var_name;
	// char			*actual_expand_var_name;
	// int				xpect_expand_var_value;
	// int				actual_expand_var_value;
	int				fd;
	t_token_list	*lst;

	// ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = " echo $MINISHELL=42";
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	xpect_expand_detection = true;
	// xpect_expand_var_name = "MINISHELL"; // begining (and or not) with dollar sign
	// xpect_expand_var_value = 42; // begining with close parenthesis
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	
	xpect_expand_detection = variable_detector(lst);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_expand_detection, actual_expand_detection);
}

MU_TEST_SUITE(test20___expansion_var_suite)
{
	MU_RUN_TEST(testing_variable_expansion_detection_simple);
}