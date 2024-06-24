/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main_tester.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/24 16:41:07 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test_initial_errors.c"
#include "minunit_utils.c"

MU_TEST_SUITE(check_initial_errors_suite);
MU_TEST_SUITE(token_simulation_errors_suite);

int	main(void)
{
	MU_RUN_SUITE(check_initial_errors_suite);
	MU_RUN_SUITE(token_simulation_errors_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
