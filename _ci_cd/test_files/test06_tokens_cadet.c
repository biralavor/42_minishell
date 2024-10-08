/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test06_tokens_cadet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:16:24 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/20 18:56:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

// MU_TEST(testing_tokens_cadet_input_hello_world)
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
// 	xpect_node2_type = get_token_string(DOUBLE_QUOTES);
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

MU_TEST(testing_tokens_cadet_input_ls)
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

MU_TEST(testing_tokens_cadet_input_cat_file)
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

MU_TEST(testing_tokens_cadet_input_mkdir)
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

MU_TEST(testing_tokens_cadet_input_rm_file)
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

// MU_TEST(testing_tokens_cadet_input_grep_pattern)
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
// 	cadet_input = "grep \"pattern\" file.txt";

// 	xpect_node1_type = get_token_string(WORD);
// 	xpect_node1_lexeme = "grep";
// 	xpect_node2_type = get_token_string(DOUBLE_QUOTES);
// 	xpect_node2_lexeme = "\"pattern\"";
// 	xpect_node3_type = get_token_string(WORD);
// 	xpect_node3_lexeme = "file.txt";
// 	xpect_lst_size = 3;
// 	idx = 0;
// 	lst = NULL;
// 	get_state(idx, cadet_input, &lst);

// 	actual_lst_size = ft_lst_size(lst);
// 	actual_node1_lexeme = lst->lexeme;
// 	actual_node1_type = get_token_string(lst->type);
// 	lst = lst->next;
// 	actual_node2_lexeme = lst->lexeme;
// 	actual_node2_type = get_token_string(lst->type);
// 	lst = lst->next;
// 	actual_node3_lexeme = lst->lexeme;
// 	actual_node3_type = get_token_string(lst->type);

// 	// ASSERT
// 	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
// 	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
// 	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
// 	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
// 	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
// 	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
// 	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
// }

MU_TEST(testing_tokens_cadet_input_cd_path_dir)
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
	cadet_input = "cd /path/to/directory";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "cd";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "/path/to/directory";
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

MU_TEST(testing_tokens_cadet_input_pwd)
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
	cadet_input = "pwd";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "pwd";
	xpect_node2_type = NULL;
	xpect_node2_lexeme = NULL;
	xpect_node3_type = NULL;
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 1;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

	actual_lst_size = ft_lst_size(lst);
	if (actual_lst_size == 1 && lst->next == NULL)
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		actual_node2_lexeme = NULL;
		actual_node2_type = NULL;
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

MU_TEST(testing_tokens_cadet_input_chmod)
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
	char			*xpect_node4_lexeme;
	char			*xpect_node4_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	char			*actual_node4_lexeme;
	char			*actual_node4_type;
	t_token_list	*lst;

	//ACT
	cadet_input = "chmod +x script.sh";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "chmod";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "+x";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "script.sh";
	xpect_node4_type = NULL;
	xpect_node4_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

	actual_lst_size = ft_lst_size(lst);
	if (actual_lst_size == 3 && lst->next->next->next == NULL)
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node3_lexeme = lst->lexeme;
		actual_node3_type = get_token_string(lst->type);
		actual_node4_lexeme = NULL;
		actual_node4_type = NULL;
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
		lst = lst->next;
		actual_node4_lexeme = lst->lexeme;
		actual_node4_type = get_token_string(lst->type);
	}

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
	mu_assert_string_eq(xpect_node4_lexeme, actual_node4_lexeme);
	mu_assert_string_eq(xpect_node4_type, actual_node4_type);
}

