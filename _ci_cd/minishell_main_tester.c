/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main_tester.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/04 16:53:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "../../src/02.signals.c"
#include "../../src/03.env_init.c"
#include "../../src/04.env_init_utils.c"
#include "../../src/05.loop_routine.c"
#include "../../src/01_lexer/06.check_initial_errors.c"
#include "../../src/01_lexer/07.token_list_functions.c"
#include "../../src/01_lexer/08.get_state.c"
#include "../../src/01_lexer/09.state10_to_state30.c"
#include "../../src/01_lexer/10.state40_to_state60.c"
#include "../../src/01_lexer/11.state61_to_state90.c"
#include "../../src/01_lexer/12.error_manager_lexer.c"
#include "../../src/01_lexer/13.lexer_utils.c"
#include "../../src/02_parser/14.syntax_analysis.c"
#include "../../src/02_parser/15.state100.c"
#include "../../src/02_parser/16.state200_to_state300.c"
#include "../../src/02_parser/17.check_redirects.c"
#include "../../src/02_parser/18.check_redirects_utils.c"
#include "../../src/02_parser/19.error_manager_parser.c"
#include "../../src/02_parser/20.manage_heredoc.c"
#include "../../src/03_binary_tree/21.building_tree.c"
#include "../../src/03_binary_tree/22.building_tree_utils.c"
#include "../../src/04_tree_execution/23.tree_execution.c"
#include "../../src/04_tree_execution/24.tree_execution_utils.c"
#include "../../src/04_tree_execution/25.manage_or_and.c"
#include "../../src/04_tree_execution/26.manage_pipe.c"
#include "../../src/04_tree_execution/27.manage_redirects.c"
#include "../../src/04_tree_execution/28.manage_subshell.c"
#include "../../src/04_tree_execution/29.manage_single_cmd.c"
#include "../../src/04_tree_execution/manage_pipe_utils.c"
#include "../../src/04_tree_execution/manage_redirects_utils.c"
#include "../../src/05_expansions/30.expansion_manager.c"
#include "../../src/05_expansions/31.expansion_detectors.c"
#include "../../src/05_expansions/32.expansion_quotes.c"
#include "../../src/05_expansions/33.expansion_tilde.c"
#include "../../src/05_expansions/34.expansion_env_var.c"
#include "../../src/05_expansions/35.expansion_env_var_utils.c"
#include "../../src/05_expansions/36.expansion_question.c"
#include "../../src/05_expansions/expansion_env_var_utils_2.c"
#include "../../src/06_builtins/37.builtin_detectors.c"
#include "../../src/06_builtins/38.builtin_manager.c"
#include "../../src/06_builtins/39.builtin_utils.c"
#include "../../src/06_builtins/40.builtin_echo.c"
#include "../../src/06_builtins/41.builtin_cd.c"
#include "../../src/06_builtins/42.builtin_cd_utils.c"
#include "../../src/06_builtins/43.builtin_pwd.c"
#include "../../src/06_builtins/44.builtin_export.c"
#include "../../src/06_builtins/45.builtin_export_utils.c"
#include "../../src/06_builtins/46.builtin_unset.c"
#include "../../src/06_builtins/47.builtin_env.c"
#include "../../src/06_builtins/48.builtin_exit.c"
#include "../../src/06_builtins/49.builtin_exit_utils.c"
#include "../../src/07_command_execution/50.command_runner.c"
#include "../../src/07_command_execution/51.command_runner_utils.c"
#include "../_tdd_utils/ft_array_printer.c"
#include "../_tdd_utils/ft_env_printer.c"
#include "../_tdd_utils/ft_lst_printer.c"
#include "../_tdd_utils/ft_tree_printer.c"
#include "../_tdd_utils/get_token_string.c"

#include "minunit_utils.c"
#include "./test_files/test01_initial_errors.c"
#include "./test_files/test02_create_token.c"
#include "./test_files/test03_tokens_01_to_02.c"
#include "./test_files/test04_tokens_03_to_05.c"
#include "./test_files/test05_tokens_06_to_10.c"
#include "./test_files/test06_tokens_cadet.c"
#include "./test_files/test07_syntax_state100.c"
#include "./test_files/test08_syntax_state200.c"
#include "./test_files/test09_syntax_state300.c"
#include "./test_files/test10_syntax_state400.c"
// #include "./test_files/test11_syntax_redirects.c"

