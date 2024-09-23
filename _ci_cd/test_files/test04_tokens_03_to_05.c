/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test04_tokens_03_to_05.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/20 18:21:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

MU_TEST(testing_userinput_token_03_pipe_at_begin)
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

MU_TEST(testing_userinput_token_03_pipe_at_middle)
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

MU_TEST(testing_userinput_token_03_pipe_at_end)
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

MU_TEST(testing_userinput_token_03_redirect_input_at_begin)
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

	xpect_node1_type = get_token_string(REDIR_IN);
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

MU_TEST(testing_userinput_token_03_redirect_input_at_middle)
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
	xpect_node2_type = get_token_string(REDIR_IN);
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

MU_TEST(testing_userinput_token_03_redirect_input_at_end)
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
	xpect_node3_type = get_token_string(REDIR_IN);
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

MU_TEST(testing_userinput_token_03_redirect_heredoc_at_begin)
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

	xpect_node1_type = get_token_string(REDIR_HDOC);
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

MU_TEST(testing_userinput_token_03_redirect_heredoc_at_middle)
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
	xpect_node2_type = get_token_string(REDIR_HDOC);
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

MU_TEST(testing_userinput_token_03_redirect_heredoc_at_end)
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
	xpect_node3_type = get_token_string(REDIR_HDOC);
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

MU_TEST(testing_userinput_token_03_redirect_output_at_begin)
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

	xpect_node1_type = get_token_string(REDIR_OUT);
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

MU_TEST(testing_userinput_token_03_redirect_output_at_middle)
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
	xpect_node2_type = get_token_string(REDIR_OUT);
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

MU_TEST(testing_userinput_token_03_redirect_output_at_end)
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
	xpect_node3_type = get_token_string(REDIR_OUT);
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

MU_TEST(testing_userinput_token_03_redirect_output_append_at_begin)
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

	xpect_node1_type = get_token_string(REDIR_OUTAPP);
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

MU_TEST(testing_userinput_token_03_redirect_output_append_at_middle)
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
	xpect_node2_type = get_token_string(REDIR_OUTAPP);
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

MU_TEST(testing_userinput_token_03_redirect_output_append_at_end)
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
	xpect_node3_type = get_token_string(REDIR_OUTAPP);
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

MU_TEST(testing_userinput_token_03_OR_at_begin)
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

MU_TEST(testing_userinput_token_03_OR_at_middle)
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

MU_TEST(testing_userinput_token_03_OR_at_end)
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

MU_TEST(testing_userinput_token_03_AND_at_begin)
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

MU_TEST(testing_userinput_token_03_AND_at_middle)
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

MU_TEST(testing_userinput_token_03_AND_at_end)
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

MU_TEST(testing_userinput_token_04)
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
	userinput = "ls a* > me";

	xpect_node_01_type = get_token_string(WORD);
	xpect_node_01_lexeme = "ls";
	xpect_node_02_type = get_token_string(WORD);
	xpect_node_02_lexeme = "a*";
	xpect_node_03_type = get_token_string(REDIR_OUT);
	xpect_node_03_lexeme = NULL;
	xpect_node_04_type = get_token_string(WORD);
	xpect_node_04_lexeme = "me";
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

// MU_TEST(testing_userinput_token_05)
// {
// 	// ARRANGE
// 	char			*userinput;
// 	int				xpect_lst_size;
// 	int				actual_lst_size;
// 	char			*xpect_node_01_lexeme;
// 	char			*xpect_node_01_type;
// 	char			*xpect_node_02_lexeme;
// 	char			*xpect_node_02_type;
// 	char			*xpect_node_03_lexeme;
// 	char			*xpect_node_03_type;
// 	char			*xpect_node_04_lexeme;
// 	char			*xpect_node_04_type;
// 	char			*xpect_node_05_lexeme;
// 	char			*xpect_node_05_type;
// 	char			*actual_node_01_lexeme;
// 	char			*actual_node_01_type;
// 	char			*actual_node_02_lexeme;
// 	char			*actual_node_02_type;
// 	char			*actual_node_03_lexeme;
// 	char			*actual_node_03_type;
// 	char			*actual_node_04_lexeme;
// 	char			*actual_node_04_type;
// 	char			*actual_node_05_lexeme;
// 	char			*actual_node_05_type;
// 	t_token_list	*lst;

// 	//ACT
// 	userinput = "t2 ls | \"'hello world'\"";

