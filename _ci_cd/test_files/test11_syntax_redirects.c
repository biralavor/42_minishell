/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11_syntax_redirects.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:31:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/18 17:39:59 by umeneses         ###   ########.fr       */
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
	bool			xpect_archive_detection;
	bool			actual_archive_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "> file.txt cat file.txt";
	xpect_redirect_detection = true; // redirect detection
	xpect_archive_detection = true; // archive detection
	actual_redirect_detection = -1; // initializing
	actual_archive_detection = -1; // initializing
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_redirect_detection = check_redirects(lst);
	if (actual_redirect_detection == true)
	{
		define_archive_token(lst);
		actual_archive_detection = check_words_after_archive(lst);
	}
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_redirect_detection, actual_redirect_detection);
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
	bool			xpect_archive_detection;
	bool			actual_archive_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "cat file1.txt echo > file2.txt file3.txt";
	xpect_redirect_detection = true; // redirect detection
	xpect_archive_detection = true; // archive detection
	actual_redirect_detection = -1; // initializing
	actual_archive_detection = -1; // initializing
	xpect_lst_size = 6;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_redirect_detection = check_redirects(lst);
	if (actual_redirect_detection == true)
	{
		define_archive_token(lst);
		actual_archive_detection = check_words_after_archive(lst);
	}
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_redirect_detection, actual_redirect_detection);
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
	bool			xpect_archive_detection;
	bool			actual_archive_detection;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo OLA-OLA file2.txt > file3.txt";
	xpect_redirect_detection = true; // redirect detection
	xpect_archive_detection = true; // archive detection
	actual_redirect_detection = -1; // initializing
	actual_archive_detection = -1; // initializing
	xpect_lst_size = 5;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	actual_redirect_detection = check_redirects(lst);
	if (actual_redirect_detection == true)
	{
		define_archive_token(lst);
		actual_archive_detection = check_words_after_archive(lst);
	}
	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_redirect_detection, actual_redirect_detection);
}

MU_TEST(testing_syntax_ORGANIZE_REDIRECTS_first_node)
{
	
}

MU_TEST_SUITE(test11___syntax_REDIRECTS_to_ARCHIVE_DETECTION_suite)
{
	MU_RUN_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_first_node);
	MU_RUN_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_middle_node);
	MU_RUN_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_last_node);
}

MU_TEST_SUITE(test11___syntax_ORGANIZE_REDIRECTS_suite)
{
	MU_RUN_TEST(testing_syntax_ORGANIZE_REDIRECTS_first_node);
}