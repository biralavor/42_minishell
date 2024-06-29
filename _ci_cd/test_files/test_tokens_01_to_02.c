/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokens_01_to_02.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/29 15:15:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"

MU_TEST(check_userinput_token_empty)
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

MU_TEST(check_userinput_token_01_word_with_space)
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

MU_TEST(check_userinput_token_01_word_with_tab_v01)
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

MU_TEST(check_userinput_token_01_word_with_tab_v02)
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

MU_TEST(check_userinput_token_01_pipe_at_begin)
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
	userinput = "|Mussum Ipsum";

	xpect_node1_type = get_token_string(PIPE);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_pipe_at_middle)
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
	userinput = "Mussum|Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(PIPE);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_pipe_at_end)
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
	userinput = "Mussum Ipsum|";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(PIPE);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_input_at_begin)
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
	userinput = "<Mussum Ipsum";

	xpect_node1_type = get_token_string(REDIRECT_INPUT);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_input_at_middle)
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
	userinput = "Mussum<Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(REDIRECT_INPUT);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_input_at_end)
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
	userinput = "Mussum Ipsum<";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(REDIRECT_INPUT);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_heredoc_at_begin)
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
	userinput = "<< Mussum Ipsum";

	xpect_node1_type = get_token_string(REDIRECT_HEREDOC);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_heredoc_at_middle)
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
	userinput = "Mussum <<Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(REDIRECT_HEREDOC);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_heredoc_at_end)
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
	userinput = "Mussum Ipsum<<";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(REDIRECT_HEREDOC);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_output_at_begin)
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
	userinput = ">Mussum Ipsum";

	xpect_node1_type = get_token_string(REDIRECT_OUTPUT);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_output_at_middle)
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
	userinput = "Mussum >Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(REDIRECT_OUTPUT);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_output_at_end)
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
	userinput = "Mussum Ipsum>";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(REDIRECT_OUTPUT);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_output_append_at_begin)
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
	userinput = "     >> Mussum Ipsum";

	xpect_node1_type = get_token_string(REDIRECT_OUTPUT_APPEND);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_output_append_at_middle)
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
	userinput = "Mussum      >>Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(REDIRECT_OUTPUT_APPEND);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_redirect_output_append_at_end)
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
	userinput = "Mussum Ipsum>>         ";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(REDIRECT_OUTPUT_APPEND);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_OR_at_begin)
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
	userinput = "     ||     Mussum Ipsum";

	xpect_node1_type = get_token_string(OR);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_OR_at_middle)
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
	userinput = "Mussum      ||Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(OR);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_OR_at_end)
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
	userinput = "Mussum Ipsum||         ";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(OR);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_AND_at_begin)
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
	userinput = "     &&     Mussum Ipsum";

	xpect_node1_type = get_token_string(AND);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_AND_at_middle)
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
	userinput = "Mussum      &&Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(AND);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_AND_at_end)
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
	userinput = "Mussum Ipsum&&         ";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(AND);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_open_parenthesis_at_begin)
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
	userinput = "     (     Mussum Ipsum";

	xpect_node1_type = get_token_string(OPEN_PARENTHESIS);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_open_parenthesis_at_middle)
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
	userinput = "Mussum      (Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(OPEN_PARENTHESIS);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_open_parenthesis_at_end)
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
	userinput = "Mussum Ipsum(         ";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(OPEN_PARENTHESIS);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_close_parenthesis_at_begin)
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
	userinput = "     )     Mussum Ipsum";

	xpect_node1_type = get_token_string(CLOSE_PARENTHESIS);
	xpect_node1_lexeme = NULL;
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Mussum";
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_close_parenthesis_at_middle)
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
	userinput = "Mussum      )Ipsum";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(CLOSE_PARENTHESIS);
	xpect_node2_lexeme = NULL;
	xpect_node3_type = get_token_string(WORD);
	xpect_node3_lexeme = "Ipsum";
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST(check_userinput_token_01_close_parenthesis_at_end)
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
	userinput = "Mussum Ipsum)         ";

	xpect_node1_type = get_token_string(WORD);
	xpect_node1_lexeme = "Mussum";
	xpect_node2_type = get_token_string(WORD);
	xpect_node2_lexeme = "Ipsum";
	xpect_node3_type = get_token_string(CLOSE_PARENTHESIS);
	xpect_node3_lexeme = NULL;
	xpect_lst_size = 3;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);

	actual_lst_size = ft_lst_size(lst);
	actual_node1_lexeme = lst->lexeme;
	actual_node1_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node2_lexeme = lst->lexeme;
	actual_node2_type = get_token_string(lst->type);
	lst = lst->next;
	actual_node3_lexeme = lst->lexeme;
	actual_node3_type = get_token_string(lst->type);

	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_string_eq(xpect_node1_lexeme, actual_node1_lexeme);
	mu_assert_string_eq(xpect_node1_type, actual_node1_type);
	mu_assert_string_eq(xpect_node2_lexeme, actual_node2_lexeme);
	mu_assert_string_eq(xpect_node2_type, actual_node2_type);
	mu_assert_string_eq(xpect_node3_lexeme, actual_node3_lexeme);
	mu_assert_string_eq(xpect_node3_type, actual_node3_type);
}

