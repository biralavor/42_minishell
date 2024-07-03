/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main_tester.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/03 12:12:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../src/02.check_userinput.c"
#include "../../src/lexer/03.check_initial_errors.c"
#include "../../src/lexer/04.create_token_list.c"
#include "../../src/lexer/05.get_state.c"
#include "../../src/lexer/06.state1_to_state5.c"
#include "../../src/lexer/07.state6_to_state10.c"
#include "../../src/lexer/08.state11_to_state15.c"
#include "../../src/lexer/09.error_manager_lexer.c"
#include "../../src/lexer/10.lexer_utils.c"
#include "../../src/parser/check_syntax_errors.c"
#include "../../src/parser/error_manager_parser.c"
#include "../../src/parser/parser_utils.c"
#include "../_tdd_utils/ft_lst_print_content.c"

#include "minunit_utils.c"
#include "test01_initial_errors.c"
#include "test02_create_token.c"
#include "test03_tokens_01_to_02.c"
#include "test03_tokens_03_to_05.c"
#include "test03_tokens_06_to_10.c"
#include "test03_tokens_cadet.c"
#include "test04_syntax_first_last_node.c"
#include "test04_syntax_lexeme.c"

int	main(void)
{
	MU_RUN_SUITE(check_initial_errors_suite);
	MU_RUN_SUITE(token_simulation_errors_suite);
	MU_RUN_SUITE(testing_create_token_suite);
	MU_RUN_SUITE(testing_01_to_02_tokens_suite);
	MU_RUN_SUITE(testing_03_to_05_tokens_suite);
	MU_RUN_SUITE(testing_06_to_10_tokens_suite);
	MU_RUN_SUITE(testing_tokens_cadet_suite);
	MU_RUN_SUITE(testing_syntax_first_last_node_errors_suite);
	// MU_RUN_SUITE(testing_syntax_lemexe_errors_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
