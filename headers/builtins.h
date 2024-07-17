/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:57:00 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 12:38:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/**
 * @brief: Calls the respective builtin function.
*/
void	builtins_controller(t_token_list *lst);

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
void	builtins_error_cd(int destiny_len, char *destiny_path);

#endif