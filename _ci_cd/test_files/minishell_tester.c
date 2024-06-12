/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/12 15:31:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "minishell.h"
#include "minunit_utils.c"

MU_TEST(first_test)
{
	// ARRANGE


	// ACT


	// ASSERT
}

MU_TEST(second_test)
{
	// ARRANGE


	// ACT


	// ASSERT
}

MU_TEST_SUITE(first_suite)
{
	MU_RUN_TEST(first_test);
	MU_RUN_TEST(second_test);
}

int	main(void)
{
	MU_RUN_SUITE(first_suite);
	MU_REPORT();
	return (0);
}