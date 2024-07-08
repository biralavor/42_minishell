/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main_tester.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/08 12:21:02 by umeneses         ###   ########.fr       */
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
#include "../../src/lexer/04.create_token_list.c"
#include "../../src/lexer/05.get_state.c"
#include "../../src/lexer/06.state10_to_state30.c"
#include "../../src/lexer/07.state40_to_state60.c"
#include "../../src/lexer/08.state61_to_state90.c"
#include "../../src/lexer/09.error_manager_lexer.c"
#include "../../src/lexer/10.lexer_utils.c"
#include "../../src/parser/11.syntax_analysis.c"
#include "../../src/parser/12.state100.c"
#include "../../src/parser/13.utils_parsing_word.c"
#include "../../src/parser/14.state200.c"
#include "../../src/parser/15.state300.c"
#include "../../src/parser/16.state400.c"
#include "../../src/parser/17.error_manager_parser.c"
#include "../_tdd_utils/ft_lst_print_content.c"

#include "minunit_utils.c"
#include "test01_initial_errors.c"
#include "test02_create_token.c"
#include "test03_tokens_01_to_02.c"
#include "test04_tokens_03_to_05.c"
#include "test05_tokens_06_to_10.c"
#include "test06_tokens_cadet.c"
#include "test07_syntax_first_last_node.c"
#include "test08_syntax_lexeme.c"

int	main(void)
{
	MU_RUN_SUITE(test01___initial_errors_suite);
	MU_RUN_SUITE(test01___token_simulation_errors_suite);
	MU_RUN_SUITE(test02___create_token_suite);
	MU_RUN_SUITE(test03___01_to_02_tokens_suite);
	MU_RUN_SUITE(test04___03_to_05_tokens_suite);
	MU_RUN_SUITE(test05___06_to_10_tokens_suite);
	MU_RUN_SUITE(test06___tokens_cadet_suite);
	MU_RUN_SUITE(test07___syntax_first_node_PIPE_errors_suite);
	MU_RUN_SUITE(test07___syntax_first_node_OR_errors_suite);
	MU_RUN_SUITE(test07___syntax_first_node_AND_errors_suite);
	MU_RUN_SUITE(test07___syntax_first_node_REDIRECT_INPUT_errors_suite);
	MU_RUN_SUITE(test07___syntax_first_node_REDIRECT_OUTPUT_errors_suite);
	MU_RUN_SUITE(test07___syntax_first_node_REDIRECT_OUTPUT_APPEND_errors_suite);
	MU_RUN_SUITE(test07___syntax_first_node_CLOSE_PARENTHESIS_errors_suite);
	// MU_RUN_SUITE(testing_syntax_last_node_errors_suite);
	// MU_RUN_SUITE(testing_syntax_few_nodes_pipe_errors_suite);
	// MU_RUN_SUITE(testing_syntax_few_nodes_redirect_errors_suite);
	// MU_RUN_SUITE(testing_syntax_few_nodes_mix_errors_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
