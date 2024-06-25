/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main_tester.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/24 22:50:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../src/check_initial_errors.c"
#include "../../src/get_state.c"
#include "../../src/state1_to_state5.c"
#include "../../src/state6_to_state10.c"
#include "../../src/state11_to_state15.c"
#include "../../src/create_token_list.c"
#include "../../src/lexer_utils.c"

#include "minunit_utils.c"
#include "test_initial_errors.c"
#include "test_tokens_01_to_02.c"
#include "test_tokens_03_to_05.c"
#include "test_tokens_06_to_10.c"

int	main(void)
{
	MU_RUN_SUITE(check_initial_errors_suite);
	MU_RUN_SUITE(token_simulation_errors_suite);
	MU_RUN_SUITE(check_01_to_02_tokens_tests);
	MU_RUN_SUITE(check_03_to_05_tokens_tests);
	MU_RUN_SUITE(check_06_to_10_tokens_tests);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
