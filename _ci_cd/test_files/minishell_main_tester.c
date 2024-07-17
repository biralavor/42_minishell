/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main_tester.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 19:39:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "../../src/02.check_userinput.c"
#include "../../src/lexer/03.check_initial_errors.c"
#include "../../src/lexer/04.token_list_functions.c"
#include "../../src/lexer/05.get_state.c"
#include "../../src/lexer/06.state20_to_state30.c"
#include "../../src/lexer/07.state40_to_state60.c"
#include "../../src/lexer/08.state61_to_state90.c"
#include "../../src/lexer/09.error_manager_lexer.c"
#include "../../src/lexer/10.lexer_utils.c"
#include "../../src/parser/11.syntax_analysis.c"
#include "../../src/parser/12.state100.c"
#include "../../src/parser/13.utils_parsing_word.c"
#include "../../src/parser/14.state200.c"
#include "../../src/parser/15.state300.c"
#include "../../src/parser/16.redir_manager.c"
#include "../../src/parser/17.redir_utils.c"
#include "../../src/parser/18.error_manager_parser.c"
#include "../_tdd_utils/ft_lst_printer.c"

#include "minunit_utils.c"
#include "test01_initial_errors.c"
#include "test02_create_token.c"
#include "test03_tokens_01_to_02.c"
#include "test04_tokens_03_to_05.c"
#include "test05_tokens_06_to_10.c"
#include "test06_tokens_cadet.c"
#include "test07_syntax_state100.c"
#include "test08_syntax_state200.c"
#include "test09_syntax_state300.c"
#include "test10_syntax_state400.c"


int	main(void)
{
	MU_RUN_SUITE(test01___initial_errors_suite);
	MU_RUN_SUITE(test01___token_simulation_errors_suite);
	MU_RUN_SUITE(test01___lexeme_MIXED_quotes_errors_suite);

	MU_RUN_SUITE(test02___create_token_suite);
	
	MU_RUN_SUITE(test03___01_to_02_tokens_suite);

	MU_RUN_SUITE(test04___03_to_05_tokens_suite);

	MU_RUN_SUITE(test05___06_to_10_tokens_suite);

	MU_RUN_SUITE(test06___tokens_cadet_suite);
	
	MU_RUN_SUITE(test07___syntax_state100_single_quote_errors_first_node_suite);
	MU_RUN_SUITE(test07___syntax_state100_single_quote_errors_last_node_suite);
	MU_RUN_SUITE(test07___syntax_state100_double_quote_errors_first_node_suite);
	MU_RUN_SUITE(test07___syntax_state100_double_quote_errors_last_node_suite);
	
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
	
	MU_RUN_SUITE(test10___syntax_state400_CLOSE_PARENTHESIS_errors_first_node_suite);
	MU_RUN_SUITE(test10___syntax_state400_CLOSE_PARENTHESIS_errors_last_node_suite);
	
	MU_RUN_SUITE(test10___syntax_state400_OPEN_PARENTHESIS_errors_first_node_suite);
	MU_RUN_SUITE(test10___syntax_state400_OPEN_PARENTHESIS_errors_last_node_suite);
	
	MU_RUN_SUITE(test10___syntax_state400_MIXED_PARENTHESIS_odd_counter_errors_suite);
	
	// MU_RUN_SUITE(testing_syntax_last_node_errors_suite);
	// MU_RUN_SUITE(testing_syntax_few_nodes_pipe_errors_suite);
	// MU_RUN_SUITE(testing_syntax_few_nodes_redirect_errors_suite);
	// MU_RUN_SUITE(testing_syntax_few_nodes_mix_errors_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
