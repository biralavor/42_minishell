/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:19:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/02 10:48:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_error_msg(int destiny_len, char *destiny_path, int chdir_status)
{
	if (!is_path_a_directory(destiny_path))
	{
		write(2, "bash: cd: ", 11);
		write(2, destiny_path, destiny_len);
		write(2, ": Not a directory", 18);
		write(2, "\n", 1);
	}
	else if (chdir_status == ENOENT)
	{
		write(2, "bash: cd: ", 11);
		write(2, destiny_path, destiny_len);
		write(2, ": No such file or directory", 28);
		write(2, "\n", 1);
	}
}

bool	is_path_a_directory(char *path)
{
	struct stat file_system_status;

	if ((stat(path, &file_system_status) == 0)
		&& (S_ISDIR(file_system_status.st_mode) != 0))
		return (true);
	return (false);
}

