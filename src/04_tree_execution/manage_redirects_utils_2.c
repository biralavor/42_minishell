/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirects_utils_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:10:47 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/11 03:15:18 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_pathname(char *pathname)
{
	if (!pathname)
	{
		ft_putendl_fd("Ambiguous Redirect", STDERR_FILENO);
		return (false);
	}
	return (true);
}
