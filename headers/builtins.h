/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:57:00 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/09 17:09:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/**
 * @brief: Calls the respective builtin function.
*/
void	builtins_manager(t_token_list *lst);

/**
 * @brief: Checks if there are any builtins in the token list.
*/
bool	builtins_detector(t_token_list *lst);

/**
 * @brief: Runs the echo - imitate words - builtin command.
*/
void	builtins_runner_echo(t_token_list *lst);

/**
 * @brief: Runs the pwd - print work directory - builtin command.
*/
void	builtins_runner_pwd(t_token_list *lst);

/**
 * @brief: Runs the cd - change directory - builtin command.
*/
void	builtins_runner_cd(t_token_list *lst);

/**
 * @brief: Prints an error message when the cd command fails.
*/
void	error_cd_messenger(int destiny_len, char *destiny_path);

/**
 * @brief: Checks if the builtin command has an argument.
*/
bool	check_command_args(t_token_list *lst, char arg);

/**
 * @brief: Runs the export - set a new environment variable - builtin command.
*/
void	builtins_runner_export(t_token_list *lst);

/**
 * @brief: Gets the name of the environment variable to be exported.
*/
char	*export_getter_var_name(t_token_list *lst);

/**
 * @brief: Gets the value of the environment variable to be exported.
*/
char	*export_getter_var_value(t_token_list *lst);

#endif