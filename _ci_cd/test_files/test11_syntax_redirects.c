/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11_syntax_redirects.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:31:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/06 10:05:12 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "lexer.h"


MU_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_first_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_redirect_detection;
	bool			actual_redirect_detection;
	bool			xpect_archive_word_detection;
	bool			actual_archive_word_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "> file.txt cat file.txt";
	xpect_redirect_detection = true; // redirect detection
	xpect_archive_word_detection = true; // word after archive detection
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_redirect_detection = check_redirects(lst);
	if (actual_redirect_detection == true)
	{
		define_archive_token(lst);
		actual_archive_word_detection = check_words_after_archive(lst);
	}
	else
		actual_archive_word_detection = -1;
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_redirect_detection, actual_redirect_detection);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	free_token_list(&lst);
}

MU_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_middle_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_redirect_detection;
	bool			actual_redirect_detection;
	bool			xpect_archive_word_detection;
	bool			actual_archive_word_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "cat file1.txt echo > file2.txt file3.txt";
	xpect_redirect_detection = true; // redirect detection
	xpect_archive_word_detection = true; // word after archive detection
	xpect_lst_size = 6;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_redirect_detection = check_redirects(lst);
	if (actual_redirect_detection == true)
	{
		define_archive_token(lst);
		actual_archive_word_detection = check_words_after_archive(lst);
	}
	else
		actual_archive_word_detection = -1;
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_redirect_detection, actual_redirect_detection);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	free_token_list(&lst);
}

MU_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_last_node)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_redirect_detection;
	bool			actual_redirect_detection;
	bool			xpect_archive_word_detection;
	bool			actual_archive_word_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo OLA-OLA file2.txt > file3.txt";
	xpect_redirect_detection = true; // redirect detection
	xpect_archive_word_detection = false; // word after archive detection
	xpect_lst_size = 5;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_redirect_detection = check_redirects(lst);
	if (actual_redirect_detection == true)
	{
		define_archive_token(lst);
		actual_archive_word_detection = check_words_after_archive(lst);
	}
	else
		actual_archive_word_detection = -1;
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_redirect_detection, actual_redirect_detection);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	free_token_list(&lst);
}

MU_TEST(testing_syntax_WORD_AFTER_ARCHIVE_detection_false)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_archive_word_detection;
	bool			actual_archive_word_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo 1-oi > 2-file.txt";
	xpect_archive_word_detection = false; // word after archive detection
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	define_archive_token(lst);
	actual_archive_word_detection = check_words_after_archive(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	free_token_list(&lst);
}

MU_TEST(testing_syntax_WORD_AFTER_ARCHIVE_detection_true)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_archive_word_detection;
	bool			xpect_another_redirect_detection;
	bool			actual_archive_word_detection;
	bool			actual_another_redirect_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo 1-oi > 2-file.txt 3-conteudo";
	xpect_archive_word_detection = true; // word after archive detection
	xpect_another_redirect_detection = false; // is there any redirect, after archive?
	xpect_lst_size = 5;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	define_archive_token(lst);
	actual_archive_word_detection = check_words_after_archive(lst);
	actual_another_redirect_detection = check_another_redirect_after_archive(lst);
	if (actual_another_redirect_detection == true)
		organize_redirects(&lst);
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	mu_assert_int_eq(xpect_another_redirect_detection, actual_another_redirect_detection);
	free_token_list(&lst);
}

MU_TEST(testing_syntax_ANOTHER_REDIRECTS_FOUND_false)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_another_redirect_detection;
	bool			actual_another_redirect_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo 1-oi > 2-file.txt 3-file.txt";
	xpect_another_redirect_detection = false; // is there any redirect, after archive?
	xpect_lst_size = 5;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	define_archive_token(lst);
	actual_another_redirect_detection = check_another_redirect_after_archive(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_another_redirect_detection, actual_another_redirect_detection);
	free_token_list(&lst);
}

MU_TEST(testing_syntax_ANOTHER_REDIRECTS_FOUND_true)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_another_redirect_detection;
	bool			actual_another_redirect_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo oi > tudo bem > com voce amigo querido > guardou";
	xpect_another_redirect_detection = true; // is there any redirect, after archive?
	xpect_lst_size = 12;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	if (check_redirects(lst))
		define_archive_token(lst);
	actual_another_redirect_detection = check_another_redirect_after_archive(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_another_redirect_detection, actual_another_redirect_detection);
	free_token_list(&lst);
}