int	main(void)
{
	MU_RUN_SUITE(test01___initial_errors_suite);
	MU_RUN_SUITE(test01___token_simulation_errors_suite);
	MU_RUN_SUITE(test01___lexeme_MIXED_quotes_errors_suite);
	
	MU_RUN_SUITE(test01___lexeme_parenthesis_validation_suite);
	MU_RUN_SUITE(test01___lexeme_parenthesis_odd_counter_suite);

	MU_RUN_SUITE(test01___lexeme_single_quote_errors_first_node_suite);
	MU_RUN_SUITE(test01___lexeme_single_quote_errors_last_node_suite);
	MU_RUN_SUITE(test01___lexeme_double_quote_errors_first_node_suite);
	MU_RUN_SUITE(test01___lexeme_double_quote_errors_last_node_suite);
	
	MU_RUN_SUITE(testing_lexeme_crazy_parentehsis_counter);
	
	MU_RUN_SUITE(test02___create_token_suite);
	
	MU_RUN_SUITE(test03___01_to_02_tokens_suite);

	MU_RUN_SUITE(test04___03_to_05_tokens_suite);

	MU_RUN_SUITE(test05___06_to_10_tokens_suite);

	MU_RUN_SUITE(test06___tokens_cadet_suite);

	MU_RUN_SUITE(test07___syntax_state100_WORDS_errors_first_node_suite);
	
	MU_RUN_SUITE(test08___syntax_state200_PIPE_errors_first_node_suite);
	MU_RUN_SUITE(test08___syntax_state200_PIPE_errors_last_node_suite);
	
	MU_RUN_SUITE(test08___syntax_state200_OR_errors_first_node_suite);
	MU_RUN_SUITE(test08___syntax_state200_OR_errors_last_node_suite);

	MU_RUN_SUITE(test08___syntax_state200_AND_errors_first_node_suite);
	MU_RUN_SUITE(test08___syntax_state200_AND_errors_last_node_suite);
	
	MU_RUN_SUITE(test08___syntax_state200_cadet_PIPE_errors_suite);
	MU_RUN_SUITE(test08___syntax_state200_cadet_MIXED_PIPE_errors_suite);
	
	MU_RUN_SUITE(test09___syntax_state300_REDIRECT_INPUT_errors_first_node_suite);
	MU_RUN_SUITE(test09___syntax_state300_REDIRECT_INPUT_errors_last_node_suite);
	
	MU_RUN_SUITE(test09___syntax_state300_REDIRECT_OUTPUT_errors_first_node_suite);
	MU_RUN_SUITE(test09___syntax_state300_REDIRECT_OUTPUT_errors_last_node_suite);

	MU_RUN_SUITE(test09___syntax_state300_REDIRECT_OUTPUT_APPEND_errors_first_node_suite);
	MU_RUN_SUITE(test09___syntax_state300_REDIRECT_OUTPUT_APPEND_errors_last_node_suite);
	
	MU_RUN_SUITE(test09___syntax_state300_REDIRECT_HEREDOC_errors_first_node_suite);
	MU_RUN_SUITE(test09___syntax_state300_REDIRECT_HEREDOC_errors_last_node_suite);
	
	MU_RUN_SUITE(test09___syntax_state300_cadet_MIXED_REDIRECT_errors_suite);
	
	MU_RUN_SUITE(test10___syntax_state400_SUBSHELL_suite);
	
	// MU_RUN_SUITE(test11___syntax_REDIRECTS_to_ARCHIVE_DETECTION_suite);
	// MU_RUN_SUITE(test11___syntax_WORD_AFTER_ARCHIVE_detection_suite);
	// MU_RUN_SUITE(test11___syntax_ANOTHER_REDIRECT_FOUND_suite);

	// MU_RUN_SUITE(test11___syntax_REORGANIZE_REDIRECTS_suite);
	
	MU_REPORT();
	return (MU_EXIT_CODE);
}
