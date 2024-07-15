/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test05_tokens_06_to_10.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/15 10:14:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

MU_TEST(testing_userinput_token_10)
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
	char			*xpect_node_06_lexeme;
	char			*xpect_node_06_type;
	char			*xpect_node_07_lexeme;
	char			*xpect_node_07_type;
	char			*xpect_node_08_lexeme;
	char			*xpect_node_08_type;
	char			*xpect_node_09_lexeme;
	char			*xpect_node_09_type;
	char			*xpect_node_10_lexeme;
	char			*xpect_node_10_type;
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
	char			*actual_node_06_lexeme;
	char			*actual_node_06_type;
	char			*actual_node_07_lexeme;
	char			*actual_node_07_type;
	char			*actual_node_08_lexeme;
	char			*actual_node_08_type;
	char			*actual_node_09_lexeme;
	char			*actual_node_09_type;
	char			*actual_node_10_lexeme;
	char			*actual_node_10_type;
	t_token_list	*lst;

	//ACT
	userinput = "/bin/ls | pwd | grep >> teste.txt > teste1.txt cat";

	xpect_node_01_type = get_token_string(WORD);
	xpect_node_01_lexeme = "/bin/ls";
	xpect_node_02_type = get_token_string(PIPE);
	xpect_node_02_lexeme = NULL;
	xpect_node_03_type = get_token_string(WORD);
	xpect_node_03_lexeme = "pwd";
	xpect_node_04_type = get_token_string(PIPE);
	xpect_node_04_lexeme = NULL;
	xpect_node_05_type = get_token_string(WORD);
	xpect_node_05_lexeme = "grep";
	xpect_node_06_type = get_token_string(REDIR_OUTAPP);
	xpect_node_06_lexeme = NULL;
	xpect_node_07_type = get_token_string(WORD);
	xpect_node_07_lexeme = "teste.txt";
	xpect_node_08_type = get_token_string(REDIR_OUT);
	xpect_node_08_lexeme = NULL;
	xpect_node_09_type = get_token_string(WORD);
	xpect_node_09_lexeme = "teste1.txt";
	xpect_node_10_type = get_token_string(WORD);
	xpect_node_10_lexeme = "cat";
	xpect_lst_size = 10;
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
	lst = lst->next;
	actual_node_06_lexeme = lst->lexeme;
	actual_node_06_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_07_lexeme = lst->lexeme;
	actual_node_07_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_08_lexeme = lst->lexeme;
	actual_node_08_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_09_lexeme = lst->lexeme;
	actual_node_09_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node_10_lexeme = lst->lexeme;
	actual_node_10_type = get_token_string(lst->type);
	
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
	mu_assert_string_eq(xpect_node_06_lexeme, actual_node_06_lexeme);
	mu_assert_string_eq(xpect_node_06_type, actual_node_06_type);
	mu_assert_string_eq(xpect_node_07_lexeme, actual_node_07_lexeme);
	mu_assert_string_eq(xpect_node_07_type, actual_node_07_type);
	mu_assert_string_eq(xpect_node_08_lexeme, actual_node_08_lexeme);
	mu_assert_string_eq(xpect_node_08_type, actual_node_08_type);
	mu_assert_string_eq(xpect_node_09_lexeme, actual_node_09_lexeme);
	mu_assert_string_eq(xpect_node_09_type, actual_node_09_type);
	mu_assert_string_eq(xpect_node_10_lexeme, actual_node_10_lexeme);
	mu_assert_string_eq(xpect_node_10_type, actual_node_10_type);
}

MU_TEST_SUITE(test05___06_to_10_tokens_suite)
{
	MU_RUN_TEST(testing_userinput_token_10);
}