MU_TEST(testing_syntax_REORGANIZE_REDIRECTS_echo_oi_tudo_bem_classic)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_archive_word_detection;
	bool			xpect_another_redirect_detection;
	bool			actual_archive_word_detection;
	bool			actual_another_redirect_detection;
	char			*xpect_node_01;
	char			*xpect_node_02;
	char			*xpect_node_03;
	char			*xpect_node_04;
	char			*xpect_node_05;
	char			*xpect_node_06;
	char			*xpect_node_07;
	char			*xpect_node_08;
	char			*xpect_node_09;
	char			*xpect_node_10;
	char			*xpect_node_11;
	char			*xpect_node_12;
	char			*actual_node_01;
	char			*actual_node_02;
	char			*actual_node_03;
	char			*actual_node_04;
	char			*actual_node_05;
	char			*actual_node_06;
	char			*actual_node_07;
	char			*actual_node_08;
	char			*actual_node_09;
	char			*actual_node_10;
	char			*actual_node_11;
	char			*actual_node_12;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo oi > tudo bem > com voce amigo querido > guardou";
	xpect_archive_word_detection = true; // word after archive detection
	xpect_another_redirect_detection = true; // is there any redirect, after archive?
	xpect_node_01 = "echo";
	xpect_node_02 = "oi";
	xpect_node_03 = "bem";
	xpect_node_04 = "voce";
	xpect_node_05 = "amigo";
	xpect_node_06 = "querido";
	xpect_node_07 = NULL;
	xpect_node_08 = "tudo";
	xpect_node_09 = NULL;
	xpect_node_10 = "com";
	xpect_node_11 = NULL;
	xpect_node_12 = "guardou";
	xpect_lst_size = 12;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	define_archive_token(lst);
	actual_archive_word_detection = check_words_after_archive(lst);
	actual_another_redirect_detection = check_another_redirect_after_archive(lst);
	if (actual_another_redirect_detection == true)
		organize_redirects(&lst);
	actual_node_01 = lst->lexeme;
	lst = lst->next;
	actual_node_02 = lst->lexeme;
	lst = lst->next;
	actual_node_03 = lst->lexeme;
	lst = lst->next;
	actual_node_04 = lst->lexeme;
	lst = lst->next;
	actual_node_05 = lst->lexeme;
	lst = lst->next;
	actual_node_06 = lst->lexeme;
	lst = lst->next;
	actual_node_07 = lst->lexeme;
	lst = lst->next;
	actual_node_08 = lst->lexeme;
	lst = lst->next;
	actual_node_09 = lst->lexeme;
	lst = lst->next;
	actual_node_10 = lst->lexeme;
	lst = lst->next;
	actual_node_11 = lst->lexeme;
	lst = lst->next;
	actual_node_12 = lst->lexeme;
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	mu_assert_int_eq(xpect_another_redirect_detection, actual_another_redirect_detection);
	mu_assert_string_eq(xpect_node_01, actual_node_01);
	mu_assert_string_eq(xpect_node_02, actual_node_02);
	mu_assert_string_eq(xpect_node_03, actual_node_03);
	mu_assert_string_eq(xpect_node_04, actual_node_04);
	mu_assert_string_eq(xpect_node_05, actual_node_05);
	mu_assert_string_eq(xpect_node_06, actual_node_06);
	mu_assert_string_eq(xpect_node_07, actual_node_07);
	mu_assert_string_eq(xpect_node_08, actual_node_08);
	mu_assert_string_eq(xpect_node_09, actual_node_09);
	mu_assert_string_eq(xpect_node_10, actual_node_10);
	mu_assert_string_eq(xpect_node_11, actual_node_11);
	mu_assert_string_eq(xpect_node_12, actual_node_12);
	free_token_list(&lst);
}

MU_TEST(testing_syntax_REORGANIZE_REDIRECTS_end_with_ARCHIVE)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_archive_word_detection;
	bool			xpect_another_redirect_detection;
	bool			actual_archive_word_detection;
	bool			actual_another_redirect_detection;
	char			*xpect_node_01;
	char			*xpect_node_02;
	char			*xpect_node_03;
	char			*xpect_node_04;
	char			*xpect_node_05;
	char			*xpect_node_06;
	char			*actual_node_01;
	char			*actual_node_02;
	char			*actual_node_03;
	char			*actual_node_04;
	char			*actual_node_05;
	char			*actual_node_06;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo 1-oi > 2-file.txt > 3-file.txt";
	xpect_archive_word_detection = false; // word after archive detection
	xpect_another_redirect_detection = false; // is there any redirect, after archive?
	xpect_node_01 = "echo";
	xpect_node_02 = "1-oi";
	xpect_node_03 = NULL;
	xpect_node_04 = "2-file.txt";
	xpect_node_05 = NULL;
	xpect_node_06 = "3-file.txt";
	xpect_lst_size = 6;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	define_archive_token(lst);
	actual_archive_word_detection = check_words_after_archive(lst);
	actual_another_redirect_detection = check_another_redirect_after_archive(lst);
	if (actual_another_redirect_detection == true)
		organize_redirects(&lst);
	actual_node_01 = lst->lexeme;
	lst = lst->next;
	actual_node_02 = lst->lexeme;
	lst = lst->next;
	actual_node_03 = lst->lexeme;
	lst = lst->next;
	actual_node_04 = lst->lexeme;
	lst = lst->next;
	actual_node_05 = lst->lexeme;
	lst = lst->next;
	actual_node_06 = lst->lexeme;
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	mu_assert_int_eq(xpect_another_redirect_detection, actual_another_redirect_detection);
	mu_assert_string_eq(xpect_node_01, actual_node_01);
	mu_assert_string_eq(xpect_node_02, actual_node_02);
	mu_assert_string_eq(xpect_node_03, actual_node_03);
	mu_assert_string_eq(xpect_node_04, actual_node_04);
	mu_assert_string_eq(xpect_node_05, actual_node_05);
	mu_assert_string_eq(xpect_node_06, actual_node_06);
	free_token_list(&lst);
}

