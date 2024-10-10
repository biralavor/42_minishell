/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:51:49 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/09 21:40:05 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_next_quote(char *str, int idx)
{
	while (str[++idx] != '\0')
	{
		if (str[idx] == '"')
			return (idx);
	}
	return (idx);
}