MU_TEST(testing_tokens_cadet_input_mv_file)
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
	char			*xpect_node4_lexeme;
	char			*xpect_node4_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	char			*actual_node4_lexeme;
	char			*actual_node4_type;
	t_token_list	*lst;

	//ACT
	cadet_input = "mv file.txt new_directory/";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "mv";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "file.txt";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "new_directory/";
	xpect_node4_type = NULL;
	xpect_node4_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

	actual_lst_size = ft_lst_size(lst);
	if (actual_lst_size == 3 && lst->next->next->next == NULL)
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node3_lexeme = lst->lexeme;
		actual_node3_type = get_token_string(lst->type);
		actual_node4_lexeme = NULL;
		actual_node4_type = NULL;
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
		lst = lst->next;
		actual_node4_lexeme = lst->lexeme;
		actual_node4_type = get_token_string(lst->type);
	}

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
	mu_assert_string_eq(xpect_node4_lexeme, actual_node4_lexeme);
	mu_assert_string_eq(xpect_node4_type, actual_node4_type);
}

MU_TEST(testing_tokens_cadet_input_alo_oie_05)
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
	char			*xpect_node4_lexeme;
	char			*xpect_node4_type;
	char			*xpect_node5_lexeme;
	char			*xpect_node5_type;
	char			*xpect_node6_lexeme;
	char			*xpect_node6_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	char			*actual_node4_lexeme;
	char			*actual_node4_type;
	char			*actual_node5_lexeme;
	char			*actual_node5_type;
	char			*actual_node6_lexeme;
	char			*actual_node6_type;
	t_token_list	*lst;

	//ACT
	cadet_input = "alo&&oi|| 	 	 	oie";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "alo";
	xpect_node2_type = get_token_string(AND);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "oi";
	xpect_node4_type = get_token_string(OR);
	xpect_node4_lexeme = NULL;
	xpect_node5_type = get_token_string(WORD);
	xpect_node5_lexeme = "oie";
	xpect_node6_type = NULL;
	xpect_node6_lexeme = NULL;
	xpect_lst_size = 5;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

	actual_lst_size = ft_lst_size(lst);
	if (actual_lst_size == 5)
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node3_lexeme = lst->lexeme;
		actual_node3_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node4_lexeme = lst->lexeme;
		actual_node4_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node5_lexeme = lst->lexeme;
		actual_node5_type = get_token_string(lst->type);
		actual_node6_lexeme = NULL;
		actual_node6_type = NULL;
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
		lst = lst->next;
		actual_node4_lexeme = lst->lexeme;
		actual_node4_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node5_lexeme = lst->lexeme;
		actual_node5_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node6_lexeme = lst->lexeme;
		actual_node6_type = get_token_string(lst->type);
	}

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
	mu_assert_string_eq(xpect_node4_lexeme, actual_node4_lexeme);
	mu_assert_string_eq(xpect_node4_type, actual_node4_type);
	mu_assert_string_eq(xpect_node5_lexeme, actual_node5_lexeme);
	mu_assert_string_eq(xpect_node5_type, actual_node5_type);
	mu_assert_string_eq(xpect_node6_lexeme, actual_node6_lexeme);
	mu_assert_string_eq(xpect_node6_type, actual_node6_type);
}

