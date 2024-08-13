/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:57:00 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/13 15:58:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "executor.h"

/**
 * @brief: Calls the respective builtin function.
*/
void		builtins_manager(t_token_list *lst);

/**
 * @brief: Checks if there are any builtins in the token list.
*/
bool		builtins_detector(t_token_list *lst);

/**
 * @brief: Runs the echo - imitate words - builtin command.
*/
void		builtins_runner_echo(t_token_list *lst);

/**
 * @brief: Runs the pwd - print work directory - builtin command.
*/
void		builtins_runner_pwd(t_token_list *lst);

/**
 * @brief: Runs the cd - change directory - builtin command.
*/
void		builtins_runner_cd(t_token_list *lst);

/**
 * @brief: Prints an error message when the cd command fails.
*/
void		error_cd_messenger(int destiny_len, char *destiny_path);

/**
 * @brief: Checks if the builtin command has an argument.
*/
bool		check_command_args(t_token_list *lst, char arg);

/**
 * @brief: Runs the export - set a new environment variable - builtin command.
*/
void		builtins_runner_export(t_env_entry *env_vars);

/**
 * @brief: Sorts the environment variables.
 */
t_env_entry	*builtins_env_sort_manager(t_env_entry *env_vars);

/**
 * @brief: Checks if the environment variables are sorted.
 */
bool		builtins_is_env_sorted(t_env_entry *env_vars);

/**
 * @brief: Swaps two nodes in the environment variables list.
 */
void		swap_env_nodes(t_env_entry **head, t_env_entry *a, t_env_entry *b);

/**
 * @brief: Sorts the environment variables list,
 * applying the Bubble Sort algorithm.
 */
t_env_entry	*bubble_sort_nodes(t_env_entry **head);

#endif