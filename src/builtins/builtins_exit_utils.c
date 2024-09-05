/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/05 10:59:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_valid_code_manager(char *lexeme)
{
	int		exit_code;
	bool	llong_min_status;

	exit_code = 0;
	exit_code = long_long_overflow_validation(lexeme);
	if (exit_code != 2)
	{
		exit_code = ft_atoi(lexeme);
		if (exit_code == 1 && ft_strlen(lexeme) == MIN_LEN_CODE)
			llong_min_status = long_long_min_detected(true, false);
		exit_code = exit_code % 256;
	}
	return (exit_code);
}

bool	long_long_min_detected(bool update, bool status)
{
	static bool	llong_min;

	if (status)
		return (llong_min);
	else if (update)
		llong_min = update;
	return (llong_min);
}

int	long_long_overflow_validation(const char *lexeme)
{
	int		code;
	int		len;
	char	*idx;

	code = 0;
	idx = (char *)lexeme;
	while (*idx == '-' || *idx == '+')
		idx++;
	while (*idx == '0')
		idx++;
	len = ft_strlen(idx);
	if (len > MAX_LEN_CODE || (len == MAX_LEN_CODE
			&& ft_strncmp(idx, LONG_MAX_CODE, len) > 0)
		|| (len == MAX_LEN_CODE && ft_strncmp(idx, LONG_MIN_CODE, len) < 0))
	{
		write(2, "bash exit: ", 11);
		write(2, lexeme, ft_strlen(lexeme));
		write(2, ": numeric argument required\n", 28);
		code = 2;
	}
	return (code);
}

bool	exit_code_not_numeric(const char *lexeme)
{
	int	idx;

	idx = 0;
	while (lexeme[idx])
	{
		if (ft_isalpha(lexeme[idx]))
			return (true);
		idx++;
	}
	return (false);
}