MU_TEST(testing_tokens_cadet_input_oi_alo_bom_dia_08)
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
	char			*xpect_node4_lexeme;
	char			*xpect_node4_type;
	char			*xpect_node5_lexeme;
	char			*xpect_node5_type;
	char			*xpect_node6_lexeme;
	char			*xpect_node6_type;
	char			*xpect_node7_lexeme;
	char			*xpect_node7_type;
	char			*xpect_node8_lexeme;
	char			*xpect_node8_type;
	char			*xpect_node9_lexeme;
	char			*xpect_node9_type;
	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	char			*actual_node4_lexeme;
	char			*actual_node4_type;
	char			*actual_node5_lexeme;
	char			*actual_node5_type;
	char			*actual_node6_lexeme;
	char			*actual_node6_type;
	char			*actual_node7_lexeme;
	char			*actual_node7_type;
	char			*actual_node8_lexeme;
	char			*actual_node8_type;
	char			*actual_node9_lexeme;
	char			*actual_node9_type;
	t_token_list	*lst;

	//ACT
	cadet_input = "oi|alo|bom dia|ola";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "oi";
	xpect_node2_type = get_token_string(PIPE);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "alo";
	xpect_node4_type = get_token_string(PIPE);
	xpect_node4_lexeme = NULL;
	xpect_node5_type = get_token_string(WORD);
	xpect_node5_lexeme = "bom";
	xpect_node6_type = get_token_string(WORD);
	xpect_node6_lexeme = "dia";
	xpect_node7_type = get_token_string(PIPE);
	xpect_node7_lexeme = NULL;
	xpect_node8_type = get_token_string(WORD);
	xpect_node8_lexeme = "ola";
	xpect_node9_type = NULL;
	xpect_node9_lexeme = NULL;
	xpect_lst_size = 8;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

	actual_lst_size = ft_lst_size(lst);
	if (actual_lst_size == 8)
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node3_lexeme = lst->lexeme;
		actual_node3_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node4_lexeme = lst->lexeme;
		actual_node4_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node5_lexeme = lst->lexeme;
		actual_node5_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node6_lexeme = lst->lexeme;
		actual_node6_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node7_lexeme = lst->lexeme;
		actual_node7_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node8_lexeme = lst->lexeme;
		actual_node8_type = get_token_string(lst->type);
		actual_node9_lexeme = NULL;
		actual_node9_type = NULL;
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
		lst = lst->next;
		actual_node4_lexeme = lst->lexeme;
		actual_node4_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node5_lexeme = lst->lexeme;
		actual_node5_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node6_lexeme = lst->lexeme;
		actual_node6_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node7_lexeme = lst->lexeme;
		actual_node7_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node8_lexeme = lst->lexeme;
		actual_node8_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node9_lexeme = lst->lexeme;
		actual_node9_type = get_token_string(lst->type);
	}

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
	mu_assert_string_eq(xpect_node4_lexeme, actual_node4_lexeme);
	mu_assert_string_eq(xpect_node4_type, actual_node4_type);
	mu_assert_string_eq(xpect_node5_lexeme, actual_node5_lexeme);
	mu_assert_string_eq(xpect_node5_type, actual_node5_type);
	mu_assert_string_eq(xpect_node6_lexeme, actual_node6_lexeme);
	mu_assert_string_eq(xpect_node6_type, actual_node6_type);
	mu_assert_string_eq(xpect_node7_lexeme, actual_node7_lexeme);
	mu_assert_string_eq(xpect_node7_type, actual_node7_type);
	mu_assert_string_eq(xpect_node8_lexeme, actual_node8_lexeme);
	mu_assert_string_eq(xpect_node8_type, actual_node8_type);
	mu_assert_string_eq(xpect_node9_lexeme, actual_node9_lexeme);
	mu_assert_string_eq(xpect_node9_type, actual_node9_type);
}

