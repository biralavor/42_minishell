/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11_syntax_redirects.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:31:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/25 13:39:02 by umeneses         ###   ########.fr       */
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
	bool			xpect_archive_word_detection;
	bool			xpect_another_redirect_detection;
	bool			actual_archive_word_detection;
	bool			actual_another_redirect_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo 1-oi > 2-file.txt 3-file.txt";
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

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
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
	bool			xpect_archive_word_detection;
	bool			xpect_another_redirect_detection;
	bool			actual_archive_word_detection;
	bool			actual_another_redirect_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo 1-oi > 2-file.txt > 3-file.txt";
	xpect_archive_word_detection = true; // word after archive detection
	xpect_another_redirect_detection = true; // is there any redirect, after archive?
	xpect_lst_size = 6;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	define_archive_token(lst);
	actual_archive_word_detection = check_words_after_archive(lst);
	actual_another_redirect_detection = check_another_redirect_after_archive(lst);

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	mu_assert_int_eq(xpect_another_redirect_detection, actual_another_redirect_detection);
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