/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokens_03_to_05.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/24 22:49:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

MU_TEST(check_userinput_token_05)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node_01_lexeme;
	char			*xpect_node_01_type;
	char			*xpect_node_02_lexeme;
	char			*xpect_node_02_type;
	char			*xpect_node_03_lexeme;
	char			*xpect_node_03_type;
	char			*xpect_node_04_lexeme;
	char			*xpect_node_04_type;
	char			*xpect_node_05_lexeme;
	char			*xpect_node_05_type;
	char			*actual_node_01_lexeme;
	char			*actual_node_01_type;
	char			*actual_node_02_lexeme;
	char			*actual_node_02_type;
	char			*actual_node_03_lexeme;
	char			*actual_node_03_type;
	char			*actual_node_04_lexeme;
	char			*actual_node_04_type;
	char			*actual_node_05_lexeme;
	char			*actual_node_05_type;
	t_token_list	*lst;

	//ACT
	userinput = ">t2 ls | \"'hello world'\"";

	xpect_node_01_type = get_token_string(REDIRECT_OUTPUT);
	xpect_node_01_lexeme = NULL;
	xpect_node_02_type = get_token_string(WORD);
	xpect_node_02_lexeme = "t2";
	xpect_node_03_type = get_token_string(WORD);
	xpect_node_03_lexeme = "ls";
	xpect_node_04_type = get_token_string(PIPE);
	xpect_node_04_lexeme = NULL;
	xpect_node_05_type = get_token_string(WORD);
	xpect_node_05_lexeme = "\"'hello world'\"";
	xpect_lst_size = 5;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	
	actual_lst_size = ft_lst_size(lst);
	actual_node_01_lexeme = lst->lexeme;
	actual_node_01_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_02_lexeme = lst->lexeme;
	actual_node_02_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_03_lexeme = lst->lexeme;
	actual_node_03_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_04_lexeme = lst->lexeme;
	actual_node_04_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_05_lexeme = lst->lexeme;
	actual_node_05_type = get_token_string(lst->type);

	//ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node_01_lexeme, actual_node_01_lexeme);
	mu_assert_string_eq(xpect_node_01_type, actual_node_01_type);
	mu_assert_string_eq(xpect_node_02_lexeme, actual_node_02_lexeme);
	mu_assert_string_eq(xpect_node_02_type, actual_node_02_type);
	mu_assert_string_eq(xpect_node_03_lexeme, actual_node_03_lexeme);
	mu_assert_string_eq(xpect_node_03_type, actual_node_03_type);
	mu_assert_string_eq(xpect_node_04_lexeme, actual_node_04_lexeme);
	mu_assert_string_eq(xpect_node_04_type, actual_node_04_type);
	mu_assert_string_eq(xpect_node_05_lexeme, actual_node_05_lexeme);
	mu_assert_string_eq(xpect_node_05_type, actual_node_05_type);
}

MU_TEST_SUITE(check_03_to_05_tokens_tests)
{
	MU_RUN_TEST(check_userinput_token_05);
}