MU_TEST(testing_tokens_cadet_input_ls_echo_07)
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
	char			*xpect_node4_lexeme;
	char			*xpect_node4_type;
	char			*xpect_node5_lexeme;
	char			*xpect_node5_type;
	char			*xpect_node6_lexeme;
	char			*xpect_node6_type;
	char			*xpect_node7_lexeme;
	char			*xpect_node7_type;
	char			*xpect_node8_lexeme;
	char			*xpect_node8_type;

	char			*actual_node1_lexeme;
	char			*actual_node1_type;
	char			*actual_node2_lexeme;
	char			*actual_node2_type;
	char			*actual_node3_lexeme;
	char			*actual_node3_type;
	char			*actual_node4_lexeme;
	char			*actual_node4_type;
	char			*actual_node5_lexeme;
	char			*actual_node5_type;
	char			*actual_node6_lexeme;
	char			*actual_node6_type;
	char			*actual_node7_lexeme;
	char			*actual_node7_type;
	char			*actual_node8_lexeme;
	char			*actual_node8_type;
	t_token_list	*lst;

	//ACT
	cadet_input = "(ls -l|echo a>out&&outsleep 5)||ls -la|grep a";

	xpect_node1_type = get_token_string(SUBSHELL);
	xpect_node1_lexeme = "(ls -l|echo a>out&&outsleep 5)";
	xpect_node2_type = get_token_string(OR);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "ls";
	xpect_node4_type = get_token_string(WORD);
	xpect_node4_lexeme = "-la";
	xpect_node5_type = get_token_string(PIPE);
	xpect_node5_lexeme = NULL;
	xpect_node6_type = get_token_string(WORD);
	xpect_node6_lexeme = "grep";
	xpect_node7_type = get_token_string(WORD);
	xpect_node7_lexeme = "a";
	xpect_node8_type = NULL;
	xpect_node8_lexeme = NULL;
	xpect_lst_size = 7;
	idx = 0;
	lst = NULL;
	get_state(idx, cadet_input, &lst);

	actual_lst_size = ft_lst_size(lst);
	if (actual_lst_size == xpect_lst_size)
	{
		actual_node1_lexeme = lst->lexeme;
		actual_node1_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node2_lexeme = lst->lexeme;
		actual_node2_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node3_lexeme = lst->lexeme;
		actual_node3_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node4_lexeme = lst->lexeme;
		actual_node4_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node5_lexeme = lst->lexeme;
		actual_node5_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node6_lexeme = lst->lexeme;
		actual_node6_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node7_lexeme = lst->lexeme;
		actual_node7_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node8_lexeme = NULL;
		actual_node8_type = NULL;
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
		lst = lst->next;
		actual_node4_lexeme = lst->lexeme;
		actual_node4_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node5_lexeme = lst->lexeme;
		actual_node5_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node6_lexeme = lst->lexeme;
		actual_node6_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node7_lexeme = lst->lexeme;
		actual_node7_type = get_token_string(lst->type);
		lst = lst->next;
		actual_node8_lexeme = lst->lexeme;
		actual_node8_type = get_token_string(lst->type);
	}

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
	mu_assert_string_eq(xpect_node4_lexeme, actual_node4_lexeme);
	mu_assert_string_eq(xpect_node4_type, actual_node4_type);
	mu_assert_string_eq(xpect_node5_lexeme, actual_node5_lexeme);
	mu_assert_string_eq(xpect_node5_type, actual_node5_type);
	mu_assert_string_eq(xpect_node6_lexeme, actual_node6_lexeme);
	mu_assert_string_eq(xpect_node6_type, actual_node6_type);
	mu_assert_string_eq(xpect_node7_lexeme, actual_node7_lexeme);
	mu_assert_string_eq(xpect_node7_type, actual_node7_type);
	mu_assert_string_eq(xpect_node8_lexeme, actual_node8_lexeme);
	mu_assert_string_eq(xpect_node8_type, actual_node8_type);
}

MU_TEST_SUITE(test06___tokens_cadet_suite)
{
	// MU_RUN_TEST(testing_tokens_cadet_input_hello_world);
	MU_RUN_TEST(testing_tokens_cadet_input_ls);
	MU_RUN_TEST(testing_tokens_cadet_input_cat_file);
	MU_RUN_TEST(testing_tokens_cadet_input_mkdir);
	MU_RUN_TEST(testing_tokens_cadet_input_rm_file);
	// MU_RUN_TEST(testing_tokens_cadet_input_grep_pattern);
	MU_RUN_TEST(testing_tokens_cadet_input_cd_path_dir);
	MU_RUN_TEST(testing_tokens_cadet_input_pwd);
	MU_RUN_TEST(testing_tokens_cadet_input_chmod);
	MU_RUN_TEST(testing_tokens_cadet_input_mv_file);
	MU_RUN_TEST(testing_tokens_cadet_input_alo_oie_05);
	MU_RUN_TEST(testing_tokens_cadet_input_oi_alo_bom_dia_08);
	MU_RUN_TEST(testing_tokens_cadet_input_ls_echo_07);
}
