/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:17:27 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/01 22:18:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGER_H
# define ERROR_MANAGER_H

enum e_error
{
	LEXER_ERROR,
	LIST_NOT_CREATED,
	UNEXPECTED_TOKEN,
	SYNTAX_ERROR,
	COMMAND_NOT_FOUND,
	PARENTHESIS_ERROR
};

#endif
