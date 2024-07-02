/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test03_tokens_cadet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:16:24 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/02 18:18:41 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

// MU_TEST(testing_cadet_input_token_02_hello_world)
// {
// 	// ARRANGE
// 	char			*cadet_input;
// 	int				idx;
// 	int				xpect_lst_size;
// 	int				actual_lst_size;
// 	char			*xpect_node1_lexeme;
// 	char			*xpect_node1_type;
// 	char			*xpect_node2_lexeme;
// 	char			*xpect_node2_type;
// 	char			*xpect_node3_lexeme;
// 	char			*xpect_node3_type;
// 	char			*actual_node1_lexeme;
// 	char			*actual_node1_type;
// 	char			*actual_node2_lexeme;
// 	char			*actual_node2_type;
// 	char			*actual_node3_lexeme;
// 	char			*actual_node3_type;
// 	t_token_list	*lst;

// 	//ACT
// 	cadet_input = "echo \"Hello, World!\"";

// 	xpect_node1_type = get_token_string(WORD);
// 	xpect_node1_lexeme = "echo";
// 	xpect_node2_type = get_token_string(WORD);
// 	xpect_node2_lexeme = "\"Hello, World!\"";
// 	xpect_node3_type = NULL;
// 	xpect_node3_lexeme = NULL;
// 	xpect_lst_size = 2;
// 	idx = 0;
// 	lst = NULL;
// 	get_state(idx, cadet_input, &lst);

// 	actual_lst_size = ft_lst_size(lst);
// 	if (actual_lst_size == 2 && lst->next->next == NULL)
// 	{
// 		actual_node1_lexeme = lst->lexeme;
// 		actual_node1_type = get_token_string(lst->type);
// 		lst = lst->next;
// 		actual_node2_lexeme = lst->lexeme;
// 		actual_node2_type = get_token_string(lst->type);
// 		actual_node3_lexeme = NULL;
// 		actual_node3_type = NULL;
// 	}
// 	else
// 	{
// 		actual_node1_lexeme = lst->lexeme;
// 		actual_node1_type = get_token_string(lst->type);
// 		lst = lst->next;
// 		actual_node2_lexeme = lst->lexeme;
// 		actual_node2_type = get_token_string(lst->type);
// 		lst = lst->next;
// 		actual_node3_lexeme = lst->lexeme;
// 		actual_node3_type = get_token_string(lst->type);
// 	}

// 	// ASSERT
// 	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
// 	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
// 	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
// 	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
// 	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
// 	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
// 	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
// }

MU_TEST(testing_cadet_input_token_02_ls)
{
	// ARRANGE
	char			*cadet_input;
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
	cadet_input = "ls -l";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "ls";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "-l";
	xpect_node3_type = NULL;
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

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

MU_TEST(testing_cadet_input_token_02_cat_file)
{
	// ARRANGE
	char			*cadet_input;
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
	cadet_input = "cat file.txt";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "cat";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "file.txt";
	xpect_node3_type = NULL;
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

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

MU_TEST(testing_cadet_input_token_02_mkdir)
{
	// ARRANGE
	char			*cadet_input;
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
	cadet_input = "mkdir new_directory";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "mkdir";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "new_directory";
	xpect_node3_type = NULL;
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

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

MU_TEST(testing_cadet_input_token_02_rm_file)
{
	// ARRANGE
	char			*cadet_input;
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
	cadet_input = "rm file.txt";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "rm";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "file.txt";
	xpect_node3_type = NULL;
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 2;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

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

// TO BE CONTINUED:
// https://github.com/DanielSurf10/minishell/blob/lexing/tests/token/expected.txt

MU_TEST_SUITE(testing_tokens_cadet_suite)
{
	// MU_RUN_TEST(testing_cadet_input_token_02_hello_world);
	MU_RUN_TEST(testing_cadet_input_token_02_ls);
	MU_RUN_TEST(testing_cadet_input_token_02_cat_file);
	MU_RUN_TEST(testing_cadet_input_token_02_mkdir);
	MU_RUN_TEST(testing_cadet_input_token_02_rm_file);

}