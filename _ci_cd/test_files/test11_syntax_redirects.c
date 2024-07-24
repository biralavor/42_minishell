/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11_syntax_redirects.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:31:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/24 17:02:57 by umeneses         ###   ########.fr       */
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

MU_TEST(testing_syntax_ORGANIZE_REDIRECTS_no_WORD_after_archive)
{
	// ARRANGE
	char			*userinput;
	int				idx;
	int				xpect_lst_size;
	int				actual_lst_size;
	bool			xpect_archive_word_detection;
	bool			actual_archive_word_detection;
	char			*xpect_node_01_lexeme;
	char			*xpect_node_01_type;
	char			*xpect_node_02_lexeme;
	char			*xpect_node_02_type;
	char			*xpect_node_03_lexeme;
	char			*xpect_node_03_type;
	char			*xpect_node_04_lexeme;
	char			*xpect_node_04_type;
	char			*actual_node_01_lexeme;
	char			*actual_node_01_type;
	char			*actual_node_02_lexeme;
	char			*actual_node_02_type;
	char			*actual_node_03_lexeme;
	char			*actual_node_03_type;
	char			*actual_node_04_lexeme;
	char			*actual_node_04_type;
	int				fd;
	t_token_list	*lst;

	//ACT
	fd = 0;
	open_redirect_stderr_to_dev_null(fd);
	userinput = "echo 1-oi > 2-file.txt";
	xpect_archive_word_detection = false; // word after archive detection
	xpect_node_01_type = get_token_string(WORD);
	xpect_node_01_lexeme = "echo";
	xpect_node_02_type = get_token_string(WORD);
	xpect_node_02_lexeme = "1-oi";
	xpect_node_03_type = get_token_string(REDIR_OUT);
	xpect_node_03_lexeme = NULL;
	xpect_node_04_type = get_token_string(ARCHIVE);
	xpect_node_04_lexeme = "2-file.txt";
	xpect_lst_size = 4;
	idx = 0;
	lst = NULL;
	get_state(idx, userinput, &lst);
	actual_lst_size = ft_lst_size(lst);
	define_archive_token(lst);
	actual_archive_word_detection = check_words_after_archive(lst);
	organize_redirects(&lst);
	
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

	close_redirect_stderr_to_dev_null(fd);
	// ASSERT
	mu_assert_int_eq(xpect_lst_size, actual_lst_size);
	mu_assert_int_eq(xpect_archive_word_detection, actual_archive_word_detection);
	mu_assert_string_eq(xpect_node_01_lexeme, actual_node_01_lexeme);
	mu_assert_string_eq(xpect_node_01_type, actual_node_01_type);
	mu_assert_string_eq(xpect_node_02_lexeme, actual_node_02_lexeme);
	mu_assert_string_eq(xpect_node_02_type, actual_node_02_type);
	mu_assert_string_eq(xpect_node_03_lexeme, actual_node_03_lexeme);
	mu_assert_string_eq(xpect_node_03_type, actual_node_03_type);
	mu_assert_string_eq(xpect_node_04_lexeme, actual_node_04_lexeme);
	mu_assert_string_eq(xpect_node_04_type, actual_node_04_type);
	free_token_list(&lst);
}



MU_TEST_SUITE(test11___syntax_REDIRECTS_to_ARCHIVE_DETECTION_suite)
{
	MU_RUN_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_first_node);
	MU_RUN_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_middle_node);
	MU_RUN_TEST(testing_syntax_REDIRECTS_to_ARCHIVE_DETECTION_last_node);
}

MU_TEST_SUITE(test11___syntax_ORGANIZE_REDIRECTS_suite)
{
	MU_RUN_TEST(testing_syntax_ORGANIZE_REDIRECTS_no_WORD_after_archive);
	MU_RUN_TEST(testing_syntax_ORGANIZE_REDIRECTS_with_WORD_after_archive);
}