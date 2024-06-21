/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_userinput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/21 13:33:05 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_userinput(char *str)
{
	if (check_initial_errors(str))
		exit (EXIT_FAILURE);
	create_token_list(str);
}
