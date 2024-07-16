/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:57:00 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/16 15:15:32 by umeneses         ###   ########.fr       */
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
 * @brief: Runs the echo builtin function.
*/
void	builtins_runner_echo(t_token_list *lst);

#endif