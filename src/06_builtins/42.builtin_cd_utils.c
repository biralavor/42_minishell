/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42.builtin_cd_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:19:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 20:33:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_error_msg(int destiny_len, char *destiny_path, int chdir_status)
{
	if (chdir_status == -1)
	{
		write(STDERR_FILENO, "bash: cd: ", 10);
		write(STDERR_FILENO, destiny_path, destiny_len);
		write(STDERR_FILENO, ": No such file or directory\n", 28);
	}
	else if (!is_path_a_directory(destiny_path))
	{
		write(STDERR_FILENO, "bash: cd: ", 10);
		write(STDERR_FILENO, destiny_path, destiny_len);
		write(STDERR_FILENO, ": Not a directory\n", 18);
	}
	exit_status_holder(EXIT_FAILURE, true);
}

bool	is_path_a_directory(char *path)
{
	struct stat	file_system_status;

	if ((stat(path, &file_system_status) == 0)
		&& S_ISDIR(file_system_status.st_mode))
		return (true);
	return (false);
}
