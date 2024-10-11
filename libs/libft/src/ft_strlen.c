/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:27:00 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/11 03:31:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Calculates the length of the string pointed to by 'str',
 * excluding the terminating null byte ('\0').
*/
size_t	ft_strlen(const char *str)
{
	int	idx;

	idx = 0;
	while (str && str[idx])
		idx++;
	return (idx);
}