MU_TEST_SUITE(check_01_to_02_tokens_tests)
{
	MU_RUN_TEST(check_userinput_token_empty);
	MU_RUN_TEST(check_userinput_token_01_word_with_space);
	MU_RUN_TEST(check_userinput_token_01_word_with_tab_v01);
	MU_RUN_TEST(check_userinput_token_01_word_with_tab_v02);
	MU_RUN_TEST(check_userinput_token_01_pipe_at_begin);
	MU_RUN_TEST(check_userinput_token_01_pipe_at_middle);
	MU_RUN_TEST(check_userinput_token_01_pipe_at_end);
	MU_RUN_TEST(check_userinput_token_01_redirect_input_at_begin);
	MU_RUN_TEST(check_userinput_token_01_redirect_input_at_middle);
	MU_RUN_TEST(check_userinput_token_01_redirect_input_at_end);
	MU_RUN_TEST(check_userinput_token_01_redirect_heredoc_at_begin);
	MU_RUN_TEST(check_userinput_token_01_redirect_heredoc_at_middle);
	MU_RUN_TEST(check_userinput_token_01_redirect_heredoc_at_end);
	MU_RUN_TEST(check_userinput_token_01_redirect_output_at_begin);
	MU_RUN_TEST(check_userinput_token_01_redirect_output_at_middle);
	MU_RUN_TEST(check_userinput_token_01_redirect_output_at_end);
	MU_RUN_TEST(check_userinput_token_01_redirect_output_append_at_begin);
	MU_RUN_TEST(check_userinput_token_01_redirect_output_append_at_middle);
	MU_RUN_TEST(check_userinput_token_01_redirect_output_append_at_end);
	MU_RUN_TEST(check_userinput_token_01_OR_at_begin);
	MU_RUN_TEST(check_userinput_token_01_OR_at_middle);
	MU_RUN_TEST(check_userinput_token_01_OR_at_end);
	MU_RUN_TEST(check_userinput_token_01_AND_at_begin);
	MU_RUN_TEST(check_userinput_token_01_AND_at_middle);
	MU_RUN_TEST(check_userinput_token_01_AND_at_end);
	MU_RUN_TEST(check_userinput_token_01_open_parenthesis_at_begin);
	MU_RUN_TEST(check_userinput_token_01_open_parenthesis_at_middle);
	MU_RUN_TEST(check_userinput_token_01_open_parenthesis_at_end);
	MU_RUN_TEST(check_userinput_token_01_close_parenthesis_at_begin);
	MU_RUN_TEST(check_userinput_token_01_close_parenthesis_at_middle);
	MU_RUN_TEST(check_userinput_token_01_close_parenthesis_at_end);
}
