/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test03_tokens_01_to_02.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/02 18:17:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(testing_userinput_token_empty)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node_01_lexeme;
	char			*xpect_node_01_type;
	char			*actual_node_01_lexeme;
	char			*actual_node_01_type;
	t_token_list	*lst;

	//ACT
	userinput = "";

	xpect_node_01_type = NULL;
	xpect_node_01_lexeme = NULL;
	xpect_lst_size = 0;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	if (lst == NULL)
	{
		actual_lst_size = 0;
		actual_node_01_lexeme = NULL;
		actual_node_01_type = NULL;
	}
	else
	{
		actual_lst_size = ft_lst_size(lst);
		actual_node_01_lexeme = lst->lexeme;
		actual_node_01_type = get_token_string(lst->type);
	}
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node_01_lexeme, actual_node_01_lexeme);
	mu_assert_string_eq(xpect_node_01_type, actual_node_01_type);
}

MU_TEST(testing_userinput_token_02_word_with_space)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node1_lexeme;
	char			*xpect_node1_type;
	char			*xpect_node2_lexeme;
	char			*xpect_node2_type;
	char			*xpect_node3_lexeme;
	char			*xpect_node3_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	t_token_list	*lst;

	//ACT
	userinput = "Mussum Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = NULL;
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	if (actual_lst_size == 2 && lst->next->next == NULL)
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		actual_node3_lexeme = NULL;
		actual_node3_type = NULL;
	}
	else
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node3_lexeme = lst->lexeme;
		actual_node3_type = get_token_string(lst->type);
	}

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(testing_userinput_token_02_word_with_tab_v01)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node1_lexeme;
	char			*xpect_node1_type;
	char			*xpect_node2_lexeme;
	char			*xpect_node2_type;
	char			*xpect_node3_lexeme;
	char			*xpect_node3_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	t_token_list	*lst;

	//ACT
	userinput = "Mussum	Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = NULL;
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	if (actual_lst_size == 2 && lst->next->next == NULL)
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		actual_node3_lexeme = NULL;
		actual_node3_type = NULL;
	}
	else
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node3_lexeme = lst->lexeme;
		actual_node3_type = get_token_string(lst->type);
	}

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(testing_userinput_token_02_word_with_tab_v02)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	char			*xpect_node1_lexeme;
	char			*xpect_node1_type;
	char			*xpect_node2_lexeme;
	char			*xpect_node2_type;
	char			*xpect_node3_lexeme;
	char			*xpect_node3_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	t_token_list	*lst;

	//ACT
	userinput = "	Mussum	Ipsum	";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = NULL;
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	if (actual_lst_size == 2 && lst->next->next == NULL)
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		actual_node3_lexeme = NULL;
		actual_node3_type = NULL;
	}
	else
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node3_lexeme = lst->lexeme;
		actual_node3_type = get_token_string(lst->type);
	}

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST_SUITE(testing_01_to_02_tokens_suite)
{
	MU_RUN_TEST(testing_userinput_token_empty);
	MU_RUN_TEST(testing_userinput_token_02_word_with_space);
	MU_RUN_TEST(testing_userinput_token_02_word_with_tab_v01);
	MU_RUN_TEST(testing_userinput_token_02_word_with_tab_v02);
}
