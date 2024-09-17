/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_question.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:32:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/03 16:09:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expansion_question_mark(char *lexeme)
{
	char	*last_exit_value;
	int		exit_status;

	exit_status = exit_status_holder(-1, false);
	last_exit_value = ft_itoa(exit_status);
	free(lexeme);
	lexeme = ft_strdup(last_exit_value);
	free(last_exit_value);
	return (lexeme);
}