MU_TEST(testing_syntax_REORGANIZE_REDIRECTS_end_with_ARCHIVE_WORD)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_archive_word_detection;
	bool			xpect_another_redirect_detection;
	bool			actual_archive_word_detection;
	bool			actual_another_redirect_detection;
	char			*xpect_node_01;
	char			*xpect_node_02;
	char			*xpect_node_03;
	char			*xpect_node_04;
	char			*xpect_node_05;
	char			*xpect_node_06;
	char			*xpect_node_07;
	char			*actual_node_01;
	char			*actual_node_02;
	char			*actual_node_03;
	char			*actual_node_04;
	char			*actual_node_05;
	char			*actual_node_06;
	char			*actual_node_07;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo 1-oi > 2-file.txt > 3-file.txt 4-arg";
	xpect_archive_word_detection = true; // word after archive detection
	xpect_another_redirect_detection = true; // is there any redirect, after archive?
	xpect_node_01 = "echo";
	xpect_node_02 = "1-oi";
	xpect_node_03 = "4-arg";
	xpect_node_04 = NULL;
	xpect_node_05 = "2-file.txt";
	xpect_node_06 = NULL;
	xpect_node_07 = "3-file.txt";
	xpect_lst_size = 7;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	define_archive_token(lst);
	actual_archive_word_detection = check_words_after_archive(lst);
	actual_another_redirect_detection = check_another_redirect_after_archive(lst);
	if (actual_another_redirect_detection == true)
		organize_redirects(&lst);
	actual_node_01 = lst->lexeme;
	lst = lst->next;
	actual_node_02 = lst->lexeme;
	lst = lst->next;
	actual_node_03 = lst->lexeme;
	lst = lst->next;
	actual_node_04 = lst->lexeme;
	lst = lst->next;
	actual_node_05 = lst->lexeme;
	lst = lst->next;
	actual_node_06 = lst->lexeme;
	lst = lst->next;
	actual_node_07 = lst->lexeme;
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	mu_assert_int_eq(xpect_another_redirect_detection, actual_another_redirect_detection);
	mu_assert_string_eq(xpect_node_01, actual_node_01);
	mu_assert_string_eq(xpect_node_02, actual_node_02);
	mu_assert_string_eq(xpect_node_03, actual_node_03);
	mu_assert_string_eq(xpect_node_04, actual_node_04);
	mu_assert_string_eq(xpect_node_05, actual_node_05);
	mu_assert_string_eq(xpect_node_06, actual_node_06);
	mu_assert_string_eq(xpect_node_07, actual_node_07);
	free_token_list(&lst);
}

MU_TEST_SUITE(test11___syntax_REDIRECTS_to_ARCHIVE_DETECTION_suite)
{
	MU_RUN_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_first_node);
	MU_RUN_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_middle_node);
	MU_RUN_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_last_node);
}

MU_TEST_SUITE(test11___syntax_WORD_AFTER_ARCHIVE_detection_suite)
{
	MU_RUN_TEST(testing_syntax_WORD_AFTER_ARCHIVE_detection_false);
	MU_RUN_TEST(testing_syntax_WORD_AFTER_ARCHIVE_detection_true);
}

MU_TEST_SUITE(test11___syntax_ANOTHER_REDIRECT_FOUND_suite)
{
	MU_RUN_TEST(testing_syntax_ANOTHER_REDIRECTS_FOUND_false);
	MU_RUN_TEST(testing_syntax_ANOTHER_REDIRECTS_FOUND_true);
}

MU_TEST_SUITE(test11___syntax_REORGANIZE_REDIRECTS_suite)
{
	MU_RUN_TEST(testing_syntax_REORGANIZE_REDIRECTS_echo_oi_tudo_bem_classic);
	MU_RUN_TEST(testing_syntax_REORGANIZE_REDIRECTS_end_with_ARCHIVE);
	MU_RUN_TEST(testing_syntax_REORGANIZE_REDIRECTS_end_with_ARCHIVE_WORD);
}