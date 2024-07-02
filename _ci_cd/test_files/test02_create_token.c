/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:00:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/02 10:08:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_create_token_list)
{
	// ARRANGE
	char			*userinput;
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
	int				xpect_create_token_list;
	char			*actual_node_01_lexeme;
	char			*actual_node_01_type;
	char			*actual_node_02_lexeme;
	char			*actual_node_02_type;
	char			*actual_node_03_lexeme;
	char			*actual_node_03_type;
	char			*actual_node_04_lexeme;
	char			*actual_node_04_type;
	int				actual_create_token_list;
	t_token_list	*lst;

	//ACT
	userinput = "cat Makefile | wc";

	xpect_node_01_type = get_token_string(WORD);
	xpect_node_01_lexeme = "cat";
	xpect_node_02_type = get_token_string(WORD);
	xpect_node_02_lexeme = "Makefile";
	xpect_node_03_type = get_token_string(PIPE);
	xpect_node_03_lexeme = NULL;
	xpect_node_04_type = get_token_string(WORD);
	xpect_node_04_lexeme = "wc";
	xpect_lst_size = 4;
	xpect_create_token_list = true;
	lst = NULL;

	actual_create_token_list = create_token_list(userinput, &lst);

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

	//ASSERT
	mu_assert_int_eq(xpect_create_token_list, actual_create_token_list);
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node_01_lexeme, actual_node_01_lexeme);
	mu_assert_string_eq(xpect_node_01_type, actual_node_01_type);
	mu_assert_string_eq(xpect_node_02_lexeme, actual_node_02_lexeme);
	mu_assert_string_eq(xpect_node_02_type, actual_node_02_type);
	mu_assert_string_eq(xpect_node_03_lexeme, actual_node_03_lexeme);
	mu_assert_string_eq(xpect_node_03_type, actual_node_03_type);
	mu_assert_string_eq(xpect_node_04_lexeme, actual_node_04_lexeme);
	mu_assert_string_eq(xpect_node_04_type, actual_node_04_type);
}

MU_TEST_SUITE(testing_lexer_tests)
{
	MU_RUN_TEST(testing_create_token_list);
}