// 	xpect_node_01_type = get_token_string(REDIR_OUT);
// 	xpect_node_01_lexeme = NULL;
// 	xpect_node_02_type = get_token_string(WORD);
// 	xpect_node_02_lexeme = "t2";
// 	xpect_node_03_type = get_token_string(WORD);
// 	xpect_node_03_lexeme = "ls";
// 	xpect_node_04_type = get_token_string(PIPE);
// 	xpect_node_04_lexeme = NULL;
// 	xpect_node_05_type = get_token_string(DOUBLE_QUOTES);
// 	xpect_node_05_lexeme = "\"'hello world'\"";
// 	xpect_lst_size = 5;
// 	lst = NULL;
// 	if (create_token_list(userinput, &lst))
// 		printf("create_token_list OK\n");
// 	else
// 		printf("create_token_list failed\n");
	
// 	actual_lst_size = ft_lst_size(lst);
// 	actual_node_01_lexeme = lst->lexeme;
// 	actual_node_01_type = get_token_string(lst->type);
// 	lst = lst->next;
// 	actual_node_02_lexeme = lst->lexeme;
// 	actual_node_02_type = get_token_string(lst->type);
// 	lst = lst->next;
// 	actual_node_03_lexeme = lst->lexeme;
// 	actual_node_03_type = get_token_string(lst->type);
// 	lst = lst->next;
// 	actual_node_04_lexeme = lst->lexeme;
// 	actual_node_04_type = get_token_string(lst->type);
// 	lst = lst->next;
// 	actual_node_05_lexeme = lst->lexeme;
// 	actual_node_05_type = get_token_string(lst->type);

// 	// ASSERT
// 	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
// 	mu_assert_string_eq(xpect_node_01_lexeme, actual_node_01_lexeme);
// 	mu_assert_string_eq(xpect_node_01_type, actual_node_01_type);
// 	mu_assert_string_eq(xpect_node_02_lexeme, actual_node_02_lexeme);
// 	mu_assert_string_eq(xpect_node_02_type, actual_node_02_type);
// 	mu_assert_string_eq(xpect_node_03_lexeme, actual_node_03_lexeme);
// 	mu_assert_string_eq(xpect_node_03_type, actual_node_03_type);
// 	mu_assert_string_eq(xpect_node_04_lexeme, actual_node_04_lexeme);
// 	mu_assert_string_eq(xpect_node_04_type, actual_node_04_type);
// 	mu_assert_string_eq(xpect_node_05_lexeme, actual_node_05_lexeme);
// 	mu_assert_string_eq(xpect_node_05_type, actual_node_05_type);
// }

MU_TEST_SUITE(test04___03_to_05_tokens_suite)
{
	MU_RUN_TEST(testing_userinput_token_03_pipe_at_begin);
	MU_RUN_TEST(testing_userinput_token_03_pipe_at_middle);
	MU_RUN_TEST(testing_userinput_token_03_pipe_at_end);
	MU_RUN_TEST(testing_userinput_token_03_redirect_input_at_begin);
	MU_RUN_TEST(testing_userinput_token_03_redirect_input_at_middle);
	MU_RUN_TEST(testing_userinput_token_03_redirect_input_at_end);
	MU_RUN_TEST(testing_userinput_token_03_redirect_heredoc_at_begin);
	MU_RUN_TEST(testing_userinput_token_03_redirect_heredoc_at_middle);
	MU_RUN_TEST(testing_userinput_token_03_redirect_heredoc_at_end);
	MU_RUN_TEST(testing_userinput_token_03_redirect_output_at_begin);
	MU_RUN_TEST(testing_userinput_token_03_redirect_output_at_middle);
	MU_RUN_TEST(testing_userinput_token_03_redirect_output_at_end);
	MU_RUN_TEST(testing_userinput_token_03_redirect_output_append_at_begin);
	MU_RUN_TEST(testing_userinput_token_03_redirect_output_append_at_middle);
	MU_RUN_TEST(testing_userinput_token_03_redirect_output_append_at_end);
	MU_RUN_TEST(testing_userinput_token_03_OR_at_begin);
	MU_RUN_TEST(testing_userinput_token_03_OR_at_middle);
	MU_RUN_TEST(testing_userinput_token_03_OR_at_end);
	MU_RUN_TEST(testing_userinput_token_03_AND_at_begin);
	MU_RUN_TEST(testing_userinput_token_03_AND_at_middle);
	MU_RUN_TEST(testing_userinput_token_03_AND_at_end);
	MU_RUN_TEST(testing_userinput_token_04);
	// MU_RUN_TEST(testing_userinput_token_05);
}
